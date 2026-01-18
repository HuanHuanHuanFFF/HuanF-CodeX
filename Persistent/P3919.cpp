//
// Created by 幻 on 2026/1/18.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

namespace Persistent {
    using std::vector;

    // 1-idx
    template<typename T>
    struct PersistentArray {
    private:
        struct Node {
            T val;
            int left, right;

            Node(T val = T(), int left = 0, int right = 0)
                : val(val), left(left), right(right) {
            }
        };

        vector<int> roots_idx;
        vector<Node> tree;

        void build(vector<T> &vec, int pos) {
            if (pos >= vec.size()) return;
            tree[pos].val = vec[pos];
            tree[pos].left = pos << 1;
            tree[pos].right = pos << 1 | 1;
            build(vec, pos << 1);
            build(vec, pos << 1 | 1);
        }

        int copy(int idx) {
            tree.emplace_back(tree[idx].val, tree[idx].left, tree[idx].right);
            return tree.size() - 1;
        }

    public:
        PersistentArray(int max_size) {
            roots_idx.reserve(max_size);
        }

        void build(vector<T> &vec) {
            roots_idx.emplace_back(1);
            tree.resize(vec.size() + 1);
            build(vec, 1);
        }

        void update(int ver, int pos, T val) {
            int idx = copy(roots_idx[ver]);
            roots_idx.emplace_back(idx);
            int path = 0, go = 0;
            while (pos > 1) {
                if (pos & 1) path |= 1;
                path <<= 1;
                pos >>= 1;
                ++go;
            }
            while (go--) {
                path >>= 1;
                if (path & 1) {
                    tree[idx].right = copy(tree[idx].right);
                    idx = tree[idx].right;
                } else {
                    tree[idx].left = copy(tree[idx].left);
                    idx = tree[idx].left;
                }
            }
            tree[idx].val = val;
        }

        T query(int ver, int pos) {
            int idx = roots_idx[ver];
            int path = 0, go = 0;
            while (pos > 1) {
                if (pos & 1) path |= 1;
                path <<= 1;
                pos >>= 1;
                ++go;
            }
            while (go--) {
                path >>= 1;
                if (path & 1) {
                    tree[idx].right = tree[idx].right;
                    idx = tree[idx].right;
                } else {
                    tree[idx].left = tree[idx].left;
                    idx = tree[idx].left;
                }
            }
            return tree[idx].val;
        }

        void cv(int ver) {
            roots_idx.emplace_back(roots_idx[ver]);
        }
    };
}

constexpr bool more = false;

// P3919 【模板】可持久化线段树 1（可持久化数组）
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Persistent::PersistentArray<int> p(2e5);
    p.build(a);
    for (int i = 0, v, opt, pos, c; i < m; ++i) {
        cin >> v >> opt >> pos;
        if (opt == 1) {
            cin >> c;
            p.update(v, pos, c);
        } else {
            p.cv(v);
            int ans = p.query(v, pos);
            cout << ans << "\n";
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/10.
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
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = false;

namespace seg {
    using std::vector;

    template<typename T, auto merge, auto E>
    struct SegmentTree {
        int n;
        vector<T> t;
        static const T e = E();

        // 自定义功能1-idx线段树
        SegmentTree(int n): n(n) { t.assign(4 * n + 5, e); }

        // 构建：输入数组 a[1..n]
        void build(const vector<T> &a) { build(1, 1, n, a); }

        // 单点更新：将位置 pos 的值设为 v
        void update(int pos, const T &v) { update(1, 1, n, pos, v); }

        // 区间查询：[L, R]
        T query(int l, int r) { return query(1, 1, n, l, r); }

    private:
        void build(int p, int l, int r, const vector<T> &a) {
            if (l == r) {
                t[p] = a[l];
                return;
            }
            int m = (l + r) >> 1;
            build(p << 1, l, m, a);
            build(p << 1 | 1, m + 1, r, a);
            t[p] = merge(t[p << 1], t[p << 1 | 1]);
        }

        void update(int p, int l, int r, int pos, const T &v) {
            if (l == r) {
                t[p] = v;
                return;
            }
            int m = (l + r) >> 1;
            if (pos <= m) update(p << 1, l, m, pos, v);
            else update(p << 1 | 1, m + 1, r, pos, v);
            t[p] = merge(t[p << 1], t[p << 1 | 1]);
        }

        T query(int p, int l, int r, int L, int R) {
            if (r < L || R < l) return e;
            if (L <= l && r <= R) return t[p];
            int m = (l + r) >> 1;
            T left = query(p << 1, l, m, L, R);
            T right = query(p << 1 | 1, m + 1, r, L, R);
            return merge(left, right);
        }
    };
}

// P1886 滑动窗口 /【模板】单调队列
// https://www.luogu.com.cn/problem/P1886
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    auto max = [](int &x, int &y) { return std::max(x, y); };
    auto min = [](int &x, int &y) { return std::min(x, y); };
    seg::SegmentTree<int, max, [] { return -INF; }> seg_max(n);
    seg::SegmentTree<int, min, [] { return INF; }> seg_min(n);
    seg_max.build(a);
    seg_min.build(a);
    for (int i = k; i <= n; ++i) {
        cout << seg_min.query(i - k + 1, i) << " ";
    }
    cout << "\n";
    for (int i = k; i <= n; ++i) {
        cout << seg_max.query(i - k + 1, i) << " ";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

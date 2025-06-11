//
// Created by 幻 on 2025/6/7.
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


struct DSU {
    std::vector<int> parent, rank, sz;

    DSU(int n)
        : parent(n + 1), rank(n + 1, 0), sz(n + 1, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) std::swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

// AtCoder Beginner Contest 409 
/* F - Connecting Points
 * link: https://atcoder.jp/contests/abc409/tasks/abc409_f
 * 标签: 并查集(DSU), 优先队列, 贪心
 * 思路:
 * 1. 将所有可能的点对（u,v）的曼哈顿距离 d(u,v) 入小顶堆 heap。
 * 2. 用 DSU 管理连通分量：
 *    - 对类型 1 查询，插入新顶点 x，并将 (x,1…x-1) 的所有距离边加入 heap。
 *    - 对类型 2 查询，弹出 heap 中最小距离边 (u,v)，跳过已连通的，找到第一个未连通的距离 k；
 *      再把 heap 中所有距离 = k 的未连通边合并到 DSU，输出 k；若 heap 耗尽则输出 -1。
 *    - 对类型 3 查询，直接用 DSU 判断 u 和 v 是否连通。
 */
void HuanF() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + q);
    vector<PII> ps;
    ps.reserve(n + q + 1);
    ps.emplace_back(0, 0);
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        ps.emplace_back(x, y);
    }

    auto dis = [&](int x, int y) { return abs(ps[x].first - ps[y].first) + abs(ps[x].second - ps[y].second); };

    std::priority_queue<std::tuple<int, int, int>, vector<std::tuple<int, int, int> >, std::greater<> > heap;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            heap.emplace(dis(i, j), i, j);
        }
    }

    for (int i = 0, opt, a, b; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            cin >> a >> b;
            int x = ps.size();
            ps.emplace_back(a, b);
            for (int y = 1; y < ps.size() - 1; ++y) {
                heap.emplace(dis(x, y), x, y);
            }
        } else if (opt == 2) {
            int min_d = -1;;
            while (heap.size()) {
                auto [d,x,y] = heap.top();
                if (dsu.connected(x, y)) {
                    heap.pop();
                    continue;
                }
                min_d = d;
                break;
            }
            if (min_d == -1) cout << -1 << "\n";
            else {
                while (heap.size()) {
                    auto [d,x,y] = heap.top();
                    if (d != min_d) break;
                    heap.pop();
                    if (dsu.connected(x, y)) continue;
                    dsu.merge(x, y);
                }
                cout << min_d << "\n";
            }
        } else {
            cin >> a >> b;
            cout << (dsu.connected(a, b) ? "Yes" : "No") << "\n";
        }
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

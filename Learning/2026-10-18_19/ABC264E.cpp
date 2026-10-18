//
// Created by 幻 on 2026/10/18.
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

constexpr bool more = false;

/* ABC264-E - Blackout 2
 * link: https://atcoder.jp/contests/abc264/tasks/abc264_e
 * 标签: 离线, 逆序处理, 并查集
 * 思路: 先删除所有查询边, 逆序加回, 将删边问题转为并查集的合并问题。
 * 所有发电所连到超级节点, 其连通块大小减去 m+1 即为供电城市数。
 * 每次加边前记录答案, 最后逆序输出, 对应正序每次断线后的状态。
 * 时间复杂度: O(ElogE + (N+M+E+Q)alpha(N+M)), 空间复杂度: O(N+M+E+Q)
 */
void HuanF() {
    int n, m, e, q;
    cin >> n >> m >> e;
    vector<PII> edges;
    for (int i = 0, u, v; i < e; ++i) {
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    cin >> q;
    vector<int> idx(q);
    for (auto &x: idx) {
        cin >> x;
        --x;
    }
    std::ranges::reverse(idx);

    std::set<PII> st(edges.begin(), edges.end());
    for (int i = 0; i < q; ++i)
        st.erase(edges[idx[i]]);
    DSU dsu(n + m + 1);
    for (int i = n + 1; i <= n + m; ++i)
        dsu.merge(n + m + 1, i);
    for (auto [x,y]: st)
        dsu.merge(x, y);

    vector<int> ans;
    for (int i = 0; i < q; ++i) {
        ans.emplace_back(dsu.size(n + m + 1) - m - 1);
        auto [x,y] = edges[idx[i]];
        dsu.merge(x, y);
    }
    for (auto &x: std::views::reverse(ans))
        cout << x << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

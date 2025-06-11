//
// Created by 幻 on 2025/6/11.
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
constexpr ll INF = 1e13 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = true;

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

// Codeforces Round 1029 (Div. 3)
/*
 * G. Omg Graph —— 并查集解法（路径最小边 + 当前并入边作为最大边）
 * 算法流程：
 * 1. 将所有边按权升序排序。
 * 2. 并查集中，根节点维护 mn[root] = 连通块里出现过的最小边权。
 * 3. 遍历边 (u,v,w)：
 *    ▸ 把 w 与两端所在块的 mn 取最小，写回两块根。
 *    ▸ merge 两块；新根继承两块的最小值。
 *    ▸ 若 1 与 n 已连通，用 cost = mn[root] + w 刷全局最小答案。
 * 4. 遍历完全部边后输出答案。
 *    （不能在第一次连通时就退出，因为后面的更大 w 可能配合更小 mn 给出更优结果。）
 * 复杂度：排序 O(m log m)；并查集近 O(m α(n))。
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<std::array<ll, 3> > edges(m);
    for (auto &[w,x,y]: edges) {
        cin >> x >> y >> w;
    }
    std::ranges::sort(edges);
    ll ans = INF;
    vector<ll> min(n + 1, INF);
    for (auto &[w,x,y]: edges) {
        int xp = dsu.find(x), yp = dsu.find(y);
        ll m = std::min({min[xp], min[yp], w});
        dsu.merge(xp, yp);
        int r = dsu.find(xp);
        min[r] = m;
        if (dsu.connected(1, n)) {
            ans = std::min(ans, min[dsu.find(1)] + w);
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

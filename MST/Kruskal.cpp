#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
    int x, y;
    ll w;

    bool operator <(const edge &o) const {
        return w < o.w;
    }
};

/**
 * @param edges 边的数组
 * @param n 点的个数
 * @return 最小生成树的代价,如果不满足题目条件则返回LONG_MAX
 */
ll Kruskal(vector<edge> &edges, int n) {
    ll ans = 0, cnt = 0;
    sort(edges.begin(), edges.end());
    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    auto find = [&](auto &self, int x) -> int {
        if (parent[x] == x) return x;
        return parent[x] = self(self, parent[x]);
    };

    auto connected = [&](int x, int y) {
        return find(find, x) == find(find, y);
    };

    auto merge = [&](int x, int y) {
        int xp = find(find, x), yp = find(find, y);
        parent[yp] = xp;
    };

    for (auto [x,y,w]: edges) {
        if (connected(x, y)) continue;
        merge(x, y);
        ans += w;
    }
    for (int i = 1; i < n; ++i) {
        if (parent[i] == i) ++cnt;
        if (cnt == 2) return LONG_MAX;
    }
    return ans;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PIII = pair<pair<int, int>, int>;

struct edge {
    int x, y;
    double w;

    bool operator <(const edge &o) const {
        return w < o.w;
    }
};

/**
 * @param edges 边的数组
 * @param n 点的个数
 * @return 最小生成树的代价,如果不满足题目条件则返回LONG_MAX
 */
double Kruskal(vector<edge> &edges, int n) {
    double ans = 0, cnt = 0;
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

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 * https://www.luogu.com.cn/problem/P12158
 * 先用O(N^2)预处理边,2.5e7,再用O(N^2*log(N^2))跑Kruskal,3秒完全够用
*/
signed main() {
    IOS();
    int n;
    cin >> n;
    vector<PIII> g;
    vector<edge> edges;
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        g.push_back({{x, y}, r});
    }
    for (int i = 0; i < n; ++i) {
        auto [xy1,r1] = g[i];
        auto [x1,y1] = xy1;
        for (int j = i + 1; j < n; ++j) {
            auto [xy2,r2] = g[j];
            auto [x2,y2] = xy2;
            double dis = pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5) - r1 - r2;
            //说明不用引线
            if (dis < 0) dis = 0;
            edges.push_back({i, j, dis});
        }
    }
    double ans = Kruskal(edges, n);
    printf("%.2lf", ans);
}

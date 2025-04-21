#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::pair;
using std::vector;

using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 * https://www.luogu.com.cn/problem/P3379
 */
signed main() {
    IOS();
    int n, m, s;
    cin >> n >> m >> s;
    vector g(n + 1, vector<int>()), up(n + 1, vector<int>(20));
    vector<int> dep(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    auto dfs = [&](auto &self, int now, int fa)-> void {
        dep[now] = dep[fa] + 1;
        up[now][0] = fa;
        for (auto &next: g[now]) {
            if (next == fa) continue;
            self(self, next, now);
        }
    };
    dfs(dfs, s, 0);
    for (int k = 1; k <= 20; ++k) {
        for (int v = 1; v <= n; ++v) {
            up[v][k] = up[up[v][k - 1]][k - 1];
        }
    }
    auto lca = [&](int a, int b) {
        if (dep[a] < dep[b]) std::swap(a, b);
        int diff = dep[a] - dep[b];
        for (int k = 0; k <= 20; ++k) {
            if (diff >> k & 1) a = up[a][k];
        }
        if (a == b) return a;
        for (int k = 20; k >= 0; --k) {
            if (up[a][k] != up[b][k]) {
                a = up[a][k];
                b = up[b][k];
            }
        }
        return up[a][0];
    };
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}

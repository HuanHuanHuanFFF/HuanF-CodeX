//
// Created by 幻 on 2025/7/15.
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

//
// Numb Numbers
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        for (int j = 0, y; j < x; ++j) {
            cin >> y;
            g[i].emplace_back(y);
        }
    }
    std::map<PII, int> ans;
    std::set<PII> vis;
    auto dfs = [&](auto &&self, int x, int last, vector<PII> &path)-> void {
        int y = 0;
        if (last != 0)
            for (int i = 0; i < g[x].size(); ++i) {
                if (g[x][i] == last) {
                    y = (i + 1) % g[x].size();
                    break;
                }
            }
        if (vis.contains({x, g[x][y]})) return;
        path.emplace_back(x, g[x][y]);
        vis.emplace(x, g[x][y]);
        self(self, g[x][y], x, path);
    };
    for (int i = 1; i <= n; ++i) {
        if (!ans.contains({i, g[i][0]})) {
            vector<PII> p;
            dfs(dfs, i, 0, p);
            std::set<PII> v;
            for (auto [x,y]: p) {
                if (x > y) std::swap(x, y);
                v.emplace(x, y);
            }
            for (auto &[x,y]: p) {
                ans[{x, y}] = v.size();
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[{i, g[i][0]}] << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

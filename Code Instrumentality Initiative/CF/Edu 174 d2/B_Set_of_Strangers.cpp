//
// Created by 幻 on 2025/6/22.
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

constexpr bool more = true;

// Educational Codeforces Round 174 (Rated for Div. 2) 
// B. Set of Strangers
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    bool tag = false;
    auto dfs = [&](int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == a[x][y]) {
                tag = true;
                return 2;
            }
        }
        return 1;
    };
    ll ans = 0;
    std::map<int, int> cost;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c = dfs(i, j);
            cost[a[i][j]] = std::max(c, cost[a[i][j]]);
        }
    }
    for (auto &[x,y]: cost) ans += y;
    cout << ans - (tag ? 2 : 1) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/16.
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

// Codeforces Round 984 (Div. 3) 
// D. I Love 1543
// https://codeforces.com/contest/2036/problem/D
// 模拟 暴力
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }
    int d = n / 2, h = m / 2;
    ll ans = 0;
    for (int x = 1, y = 1; x <= d && y <= h; ++x, ++y) {
        vector<char> p;
        for (int i = y; i <= m - y + 1; ++i) p.emplace_back(g[x][i]);
        for (int i = x + 1; i <= n - x + 1; ++i) p.emplace_back(g[i][m - y + 1]);
        for (int i = m - y; i >= y; --i) p.emplace_back(g[n - x + 1][i]);
        for (int i = n - x; i >= x + 1; --i) p.emplace_back(g[i][y]);
        for (int i = 0; i < 3; ++i) p.emplace_back(p[i]);
        for (int i = 0; i < p.size() - 3; ++i) {
            if (p[i] == '1' && p[i + 1] == '5' && p[i + 2] == '4' && p[i + 3] == '3') ++ans;
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

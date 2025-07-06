//
// Created by 幻 on 2025/7/3.
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

// Codeforces Round 997 (Div. 2) 
// A. Shape Perimeter
// https://codeforces.com/contest/2056/problem/A
// 根据每次平移计算接触抵消的周长
void HuanF() {
    ll ans = 0, n, m;
    cin >> n >> m;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        ans += 4 * m;
        if (y > m || x > m || i == 0) continue;
        int dis = 2 * m - x - y;
        ans -= 2 * dis;
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

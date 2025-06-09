//
// Created by 幻 on 2025/6/8.
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
constexpr int N = 1e6 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = true;

// Codeforces Round 962 (Div. 3) 
// D. Fun
// https://codeforces.com/contest/1996/problem/D
// 这题暴力都想不到😭😭😭还是太菜了
void HuanF() {
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    for (int a = 1; a <= std::min(x, n); ++a) {
        for (int b = 1; b <= n / a && a + b <= x; ++b) {
            ll c = std::min((n - a * b) / (a + b), x - a - b);
            ans += c;
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

//
// Created by 幻 on 2025/6/18.
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

// Experimental Educational Round: VolBIT Formulas Blitz 
// A. Again Twenty Five!
void HuanF() {
    int n;
    cin >> n;
    ll ans = 1, base = 5, mod = 100;
    while (n) {
        if (n & 1) ans = base * ans % mod;
        base = base * base % mod;
        n >>= 1;
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

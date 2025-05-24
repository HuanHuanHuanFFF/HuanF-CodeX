//
// Created by 幻 on 2025/5/23.
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

// Panasonic Programming Contest 2025（AtCoder Beginner Contest 406） 
// B - Product Calculator
// https://atcoder.jp/contests/abc406/tasks/abc406_b
void HuanF() {
    ll n, k;
    __int128_t x = 1, y = 1;
    cin >> n >> k;
    while (k-- > 0) y *= 10;
    for (ll i = 0, a; i < n; ++i) {
        cin >> a;
        x *= a;
        if (x >= y) x = 1;
    }
    cout << static_cast<ll>(x);
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

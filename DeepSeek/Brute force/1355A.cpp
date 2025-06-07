//
// Created by 幻 on 2025/6/7.
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

// Codeforces Round 643 (Div. 2) 
// A. Sequence with Digits
// https://codeforces.com/problemset/problem/1355/A
// guess出来然后暴力
void HuanF() {
    ll a, k;
    cin >> a >> k;
    auto min_d = [](ll a) {
        ll d = 10;
        while (a) {
            d = std::min(a % 10, d);
            a /= 10;
        }
        return d;
    };
    auto max_d = [](ll a) {
        ll d = 0;
        while (a) {
            d = std::max(a % 10, d);
            a /= 10;
        }
        return d;
    };

    for (int i = 0; i < k - 1; ++i) {
        if (min_d(a) == 0 || max_d(a) == 0) break;
        a = a + min_d(a) * max_d(a);
        // cout << a << "\n";
    }
    cout << a << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/2.
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

// Codeforces Round  834 (Div. 3) 
// D. Make It Round
// https://codeforces.com/problemset/problem/1759/D
// 暴力
// 必须2和5的因数数量一样才能有0结尾
void HuanF() {
    ll n, m;
    cin >> n >> m;
    int cnt2 = 0, cnt5 = 0;
    ll p = n, q = n * m;
    while (p > 0 && p % 2 == 0) {
        p /= 2;
        ++cnt2;
    }
    while (p > 0 && p % 5 == 0) {
        p /= 5;
        ++cnt5;
    }
    ll all = 1;
    while (cnt2 < cnt5 && all * 2 <= m) {
        n *= 2;
        ++cnt2;
        all *= 2;
    }
    while (cnt2 > cnt5 && all * 5 <= m) {
        n *= 5;
        ++cnt5;
        all *= 5;
    }
    while (all * 10 <= m) {
        all *= 10;
        n *= 10;
    }
    if (all == 1) cout << q << "\n";
    else {
        all = m / all;
        cout << n * all << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/27.
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

// Codeforces Round 995 (Div. 3) 
// B. Journey
// https://codeforces.com/contest/2051/problem/B
void HuanF() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll p = a + b + c;
    ll ans = n / p * 3;
    n %= p;
    if (n > 0) {
        n -= a;
        ++ans;
    }
    if (n > 0) {
        n -= b;
        ++ans;
    }
    if (n > 0) {
        n -= c;
        ++ans;
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

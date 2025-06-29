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

constexpr bool more = false;

// P3811 【模板】模意义下的乘法逆元
// https://www.luogu.com.cn/problem/P3811
void HuanF() {
    // ll n, p;
    // cin >> n >> p;
    // vector<ll> inv(n + 1);
    // inv[1] = 1;
    // for (int i = 2; i <= n; ++i) {
    //     inv[i] = p - p / i * inv[p % i] % p;
    // }
    // for (int i = 1; i <= n; ++i) {
    //     cout << inv[i] << "\n";
    // }
    vector<ll> inv(N);
    inv[1] = 1;
    for (int i = 2; i <= N; ++i) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

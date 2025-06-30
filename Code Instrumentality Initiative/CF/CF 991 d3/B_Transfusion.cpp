//
// Created by 幻 on 2025/6/28.
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

// Codeforces Round 991 (Div. 3) 
// B. Transfusion
// https://codeforces.com/contest/2050/problem/B
// 奇数位和偶数位可以不断平均
void HuanF() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    sum = std::accumulate(a.begin(), a.end(), 0ll);
    if (sum % n != 0) {
        cout << "NO\n";
        return;
    }
    ll avg = sum / n;
    ll odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) odd += a[i];
        else even += a[i];
    }
    if (odd / (n / 2) == avg && even / ((n + 1) / 2) == avg)
        cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

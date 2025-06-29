//
// Created by 幻 on 2025/6/29.
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
constexpr ll INF = 4e17 + 17;
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

// Codeforces Round 783 (Div. 1) 
// A. Make it Increasing
// https://codeforces.com/problemset/problem/1667/A
// 暴力
// n只有5000 可以n^2
// 枚举0的位置,按最小递增计算
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        vector<ll> b(n);
        ll now = 0;
        for (int j = i + 1; j < n; ++j) {
            ll tar = b[j - 1] + 1;
            ll move = (tar + a[j] - 1) / a[j];
            b[j] = move * a[j];
            now += move;
        }
        for (int j = i - 1; j >= 0; --j) {
            ll tar = b[j + 1] - 1;
            ll move = (tar - a[j] + 1) / a[j];
            b[j] = move * a[j];
            now -= move;
        }
        ans = std::min(ans, now);
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

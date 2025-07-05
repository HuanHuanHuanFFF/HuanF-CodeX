//
// Created by 幻 on 2025/7/5.
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

// Codeforces Round 909 (Div. 3) 
// B. 250 Thousand Tons of TNT
// https://codeforces.com/problemset/problem/1899/B
// 暴力模拟
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int k = 1; k <= n; ++k) {
        if (n % k != 0) continue;
        ll max = 0, min = INF;
        vector<ll> s(n / k);
        for (int i = 0; i < n; ++i) {
            s[i / k] += a[i];
        }
        max = std::ranges::max(s);
        min = std::ranges::min(s);
        ans = std::max(max - min, ans);
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

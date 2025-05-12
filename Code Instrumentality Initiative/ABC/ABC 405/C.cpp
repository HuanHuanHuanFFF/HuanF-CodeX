//
// Created by 幻 on 2025/5/12.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// https://atcoder.jp/contests/abc405/tasks/abc405_c
// 根据公式相当于每个数乘以后缀和
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n), suf(n + 1);
    for (auto &x: a) cin >> x;
    for (int i = n - 1; i >= 0; --i) {
        suf[i] += suf[i + 1] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += a[i] * suf[i + 1];
    }
    cout << ans;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

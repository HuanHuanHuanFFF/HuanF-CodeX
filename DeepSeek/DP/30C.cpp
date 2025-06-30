//
// Created by 幻 on 2025/6/30.
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

// Codeforces Beta Round 30 (Codeforces format) 
// C. Shooting Gallery
// https://codeforces.com/problemset/problem/30/C
// 线性dp  按时间排序依次判断O(n^2)
void HuanF() {
    int n;
    cin >> n;
    vector<double> dp(n);
    vector<std::array<double, 4> > ns(n);
    for (auto &[t,x,y,p]: ns) {
        cin >> x >> y >> t >> p;
    }
    std::ranges::sort(ns);
    for (int i = 0; i < n; ++i) {
        dp[i] = ns[i][3];
    }
    for (int i = 1; i < n; ++i) {
        auto &[t,x,y,p] = ns[i];
        for (int j = 0; j < i; ++j) {
            auto &[t1,x1,y1,p1] = ns[j];
            if (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) <= t - t1)
                dp[i] = std::max(dp[i], dp[j] + p);
        }
    }
    printf("%.8lf", std::ranges::max(dp));
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

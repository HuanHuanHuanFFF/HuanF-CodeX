//
// Created by 幻 on 2025/7/12.
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

// Codeforces Round 355 (Div. 2)
// A. Vanya and Fence
// https://codeforces.com/problemset/problem/677/A
// 水题这一块
void HuanF() {
    int n, h;
    cin >> n >> h;
    int ans = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ans += x > h ? 2 : 1;
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

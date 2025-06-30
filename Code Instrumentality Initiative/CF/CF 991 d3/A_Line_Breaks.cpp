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
// A. Line Breaks
// https://codeforces.com/contest/2050/problem/A
void HuanF() {
    int n, m, sum = 0, ans = 0;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        sum += s.length();
        if (sum <= m) ++ans;
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

//
// Created by 幻 on 2025/7/14.
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

// Codeforces Round 899 (Div. 2) 
// A. Increasing Sequence
// https://codeforces.com/contest/1882/problem/A
// 模拟贪心
void HuanF() {
    int n, b = 1;
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        if (x == b) ++b;
        if (i == n) break;
        ++b;
    }
    cout << b << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

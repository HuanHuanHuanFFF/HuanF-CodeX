//
// Created by 幻 on 2025/6/6.
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

// Codeforces Beta Round 47 
// A. Domino piling
// https://codeforces.com/problemset/problem/50/A
void HuanF() {
    int m, n;
    cin >> m >> n;
    cout << std::max(m / 2 * n + m % 2 * n / 2, n / 2 * m + n % 2 * m / 2);
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

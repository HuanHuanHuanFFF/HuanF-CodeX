//
// Created by 幻 on 2025/7/3.
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

// Codeforces Round 997 (Div. 2) 
// C. Palindromic Subsequences
// https://codeforces.com/contest/2056/problem/C
// 分析样例1,分析完直接秒了
void HuanF() {
    int n;
    cin >> n;
    cout << "1 1 2 ";
    for (int i = 0; i < n - 5; ++i) {
        cout << 3 + i << " ";
    }
    cout << "1 2\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

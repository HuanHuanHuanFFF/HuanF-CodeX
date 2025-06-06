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

// Codeforces Round 161 (Div. 2) 
// A. Beautiful Matrix 曼哈顿距离
// https://codeforces.com/problemset/problem/263/A
void HuanF() {
    int x = 0, y = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0, k; j < 5; ++j) {
            cin >> k;
            if (k) x = i, y = j;
        }
    }
    cout << std::abs(x - 2) + std::abs(y - 2);
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

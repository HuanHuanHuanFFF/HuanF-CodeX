//
// Created by 幻 on 2025/6/21.
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

// Codeforces Round 1033 (Div. 2) and CodeNite 2025 
// A. Square of Rectangles
// 分类讨论,注意给的矩形是越来越小的
// https://codeforces.com/contest/2120/problem/A
void HuanF() {
    int l1, l2, l3, b1, b2, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l1 > b1) {
        if (l2 == l3 && l1 == l2 && l1 == b1 + b2 + b3) {
            cout << "YES\n";
            return;
        }
        if (l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1) {
            cout << "YES\n";
            return;
        }
    }
    if (l1 < b1) {
        if (l2 == l3 && b1 == b2 + b3 && b1 == l1 + l2) {
            cout << "YES\n";
            return;
        }
        if (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

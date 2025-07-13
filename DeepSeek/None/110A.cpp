//
// Created by 幻 on 2025/7/13.
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

// Codeforces Beta Round 84 (Div. 2 Only)
// A. Nearly Lucky Number
// https://codeforces.com/problemset/problem/110/A
// 水题wa2次这一块
void HuanF() {
    ll n, cnt = 0;
    cin >> n;
    while (n) {
        int x = n % 10;
        if (x == 7 || x == 4) ++cnt;
        n /= 10;
    }
    if (cnt == 7 || cnt == 4)
        cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

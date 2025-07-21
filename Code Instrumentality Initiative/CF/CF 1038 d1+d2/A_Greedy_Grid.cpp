//
// Created by 幻 on 2025/7/19.
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

// Order Capital Round 1 (Codeforces Round 1038, Div. 1 + Div. 2) 
// A. Greedy Grid
// https://codeforces.com/contest/2122/problem/A
// 某个为1的情况,和两个小于等于2的情况都不可能
// 对于大于2的,引诱他走到某一端,然后在到不了的地方放一个INF
void HuanF() {
    int n, m;
    cin >> n >> m;
    if ((n <= 2 && m <= 2) || m == 1 || n == 1) cout << "NO\n";
    else cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

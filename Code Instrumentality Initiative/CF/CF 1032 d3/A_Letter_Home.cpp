//
// Created by 幻 on 2025/6/17.
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

// Codeforces Round 1032 (Div. 3) 
// A. Letter Home
// https://codeforces.com/contest/2121/problem/A
void HuanF() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    cout << std::ranges::max(a) - std::ranges::min(a) + std::min(
        abs(s - std::ranges::min(a)), abs(s - std::ranges::max(a))) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

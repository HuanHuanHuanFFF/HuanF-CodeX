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

constexpr bool more = false;

// UNIQUE VISION Programming Contest 2025 Summer (AtCoder Beginner Contest 411) 
// A - Required Length
// https://atcoder.jp/contests/abc411/tasks/abc411_a
void HuanF() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    cout << (s.length() >= n ? "Yes" : "No") << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/22.
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

// Educational Codeforces Round 181 (Rated for Div. 2) 
// A. Difficult Contest、
// https://codeforces.com/contest/2125/problem/A
// 把T放到最前面就好了
void HuanF() {
    string s;
    cin >> s;
    for (int i = 0; i < std::count(s.begin(), s.end(), 'T'); ++i) {
        cout << "T";
    }
    for (auto &c: s) {
        if (c == 'T') continue;
        cout << c;
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

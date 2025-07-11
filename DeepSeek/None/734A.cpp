//
// Created by 幻 on 2025/7/11.
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

// Codeforces Round 379 (Div. 2)
// A. Anton and Danik
// https://codeforces.com/problemset/problem/734/A
// 水题这一块
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    int win = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') ++win;
        else --win;
    }
    if (win > 0) cout << "Anton";
    else if (win < 0) cout << "Danik";
    else cout << "Friendship";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

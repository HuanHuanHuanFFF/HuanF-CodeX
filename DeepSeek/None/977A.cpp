//
// Created by 幻 on 2025/7/8.
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

// Codeforces Beta Round 55 (Div. 2) 
// A. Word
// https://codeforces.com/problemset/problem/59/A
void HuanF() {
    string s;
    cin >> s;
    int big = 0, small = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') ++big;
        else ++small;
    }
    if (big > small) for (auto &c: s) c = toupper(c);
    else for (auto &c: s) c = tolower(c);
    cout << s;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

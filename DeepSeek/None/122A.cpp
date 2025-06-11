//
// Created by 幻 on 2025/6/11.
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

// Codeforces Beta Round 85 (Div. 2 Only) 
// A. Petya and Strings
void HuanF() {
    string a, b;
    cin >> a >> b;
    for (char &c: a) c = tolower(c);
    for (char &c: b) c = tolower(c);
    if (a > b) {
        cout << 1;
    } else if (a < b) cout << -1;
    else cout << 0;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

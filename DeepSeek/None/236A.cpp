//
// Created by 幻 on 2025/6/15.
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

// Codeforces Round 146 (Div. 2) 
// A. Boy or Girl
void HuanF() {
    string s;
    cin >> s;
    std::set<char> st;
    for (int i = 0; i < s.length(); ++i) {
        st.insert(s[i]);
    }
    if (st.size() % 2 == 1) {
        cout << "IGNORE HIM!";
    } else
        cout << "CHAT WITH HER!";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

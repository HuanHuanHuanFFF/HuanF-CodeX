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

constexpr bool more = true;

// Codeforces Round 817 (Div. 4) 
// A. Spell Check
// https://codeforces.com/problemset/problem/1722/A
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    if (n != 5) {
        cout << "NO\n";
        return;
    }
    std::map<char, int> cnt;
    std::set<char> st;
    st.insert('T');
    st.insert('i');
    st.insert('m');
    st.insert('r');
    st.insert('u');
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i]];
    }
    for (auto &[x,y]: cnt) {
        if (y > 1 || !st.contains(x)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

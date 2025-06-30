//
// Created by 幻 on 2025/6/30.
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

// Codeforces Round 108 (Div. 2) 
// C. Pocket Book
// https://codeforces.com/problemset/problem/152/C
// 乘法原理
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x: s) cin >> x;
    ll ans = 1;
    for (int i = 0; i < m; ++i) {
        std::set<char> st;
        for (int j = 0; j < n; ++j) {
            st.insert(s[j][i]);
        }
        ans = ans * st.size() % MOD;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

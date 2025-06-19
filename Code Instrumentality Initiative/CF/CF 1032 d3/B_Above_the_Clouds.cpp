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
// B. Above the Clouds
// https://codeforces.com/contest/2121/problem/B
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    std::set<char> st;
    st.insert(s[0]);
    for (int i = 1; i < n - 1; ++i) {
        if (st.contains(s[i])) {
            cout << "Yes\n";
            return;
        }
        st.insert(s[i]);
    }
    st.clear();
    st.insert(s.back());
    for (int i = n - 2; i > 0; --i) {
        if (st.contains(s[i])) {
            cout << "Yes\n";
            return;
        }
        st.insert(s[i]);
    }
    cout << "No\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

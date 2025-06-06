//
// Created by 幻 on 2025/6/3.
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

// Educational Codeforces Round 179 (Rated for Div. 2) 
// D. Creating a Schedule
// https://codeforces.com/contest/2111/problem/D
// 模拟,set暴力抽插放松大脑
void HuanF() {
    int n, m;
    cin >> n >> m;
    std::set<int> st;
    vector<PII> ans;
    int cn = n;
    if (n & 1) ++n;
    n >>= 1;
    ans.reserve(n);
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        st.emplace(x);
    }
    int c = n;
    while (c--) {
        ans.emplace_back(*st.begin(), *st.rbegin());
        st.erase(st.begin());
        if (!st.empty())
            st.erase(*st.rbegin());
    }
    for (auto &[x,y]: ans) {
        for (int i = 1; i <= 6; ++i) {
            if (i & 1) cout << x << " ";
            else cout << y << " ";
        }
        cout << "\n";
    }
    for (int k = 0; k < cn - n; ++k) {
        auto [x,y] = ans[k];
        for (int i = 1; i <= 6; ++i) {
            if (i & 1) cout << y << " ";
            else cout << x << " ";
        }
        cout << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

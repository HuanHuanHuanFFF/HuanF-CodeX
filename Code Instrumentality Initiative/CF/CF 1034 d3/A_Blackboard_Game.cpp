//
// Created by 幻 on 2025/7/1.
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

// Codeforces Round 1034 (Div. 3) 
// A. Blackboard Game
// https://codeforces.com/contest/2123/problem/A
// 观察不出来,wa了几次急了写暴力才过😇
// 观察0 1 2 3 0 1 2 3,只有4的倍数的时候bob才能赢
// 或者是0 3,1 2的个数一样才行
void HuanF() {
    // int n;
    // cin >> n;
    // std::set<int> st;
    // for (int i = 0; i < n; ++i) {
    //     st.insert(i);
    // }
    // for (int i = 0; i < n; ++i) {
    //     if (st.contains(i)) {
    //         st.erase(i);
    //         bool tag = false;
    //         for (int j = 0; j < n; ++j) {
    //             if (st.contains(j) && (i + j) % 4 == 3) {
    //                 st.erase(j);
    //                 tag = true;
    //                 break;
    //             }
    //         }
    //         if (!tag) {
    //             cout << "Alice\n";
    //             return;
    //         }
    //     }
    // }
    // if (st.empty())
    //     cout << "Bob\n";
    // else cout << "Alice\n";
    int n;
    cin >> n;
    cout << (n % 4 == 0 ? "Bob" : "Alice") << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/27.
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

// IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2) 
// A. Kevin and Arithmetic
// 先排偶数后排奇数
// https://codeforces.com/contest/2061/problem/A
void HuanF() {
    int ans = 0, n;
    cin >> n;
    bool tag = false;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x & 1) ++ans;
        if (!tag && (x & 1) == 0) {
            ++ans;
            tag = true;
        }
    }
    cout << ans - (!tag) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

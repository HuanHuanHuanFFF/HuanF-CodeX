//
// Created by 幻 on 2025/6/20.
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

// Ethflow Round 1 (Codeforces Round 1001, Div. 1 + Div. 2) 
// B. Clockwork
// 题目看错卡我半天
// 来回边跑边复原
// https://codeforces.com/contest/2062/problem/B
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= std::max(i, n - i - 1) * 2) {
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

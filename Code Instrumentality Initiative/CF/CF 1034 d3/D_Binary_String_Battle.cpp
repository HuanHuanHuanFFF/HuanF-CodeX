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
// D. Binary String Battle
// https://codeforces.com/contest/2123/problem/D
// 开始我想了很久的第二个样例怎么Alice赢的
// 然后发现是通过留下最中间1个,这样即使从头或者从尾,Bob也只能变4个
// k>n/2时可以这样通过控制留下最中间的,Alice一定能赢
// 于是分为两种情况判断
// 另一种是直接看能不能一次消除
// O(N)
void HuanF() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k > n / 2) {
        cout << "Alice\n";
    } else {
        int cnt = std::ranges::count(s, '1');
        if (cnt > k) cout << "Bob\n";
        else cout << "Alice\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/23.
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

// Codeforces Round 1000 (Div. 2) 
// B. Subsequence Update
// https://codeforces.com/contest/2063/problem/B
// 子序列是分散的,相当于选区间外一边的最小的几个换过来
void HuanF() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    std::priority_queue<int, vector<int>, std::greater<> > heap1, heap2;
    for (int i = 1; i < l; ++i) {
        heap1.emplace(a[i]);
    }
    for (int i = r + 1; i <= n; ++i) {
        heap2.emplace(a[i]);
    }
    for (int i = l; i <= r; ++i) {
        heap1.emplace(a[i]);
        heap2.emplace(a[i]);
    }
    ll s1 = 0, s2 = 0;
    for (int i = l; i <= r; ++i) {
        s1 += heap1.top();
        heap1.pop();
        s2 += heap2.top();
        heap2.pop();
    }
    cout << std::min(s1, s2) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

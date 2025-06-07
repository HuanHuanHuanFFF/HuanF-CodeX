//
// Created by 幻 on 2025/6/5.
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

// Codeforces Round 1008 (Div. 2) 
// A. Final Verdict
// https://codeforces.com/contest/2078/problem/A
// 平均值可以推广开
void HuanF() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    double sum = std::accumulate(a.begin(), a.end(), 0);
    cout << (sum / n == x ? "YES" : "NO") << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

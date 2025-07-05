//
// Created by 幻 on 2025/7/4.
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

// Codeforces Round 304 (Div. 2) 
// A. Soldier and Bananas
// https://codeforces.com/problemset/problem/546/A
void HuanF() {
    ll n, k, w;
    cin >> k >> n >> w;
    ll need = 0;
    for (int i = 1; i <= w; ++i) {
        need += i * k;
    }
    cout << std::max(0ll, need - n);
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

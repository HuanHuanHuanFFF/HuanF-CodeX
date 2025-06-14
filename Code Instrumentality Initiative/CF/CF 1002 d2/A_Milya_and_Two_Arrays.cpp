//
// Created by 幻 on 2025/6/13.
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

// Codeforces Round 1002 (Div. 2) 
// A. Milya and Two Arrays
// https://codeforces.com/contest/2059/problem/A
// 乘法原理
void HuanF() {
    int n;
    cin >> n;
    std::set<int> a, b;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a.insert(x);
    }
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        b.insert(x);
    }
    if (a.size() * b.size() >= 3) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

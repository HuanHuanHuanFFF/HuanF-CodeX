//
// Created by 幻 on 2025/5/27.
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

// Codeforces Round 992 (Div. 2) 
// B. Paint a Strip
// https://codeforces.com/contest/2040/problem/B
void HuanF() {
    int n;
    cin >> n;
    ll a = 1, b = 0, l = 1;
    while (l < n) {
        ++a;
        ++b;
        ++l;
        l <<= 1;
    }
    cout << a << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

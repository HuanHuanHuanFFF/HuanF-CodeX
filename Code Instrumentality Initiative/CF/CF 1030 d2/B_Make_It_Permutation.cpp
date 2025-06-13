//
// Created by 幻 on 2025/6/12.
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

// Codeforces Round 1030 (Div. 2) 
// B. Make It Permutation
// https://codeforces.com/contest/2118/problem/B
// 注意力不够
void HuanF() {
    int n;
    cin >> n;
    cout << 2 * n - 1 << "\n";
    cout << "1 1 " << n << "\n";
    for (int i = 2; i <= n; ++i) {
        cout << i << " " << 1 << " " << n - i + 1 << "\n";
        cout << i << " " << n - i + 2 << " " << n << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

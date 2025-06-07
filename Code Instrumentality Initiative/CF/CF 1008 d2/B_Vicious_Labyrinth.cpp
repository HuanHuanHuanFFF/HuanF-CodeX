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
// B. Vicious Labyrinth
// https://codeforces.com/contest/2078/problem/B
// 奇偶分类讨论,保证都能走到出口处
void HuanF() {
    int n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 1; i <= n - 1; ++i) {
            cout << n << " ";
        }
        cout << n - 1 << "\n";
    } else {
        for (int i = 1; i <= n - 2; ++i) {
            cout << n - 1 << " ";
        }
        cout << n << " " << n - 1 << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

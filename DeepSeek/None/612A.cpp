//
// Created by 幻 on 2025/6/30.
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

// Educational Codeforces Round 4 
// A. The Text Splitting
// https://codeforces.com/problemset/problem/612/A
// 水题 暴力枚举
void HuanF() {
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    for (int i = 0; i <= n / q; ++i) {
        if ((n - q * i) % p == 0) {
            cout << i + (n - q * i) / p << "\n";
            int idx = -1;
            for (int j = 0; j < i; ++j) {
                for (int t = 0; t < q; ++t) {
                    cout << s[++idx];
                }
                cout << "\n";
            }
            for (int j = 0; j < (n - q * i) / p; ++j) {
                for (int t = 0; t < p; ++t) {
                    cout << s[++idx];
                }
                cout << "\n";
            }
            return;
        }
    }
    cout << "-1\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

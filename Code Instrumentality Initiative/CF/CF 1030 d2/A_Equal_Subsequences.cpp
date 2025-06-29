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
// A. Equal Subsequences
void HuanF() {
    int n, k;
    cin >> n >> k;
    if (k == n) {
        for (int i = 0; i < k; ++i) {
            cout << 1;
        }
        cout << "\n";
    } else if (k == 0) {
        for (int i = 0; i < n; ++i) {
            cout << 0;
        }
        cout << "\n";
    } else {
        cout << 1;
        for (int i = 0; i < n - 1 - k; ++i) {
            cout << 0;
        }
        for (int i = 1; i < k; ++i) {
            cout << 1;
        }
        cout << 0;
        cout << "\n";
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

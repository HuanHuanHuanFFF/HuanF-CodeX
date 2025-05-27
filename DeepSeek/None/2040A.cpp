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
// A. Game of Division
// https://codeforces.com/contest/2040/problem/A
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    for (int i = 0; i < n; ++i) {
        bool win = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (std::abs(a[i] - a[j]) % k == 0) {
                win = false;
                break;
            }
        }
        if (win) {
            cout << "YES\n" << i + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

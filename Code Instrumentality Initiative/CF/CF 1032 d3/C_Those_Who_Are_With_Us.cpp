//
// Created by 幻 on 2025/6/17.
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

// Codeforces Round 1032 (Div. 3) 
// C. Those Who Are With Us
// https://codeforces.com/contest/2121/problem/C
// 暴力枚举每个点做行列-1,看是否能消除全部最大
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector mat(n, vector<int>(m));
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
            mx = std::max(mx, mat[i][j]);
        }
    }
    vector<int> cnt_v(n), cnt_h(m);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == mx) {
                ++sum;
                ++cnt_h[j];
                ++cnt_v[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cnt_h[j] + cnt_v[i] - (mat[i][j] == mx) == sum) {
                cout << mx - 1 << "\n";
                return;
            }
        }
    }
    cout << mx << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

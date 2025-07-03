//
// Created by 幻 on 2025/7/1.
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

// Codeforces Round 1034 (Div. 3) 
// B. Tournament
// https://codeforces.com/contest/2123/problem/B
// 如果k>=2,就让最大的把其他都打了
// 否则他是最大的才能留下
void HuanF() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int x = a[j];
    if (k == 1) {
        if (x == std::ranges::max(a))
            cout << "YES\n";
        else cout << "NO\n";
    } else cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

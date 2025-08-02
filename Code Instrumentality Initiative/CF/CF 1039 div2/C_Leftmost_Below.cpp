//
// Created by 幻 on 2025/7/27.
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

// Codeforces Round 1039 (Div. 2) 
// C. Leftmost Below
// https://codeforces.com/contest/2128/problem/C
// 贪心
// 只要小于等于pre_min的两倍,就能最多分两次达到所需的值
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre_min(n + 1, INF);
    // for (auto &x: a) cin >> x;
    for (auto &x: a | std::views::drop(1)) cin >> x;
    for (int i = 1; i <= n; ++i) {
        pre_min[i] = std::min(pre_min[i - 1], a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= pre_min[i] * 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

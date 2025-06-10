//
// Created by 幻 on 2025/5/31.
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

// https://atcoder.jp/contests/abc408/tasks/abc408_c
// 差分找最小的
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 2);
    for (int i = 0, l, r; i < m; ++i) {
        cin >> l >> r;
        ++d[l];
        --d[r + 1];
    }
    ll ans = INF, x = 0;
    for (int i = 1; i <= n; ++i) {
        x += d[i];
        ans = std::min(ans, x);
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

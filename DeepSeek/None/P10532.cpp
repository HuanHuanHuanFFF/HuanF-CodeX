//
// Created by 幻 on 2025/5/16.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// https://www.luogu.com.cn/problem/P10532
// 打表->不会有这么巧的事吧
void HuanF() {
    ll n;
    cin >> n;
    // ll ans = 0;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         if (std::gcd(i, j) == 1)
    //             ans += n / std::max(i, j);
    //     }
    // }
    cout << n * n << "\n";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

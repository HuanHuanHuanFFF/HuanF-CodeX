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
// E. Sponsor of Your Problems
// https://codeforces.com/contest/2121/problem/E
// 如果大于10并且前一位大于1,就不用看这一位
// 然后最多枚举十几个数计算取值就行 非常省脑
void HuanF() {
    int l, r;
    cin >> l >> r;
    auto f = [](int x, int l, int r) {
        int ans = 0;
        while (l) {
            if (l % 10 == x % 10) ++ans;
            if (r % 10 == x % 10) ++ans;
            l /= 10;
            r /= 10;
            x /= 10;
        }
        return ans;
    };
    int ans = INF;
    while (true) {
        if (r / 10 > l / 10 && r - l >= 10) {
            r /= 10;
            l /= 10;
        } else break;
    }
    for (int i = l; i <= r; ++i) {
        ans = std::min(ans, f(i, l, r));
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

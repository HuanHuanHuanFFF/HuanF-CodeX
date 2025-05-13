//
// Created by 幻 on 2025/5/11.
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

/* 2102A - Dinner Time
 * link: https://codeforces.com/problemset/problem/2102/A
 * 思路:
 * 1. 由每个长度为 p 的窗口和相同可得 a[i+p] = a[i], 整个数组对 p 周期性
 * 2. 令 k = n / p, d = n % p, 则总和 m = k * q + (前 d 个周期内元素之和)
 * 3. 当 d == 0 时, 前 d 项和为 0, 必须 m == k*q, 否则无解
 *    当 d > 0 时, 可以通过调整周期内元素使前 d 项之和任意, 故总有解
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */
void HuanF() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p == 0 && n / p * q != m)
        cout << "no\n";
    else cout << "yes\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

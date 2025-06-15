//
// Created by 幻 on 2025/6/15.
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

// Codeforces Round 1003 (Div. 4) 
/* CF1003 C2
 * link: https://codeforces.com/problemset/problem/2065/C2
 * 标签: 贪心, 二分查找
 * 思路:
 *   从左往右遍历 a[i]，维护前一位置的最小可得值 prev。
 *   对于 i=1，prev = min(a[1], b[1]-a[1])。
 *   对于 i>1：
 *     - 在 b 中二分找第一个 bj 使 bj - a[i] >= prev；
 *     - 候选值有 x1 = a[i]（不操作）和 x2 = bj - a[i]；
 *     - 取最小的那一个若 ≥ prev，否则取另一个；若两者都 < prev，则无解。
 *   判断 x ≥ prev 即可保证非减序列，时间 O(n log m)。
 * 时间复杂度: O(n log m)
 * 空间复杂度: O(n + m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    std::ranges::sort(b);
    a[0] = std::min(b.front() - a[0], a[0]);
    for (int i = 1; i < n; ++i) {
        auto p = std::ranges::lower_bound(b, a[i] + a[i - 1]) - b.begin();
        if (p < m && p >= 0) {
            if (a[i] >= a[i - 1])
                a[i] = std::min(b[p] - a[i], a[i]);
            else a[i] = b[p] - a[i];
        }
        if (a[i] < a[i - 1]) {
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

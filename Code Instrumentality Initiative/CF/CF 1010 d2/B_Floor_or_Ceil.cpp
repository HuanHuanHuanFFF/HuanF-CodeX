//
// Created by 幻 on 2025/5/30.
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

// Codeforces Round 1010 (Div. 2, Unrated) 
/* 2082B - Floor or Ceil
 * link: https://codeforces.com/contest/2082/problem/B
 * 标签: 二进制, 贪心, 模拟
 * 思路:
 *   最大值: 先做 m 次 ceil(⌈x/2⌉) 保证尽可能多进位, 再做 n 次 floor(⌊x/2⌋) 丢弃最低位
 *   最小值: 先做 n 次 floor, 再做 m 次 ceil
 *   由于每次操作右移后 x 迅速变小, O(log x) 步后 x 不变, 可直接模拟
 * 时间复杂度: O(log x)
 * 空间复杂度: O(1)
 */
void HuanF() {
    int x, n, m;
    cin >> x >> n >> m;
    int p = x;
    for (int i = 0; i < m; ++i) {
        if (p <= 1) break;
        p = (p + 1) >> 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!p) break;
        p >>= 1;
    }
    cout << p << " ";
    p = x;
    for (int i = 0; i < n; ++i) {
        if (!p) break;
        p >>= 1;
    }
    for (int i = 0; i < m; ++i) {
        if (p <= 1) break;
        p = (p + 1) >> 1;
    }
    cout << p << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

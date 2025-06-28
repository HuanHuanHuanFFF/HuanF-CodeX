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

// Codeforces Round 1006 (Div. 3)
/* 2072F - Goodbye, Banker Life
 * link: https://codeforces.com/contest/2072/problem/F
 * 标签: 杨辉三角、谢尔宾斯基三角、Lucas 定理、按位运算、O(n) 构造
 * 思路:
 *   1. 定义中间递推 Ti,j = Ti-1,j-1 ⊕ Ti-1,j 等价于
 *        Ti,j = k ⨁⋯ (组合意义上对上层做「模 2 加法」)。
 *      因而 Ti,j = k × ( C(i-1, j-1) mod 2 )，与杨辉三角奇偶性一致。
 *
 *   2. **挖掉偶数 ⇒ 谢尔宾斯基三角**
 *        Pascal Triangle mod 2 中偶数为 0，奇数为 1，可视化就是
 *        谢尔宾斯基三角形。我们仅需判断组合数奇偶性。
 *
 *   3. **Lucas 定理 (p = 2) 特例**
 *        C(n-1, j-1) mod 2 = 1  ⇔  (j-1) & (n-j) = 0
 *        → 无需预处理 C(n,k)，直接按位判断。
 *
 *   4. 枚举 j=1..n
 *        若 ( (j-1) & (n-j) ) == 0 输出 k，否则输出 0。
 *
 *   复杂度: O(n) 时间，O(1) 额外空间 —— 最简满足题意。
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << "\n";
        return;
    }
    cout << k << " ";
    for (int i = 2; i < n; ++i) {
        if (n - i & i - 1) cout << 0 << " ";
        else cout << k << " ";
    }
    cout << k << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

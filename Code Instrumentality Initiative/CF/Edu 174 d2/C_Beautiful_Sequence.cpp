//
// Created by 幻 on 2025/6/22.
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
constexpr int MOD = 998244353;
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

// Educational Codeforces Round 174 (Rated for Div. 2) 
/* 2069C-Beautiful Sequence
 * link: https://codeforces.com/contest/2069/problem/C
 * 标签: DP，状态机，子序列计数
 * 思路:
 *   用长度为 4 的 dp 数组表示「已选状态」：
 *     dp[0] = 1                // 空序列
 *     dp[1] = 已选首位 1
 *     dp[2] = 已选 1+若干个 2
 *     dp[3] = 已完成 1 2* 3
 *
 *   依次读取每个元素 x：
 *     — 若 x == 2：先让已有 dp[2] * 2（每条可“跳过/选中”），再加上所有状态 1 接上此 2 → dp[2] = dp[2]*2 + dp[1]
 *     — 无论 x 为 1、2 还是 3：都可把所有状态 (x−1) 的序列接上当前 x → dp[x] += dp[x−1]
 *       （但当 x==1 时，dp[0]=1 唯一来源；当 x==3 时，dp[2] 的序列首次完结）
 *
 *   最终 dp[3] 即为所有漂亮子序列的数量。
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), dp(4);
    dp[0] = 1;
    for (auto &x: a) {
        cin >> x;
        if (x == 2) dp[x] = dp[x] * 2 % MOD;
        dp[x] = (dp[x] + dp[x - 1]) % MOD;
    }
    cout << dp[3] << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/27.
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

// IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2) 
/* 2061C - Kevin and Puzzle
 * link: https://codeforces.com/contest/2061/problem/C
 * 标签: DP 不相邻限制 计数
 * 思路:
 * 0 边界 dp[0]=1 a[0]=0
 * 1 定义 dp[i] 为前 i 人中第 i 人诚实的方案数
 * 2 转移:
 *   若 i-1 诚实 且 a[i]==a[i-1] 则 dp[i]+=dp[i-1]
 *   若 i-1 为骗子(由 dp[i-2] 转移) 必满足 a[i]==a[i-2]+1 则 dp[i]+=dp[i-2]
 * 推论证明: 骗子前一人必诚实, 前 i-2 诚实时左侧骗子数为 a[i-2], 加上当前骗子自身总数为 a[i-2]+1
 * 3 结果 ans=(dp[n]+dp[n-1]) mod MOD
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i >= 2 && a[i] == a[i - 2] + 1) dp[i] = (dp[i] + dp[i - 2]) % MOD;
        if (a[i] == a[i - 1]) dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
    cout << (dp[n] + dp[n - 1]) % MOD << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/23.
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

constexpr bool more = false;

// Codeforces Round 674 (Div. 3)
/* 1426F-Number of Subsequences
 * link: https://codeforces.com/contest/1426/problem/F
 * 标签: 子序列计数 动态规划 状态机
 * 思路:
 *   dp[0] 记录前缀所有具体字符串数
 *   dp[1] 记录形成 a 的子序列数
 *   dp[2] 记录形成 ab 的子序列数
 *   dp[3] 记录形成 abc 的子序列数
 *   扫描 s
 *     若 x 为 '?'
 *       整体 *3 复制三种替换分支
 *       再用当前字符分别取 a b c 推进状态
 *         dp[i] += dp[i-1]  (i=1..3)
 *     若 x 为确定字母
 *       dp[x-'a'+1] += dp[x-'a']  (推进单一状态)
 *   最终答案为 dp[3]
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
 */
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    vector<ll> dp(4, 0);
    dp[0] = 1;
    char c = 'a' - 1;
    for (auto x: s) {
        if (x == '?') {
            for (int i = 3; i >= 1; --i) {
                dp[i] = dp[i] * 3 % MOD;
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
            dp[0] = dp[0] * 3 % MOD;
        } else dp[x - c] = (dp[x - c] + dp[x - c - 1]) % MOD;
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

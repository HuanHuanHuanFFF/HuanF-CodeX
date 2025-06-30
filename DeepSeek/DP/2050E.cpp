//
// Created by 幻 on 2025/6/29.
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

// Codeforces Round 991 (Div. 3) 
/* E-三个字符串
 * link: https://codeforces.com/problemset/problem/2050/E
 * 标签: 动态规划 DP 二维状态 交错序列
 * 思路:
 *   定义 dp[i][j] = 从 a 前 i 个、b 前 j 个字符交错取出，拼成 c 前 i+j 个时的最少修改次数
 *   转移:
 *     k = i+j-1  // c 下标从 0 开始
 *     // 下一位取自 a[i-1]
 *     dp[i][j] = min(dp[i][j], dp[i-1][j] + (a[i-1]!=c[k]));
 *     // 下一位取自 b[j-1]
 *     dp[i][j] = min(dp[i][j], dp[i][j-1] + (b[j-1]!=c[k]));
 *   边界:
 *     dp[0][0]=0
 *     dp[i][0]=dp[i-1][0]+(a[i-1]!=c[i-1])
 *     dp[0][j]=dp[0][j-1]+(b[j-1]!=c[j-1])
 *   答案: dp[n][m]
 * 时间复杂度 O(n*m)，空间复杂度 O(n*m)
 */
void HuanF() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size(), len = c.size();
    vector dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = dp[i][0] + (a[i] != c[i]);
    }
    for (int i = 0; i < m; ++i) {
        dp[0][i + 1] = dp[0][i] + (b[i] != c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = std::min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]),
                                dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
        }
    }
    cout << dp[n][m] << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

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

// AtCoder Beginner Contest 410 
/* E - 连续战斗
 * link: https://atcoder.jp/contests/abc410/tasks/abc410_e
 * 标签: 动态规划, 状态压缩
 * 思路:
 *   令 dp[i][m] 为打完前 i 只怪后剩余魔法 m 时的最大生命值（-1 表示不可达）
 *   对每个 i：
 *     1) 从大到小枚举 m，若 dp[i][m] != -1 且 m >= b[i+1]，则使用魔法：
 *        dp[i+1][m - b[i+1]] = max(dp[i+1][m - b[i+1]], dp[i][m]);
 *     2) 从大到小枚举 m，若 dp[i][m] >= a[i+1]，则使用生命：
 *        dp[i+1][m] = max(dp[i+1][m], dp[i][m] - a[i+1]);
 *   最后取最大的 i，使得存在 m 令 dp[i][m] >= 0，即为答案。
 * 时间复杂度: O(N*M)
 * 空间复杂度: O(N*M)
 */
void HuanF() {
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector dp(n + 1, vector<int>(m + 1, -1));
    dp[0][m] = h;
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 0; --j) {
            if (b[i + 1] > j) break;
            if (dp[i][j] != -1)
                dp[i + 1][j - b[i + 1]] = std::max(dp[i + 1][j - b[i + 1]], dp[i][j]);
        }
        for (int j = m; j >= 0; --j) {
            if (dp[i][j] >= a[i + 1])
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] - a[i + 1]);
        }
    }
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j <= m; ++j) {
            if (dp[i][j] >= 0) {
                cout << i << "\n";
                return;
            }
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

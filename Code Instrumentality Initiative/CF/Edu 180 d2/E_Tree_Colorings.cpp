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
constexpr int N = 5e5 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> dp(N, INF);

void init() {
    IOS();
    dp[1] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; (i + 2) * j < N; ++j) {
            dp[(i + 2) * j] = std::min(dp[(i + 2) * j], dp[i] + dp[j]);
        }
    }
}

constexpr bool more = true;

// Educational Codeforces Round 180 (Rated for Div. 2) 
/* 2112E - Tree Colorings
 * link: https://codeforces.com/contest/2112/problem/E
 * 标签: 树, 动态规划, 枚举
 * 思路:
 *  1. 定义 dp[k] 表示恰好有 k 种美丽染色的最小节点数，初始化 dp[1]=1，其余为无穷
 *  2. 对于任意 i, j 使 (i+2)*j<=M，可合并为染色数 (i+2)*j，节点数 dp[i]+dp[j]
 *     更新转移：dp[(i+2)*j] = min(dp[(i+2)*j], dp[i] + dp[j])
 *  3. 预处理 M=5e5 范围内所有 dp 值，查询时输出 dp[m] 或 -1
 * 时间复杂度 O(M log M)，空间复杂度 O(M)
 */
void HuanF() {
    int m;
    cin >> m;
    cout << (dp[m] == INF ? -1 : dp[m]) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

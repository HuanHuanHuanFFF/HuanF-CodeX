//
// Created by 幻 on 2025/7/19.
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

// Order Capital Round 1 (Codeforces Round 1038, Div. 1 + Div. 2)
/* 2122D-Traffic Lights
 * link: https://codeforces.com/contest/2122/problem/D
 * 标签: BFS·状态DP
 * 思路:
 *   1 枚举时间 t（0≤t≤3n），用 dp[x] 记录在时刻 t 到达 x 的最少等待次数
 *   2 转移:
 *     - 等待: next[x]=dp[x]+1
 *     - 行走: k=t % deg(x)，v=g[x][k]，next[v]=dp[x]
 *   3 首次出现 dp[n]≠INF 时，t+1 为最短总时间，dp[n] 为最少等待
 *   推论: 任一路径度数和 d=∑deg(u) ≤3n，故枚举 t≤3n 可覆盖所有最优
 * 时间复杂度 O(n^2 + m) 空间复杂度 O(n + m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int> dp(n + 1, INF), next(n + 1);
    dp[1] = 0;
    int ans1 = -1, ans2 = -1;
    for (int t = 0; dp[n] == INF; ++t) {
        std::ranges::fill(next, INF);
        for (int x = 1; x <= n; ++x) {
            if (dp[x] != INF) {
                next[x] = std::min(dp[x] + 1, next[x]);
                int sz = g[x].size();
                int y = g[x][t % sz];
                next[y] = std::min(next[y], dp[x]);
            }
        }
        dp.swap(next);
        if (dp[n] != INF) ans1 = t + 1, ans2 = dp[n];
    }
    cout << ans1 << " " << ans2 << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

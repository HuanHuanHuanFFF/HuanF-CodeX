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

#define x first
#define y second
// Codeforces Round 991 (Div. 3)
/* G-树的破坏
 * link: https://codeforces.com/problemset/problem/2050/G
 * 标签: 树 DP 贪心 后序遍历
 * 思路:
 *   令 w(v)=deg(v)-2，结合代码中用 deg(v) 初始化：
 *   dfs(x):
 *     // 初始取自身度数
 *     dp[x].first = g[x].size();
 *     取两大子贡献 m1,m2
 *     遍历每个子节点 y:
 *       dfs(y)
 *       // 从子树延伸一条链并减去 2
 *       dp[x].first = max(dp[x].first, dp[y].first + (int)g[x].size() - 2);
 *       更新 m1,m2 为子 dp[y].first 的前两大
 *     // 横穿 x 的路径
 *     dp[x].second = dp[x].first;
 *     nếu(m2 != -1) dp[x].second = max(dp[x].second, m1 + m2 + (int)g[x].size() - 4);
 * 答案: max_v max(dp[v].first, dp[v].second)
 * 时间复杂度 O(n)，空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<PII> dp(n + 1);
    auto dfs = [&](auto &&self, int x, int p)-> void {
        dp[x].x = g[x].size();
        int m1 = -1, m2 = -1;
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self,y,x);
            dp[x].x = std::max(dp[x].x, dp[y].x + (int) g[x].size() - 2);
            m2 = std::max(m2, dp[y].x);
            if (m1 < m2) std::swap(m1, m2);
        }
        dp[x].y = dp[x].x;
        if (m2 != -1) dp[x].y = m1 + m2 + g[x].size() - 4;
    };
    dfs(dfs, 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = std::max({ans, dp[i].x, dp[i].y});
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

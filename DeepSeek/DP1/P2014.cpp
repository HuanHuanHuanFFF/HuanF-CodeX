//
// Created by 幻 on 2025/5/21.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1E9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* P2014-CTSC1997 选课
 * link: https://www.luogu.com.cn/problem/P2014
 * 思路:
 * 将先修关系建成一棵（或多棵）树，添加学分为0的超级根0。
 * 树形DP：定义 dp[x][j] 为在x子树中恰选 j 门课（必须选x本身）时的最大学分和。
 * 对于每个节点x，初始化：
 *   若x==0（超级根）：dp[0][0]=0, sz[0]=0；
 *   否则：dp[x][0]=0, dp[x][1]=scores[x], sz[x]=1。
 * 然后DFS合并每个子v：
 *   倒序枚举 i=sz[x]→0, j=1→sz[v]，更新 dp[x][i+j]=max(dp[x][i+j], dp[x][i]+dp[v][j])。
 * 最后答案为 dp[0][M]。
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector child(n + 1, vector<int>()), dp(n + 1, vector<int>(m + 1, -INF));
    vector<int> scores(n + 1), sz(n + 1);
    for (int i = 1, k; i <= n; ++i) {
        cin >> k >> scores[i];
        child[k].emplace_back(i);
    }
    auto dfs = [&](auto &&self, int x)-> void {
        dp[0][0] = 0;
        if (x == 0) {
        } else {
            sz[x] = 1;
            dp[x][1] = scores[x];
        }
        for (auto &y: child[x]) {
            self(self, y);
            for (int i = sz[x]; i >= 0; --i) {
                if (dp[x][i] == -INF) continue;
                for (int j = 1; j <= sz[y]; ++j) {
                    if (i + j > m) break;
                    if (dp[y][j] == -INF) continue;
                    dp[x][i + j] = std::max(dp[x][i + j], dp[x][i] + dp[y][j]);
                }
            }
            sz[x] += sz[y];
        }
    };
    dfs(dfs, 0);
    cout << dp[0][m];
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

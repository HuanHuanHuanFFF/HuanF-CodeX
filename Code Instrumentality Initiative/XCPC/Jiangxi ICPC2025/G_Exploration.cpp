//
// Created by 幻 on 2025/5/29.
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
constexpr ll INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest 
/* G. 探险
 * link: https://codeforces.com/gym/105911/problem/G
 * 标签: 有向图, 动态规划, 二分查找
 * 思路:
 * 1. 限定最大步数 T = 35 —— 因为每次权重 ≥ 2，初始体力 ≤ 1e9，至多 ≲ 35 步后体力归 0
 * 2. 定义 dp[x][t] 表示从节点 x 出发恰走 t 条边时的最大难度乘积（超过 INF 截断为 INF）
 * 3. 转移：枚举所有有向边 u -> v，
 *    dp[u][t] = max(dp[u][t], min(INF, dp[v][t-1] * weight(u->v)))
 * 4. 预处理 O(T*(n + m)) 构建 dp 表；每次查询 (p, x) 时在 t∈[1..T] 上二分查找首个 dp[p][t] > x 即为答案
 * 时间复杂度: O(T*(n+m) + Q*log T)
 * 空间复杂度: O(n * T)
 */
void HuanF() {
    int n, m, q;
    cin >> n >> m >> q;
    vector g(n + 1, vector<PII>());
    for (int i = 0, x, y, w; i < m; ++i) {
        cin >> x >> y >> w;
        g[x].emplace_back(w, y);
    }
    vector dp(n + 1, vector<ll>(35, 1));
    for (int step = 1; step < 35; ++step) {
        for (int x = 1; x <= n; ++x) {
            dp[x][step] = 0;
        }
        for (int x = 1; x <= n; ++x) {
            for (auto &[d,y]: g[x]) {
                ll p = dp[y][step - 1] * d;
                if (p > INF) p = INF;
                dp[x][step] = std::max(dp[x][step], p);
            }
        }
    }
    for (int i = 0, x, p; i < q; ++i) {
        cin >> p >> x;
        int r = std::log2(x);
        int ans = std::upper_bound(dp[p].begin() + 1, dp[p].begin() + r + 1, x) - dp[p].begin();
        cout << ans << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* P1137-旅行计划
 * link: https://www.luogu.com.cn/problem/P1137
 * 思路:
 *   1. 将给定的城市和道路构造为有向无环图(DAG), 边从西向东, x->y 表示城市 x 在西, y 在东
 *   2. 使用入度数组 in[i] 记录每个城市的入度, dp[i] 初始为 1 表示至少能自己游览
 *   3. 用队列进行 Kahn 拓扑排序: 将所有 in[i]==0 的城市入队
 *   4. 当队列非空时, 取出当前城市 x, 遍历其所有出边 y:
 *      - dp[y] = max(dp[y], dp[x] + 1)  // 松弛最长路径
 *      - 若 --in[y] 变为 0, 则将 y 入队
 *   5. 排序结束后, dp[i] 即为以城市 i 为终点最多能游览的城市数
 * 时间复杂度: O(N + M)
 * 空间复杂度: O(N + M)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    vector<int> in(n + 1), dp(n + 1, 1);
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        ++in[y];
    }
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto &y: g[x]) {
            if (--in[y] == 0) q.push(y);
            dp[y] = std::max(dp[y], dp[x] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) cout << dp[i] << "\n";
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

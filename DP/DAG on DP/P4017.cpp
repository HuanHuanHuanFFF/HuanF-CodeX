#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 80112002;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* P4017-最大食物链计数
 * link: https://www.luogu.com.cn/problem/P4017
 * 思路:
 *   1. 将食物网视作有向无环图(DAG)，节点代表生物，边 x->y 表示 x 被 y 捕食。
 *   2. 用数组 in[i] 统计每个节点的入度（前驱数），out[i] 统计出度以识别消费者（出度为 0）。
 *   3. 拓扑排序 (Kahn 算法)：
 *      - 将所有 in[i]==0 的生产者入队，初始化 dp[i]=1，表示单独一条链。
 *      - 从队列中依次弹出 x，遍历其所有出边 y：
 *          dp[y] = (dp[y] + dp[x]) % MOD;  // 累加所有来源于生产者的链条数量
 *          if (--in[y] == 0) q.push(y);
 *   4. 遍历所有消费者节点（out[i]==0），将它们的 dp 值累加即为最大食物链数量。
 * 时间复杂度: O(n + m)
 * 空间复杂度: O(n + m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    vector<int> dp(n + 1), in(n + 1), out(n + 1);
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        ++in[y];
        ++out[x];
    }
    vector<int> ans;
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            dp[i] = 1;
            q.push(i);
        }
        if (!out[i]) ans.push_back(i);
    }
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto &y: g[x]) {
            dp[y] = (dp[y] + dp[x]) % MOD;
            if (--in[y] == 0) q.push(y);
        }
    }
    ll sum = 0;
    for (auto &x: ans) sum = (sum + dp[x]) % MOD;
    cout << sum;
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

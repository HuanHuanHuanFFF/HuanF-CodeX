//
// Created by 幻 on 2025/5/26.
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

// Codeforces Round  1027 (Div. 3) 
/* E. Kirei Attacks the Estate
 * link: https://codeforces.com/contest/2114/problem/E
 * 标签: 树上DP, 交替和, DFS
 * 思路:
 * 1. 树上DP：对每个节点维护 dp[i][0] 和 dp[i][1]，分别表示从节点 i 开始
 *    以“+damage[i]”和“-damage[i]”为首的最大交替和
 * 2. 初始条件：根节点 1：
 *    dp[1][0] = damage[1]
 *    dp[1][1] = -damage[1]
 * 3. 递推公式：对于节点 x 的子节点 y
 *    dp[y][0] = max(damage[y], damage[y] + dp[x][1])
 *    dp[y][1] = max(-damage[y], -damage[y] + dp[x][0])
 *    其中第一项表示只取自身，第二项表示在自身基础上延伸到父节点的最优
 * 4. 从根节点出发做一次 DFS，自顶向下计算所有 dp 值
 * 5. 每个节点的威胁值即 dp[i][0]
 * 时间复杂度 O(n)，空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> damage(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> damage[i];
    }
    vector g(n + 1, vector<int>());
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<std::array<ll, 2> > dp(n + 1);
    dp[1][0] = damage[1];
    dp[1][1] = -damage[1];
    auto dfs = [&](auto &&self, int x, int p)-> void {
        for (auto &y: g[x]) {
            if (y == p) continue;
            dp[y][0] = std::max(damage[y], damage[y] + dp[x][1]);
            dp[y][1] = std::max(-damage[y], -damage[y] + dp[x][0]);
            self(self, y, x);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << dp[i][0] << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

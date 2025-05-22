//
// Created by 幻 on 2025/5/20.
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
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* Infection-ProblemI
 * link: [无]
 * 思路:
 * 1 构建树并统计每个节点的度 deg[i]
 * 2 dfs1(x, p, d):
 *   - sum[x] = deg[x]
 *   - ans[1] 初始累加为 (n - dist(1,i)) * deg[i] 通过递归累加子节点 ans[x]
 *   - 计算后 sum[x] 为子树 deg 之和，ans[1] 为根节点完整答案
 * 3 dfs2(x, p): 重根转移
 *   - 对子节点 y:
 *       ans[y] = ans[x] + total - 2 * sum[y]
 *       其中 total = sum[1]
 *   - 更新时 sum[y] 不变
 * 4 收集所有 ans[i] 等于最大值的节点
 * 时间复杂度 O(n), 空间复杂度 O(n)
 */
void HuanF() {
    ll n;
    cin >> n;
    vector g(n + 1, vector<int>());
    vector<int> deg(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        ++deg[x];
        ++deg[y];
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<ll> ans(n + 1), sum(n + 1);
    // dfs1: 计算 sum 子树度和 和 ans[1]
    auto dfs1 = [&](auto &&self, int x, int p, ll d)-> void {
        sum[x] = deg[x];
        ans[x] = (n - d) * deg[x];
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self, y, x, d + 1);
            sum[x] += sum[y];
            ans[x] += ans[y];
        }
    };
    dfs1(dfs1, 1, 0, 0);

    // dfs2: 重根 DP 计算 ans[y]
    ll max = 0;
    auto dfs2 = [&](auto &&self, int x, int p)-> void {
        for (auto &y: g[x]) {
            if (y == p) continue;
            ans[y] = ans[x];
            ans[y] += sum[y];
            ans[y] -= sum[1] - sum[y];
            self(self, y, x);
        }
        max = std::max(max, ans[x]);
    };
    dfs2(dfs2, 1, 0);

    vector<int> answer;
    answer.reserve(n);
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == max) answer.push_back(i);
    }
    cout << answer.size() << "\n";
    for (auto x: answer) cout << x << " ";
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

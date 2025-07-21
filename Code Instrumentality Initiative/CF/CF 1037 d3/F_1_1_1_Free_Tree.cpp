//
// Created by 幻 on 2025/7/17.
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

// Codeforces Round 1037 (Div. 3) 
/* 2122E-Tree Recoloring Queries
 * link: https://codeforces.com/contest/2126/problem/E
 * 标签: 树·DFS·哈希映射·在线维护·复杂度优化
 * 思路:
 *   1 预累积: DFS 根化时对每条 u→v 边执行 cost[u][color[v]] += w，并累加异色边权至 sum
 *   2 查询重染 v→x:
 *     a old = color[v]
 *     b sum += cost[v][old]      // 子边同色→异色增量
 *     c sum -= cost[v][x]        // 子边异色→同色减量
 *     d 若 parent[v] 存在:
 *          if(color[parent[v]]==old) sum += pcost[v]
 *          if(color[parent[v]]==x)   sum -= pcost[v]
 *          更新父节点映射:
 *            cost[parent[v]][old] -= pcost[v]
 *            cost[parent[v]][x]   += pcost[v]
 *     e color[v] = x
 *   3 每次操作仅访问 O(1) 个映射条目，无需遍历全部邻居
 *   4 复杂度 O(n + q log n)
 * 时间复杂度 O(n + q log n)
 * 空间复杂度 O(n + m)
 */
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<vector<PII> > g(n + 1);
    vector<int> color(n + 1);
    for (int i = 1; i <= n; ++i) cin >> color[i];
    for (int i = 0, x, y, c; i < n - 1; ++i) {
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    std::map<int, std::map<int, ll> > cost;
    vector<int> parent(n + 1), pcost(n + 1);
    ll sum = 0;
    auto dfs = [&](auto &&self, int x, int p)-> void {
        for (auto &[y,c]: g[x]) {
            if (y == p) continue;
            cost[x][color[y]] += c;
            if (color[x] != color[y]) sum += c;
            pcost[y] = c;
            parent[y] = x;
            self(self, y, x);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 0, v, x; i < q; ++i) {
        cin >> v >> x;
        int old = color[v];
        if (x != old) {
            sum += cost[v][old];
            if (old == color[parent[v]])
                sum += pcost[v];
            sum -= cost[v][x];
            if (x == color[parent[v]]) sum -= pcost[v];
            cost[parent[v]][old] -= pcost[v];
            cost[parent[v]][x] += pcost[v];
            color[v] = x;
        }
        cout << sum << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

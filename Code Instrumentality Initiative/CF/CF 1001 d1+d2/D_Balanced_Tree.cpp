//
// Created by 幻 on 2025/6/20.
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

// Ethflow Round 1 (Codeforces Round 1001, Div. 1 + Div. 2) 
/* 2062D - Balanced Tree
 * link: https://codeforces.com/contest/2062/problem/D
 * 标签: 树 DP, DFS, 贪心
 * 思路: 以 1 为根，自底向上 DFS 递归计算每个节点的最小可行值 mx[x]，步骤：
 *   1. 初始化 mx[x]=l[x]
 *   2. 遍历子节点 y，递归计算后 mx[x]=max(mx[x], mx[y])
 *   3. 将 mx[x] 限制到 r[x] 上，即 mx[x]=min(mx[x], r[x])
 *   4. 对每个子节点统计需要的增量操作 d += max(0, mx[y] - mx[x])
 * 最终答案为 mx[1] + d
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    vector<int> mx(n + 1);
    ll d = 0;
    auto dfs = [&](auto &&self, int x, int p)-> void {
        mx[x] = l[x];
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self, y, x);
            mx[x] = std::max(mx[y], mx[x]);
        }
        mx[x] = std::min(r[x], mx[x]);
        for (auto &y: g[x])
            if (y != p)
                d += std::max(0, mx[y] - mx[x]);
    };
    dfs(dfs, 1, 0);

    cout << mx[1] + d << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

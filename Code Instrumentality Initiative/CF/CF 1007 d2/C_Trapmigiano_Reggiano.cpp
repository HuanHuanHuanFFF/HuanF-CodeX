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

// Codeforces Round 1007 (Div. 2) 
/* 2071C-树上抓鼠
 * link: https://codeforces.com/contest/2071/problem/C
 * 标签: 树、DFS、贪心
 * 思路:
 * 1 将树以陷阱顶点 en 根化
 * 2 DFS 计算所有节点深度即到 en 的距离
 * 3 按深度从大到小依次输出节点编号
 * 4 老鼠每次只能向深度相同或更小方向移动,因此最终停在深度 0 的 en
 * 时间复杂度 O(n),空间复杂度 O(n)
 */
void HuanF() {
    int n, st, en;
    cin >> n >> st >> en;
    vector g(n + 1, vector<int>());
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    vector<int> dep(n + 1);
    dep[en] = 0;
    auto dfs = [&](auto &&self, int x, int p)-> void {
        for (auto &&y: g[x]) {
            if (y == p) continue;
            dep[y] = dep[x] + 1;
            self(self, y, x);
        }
    };
    dfs(dfs, en, 0);

    vector bkt(std::ranges::max(dep) + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        bkt[dep[i]].emplace_back(i);
    }
    while (bkt.size()) {
        for (auto &&x: bkt.back()) {
            cout << x << " ";
        }
        bkt.pop_back();
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

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

// P1330 - 封锁阳光大学
// link: https://www.luogu.com.cn/problem/P1330
// 标签: 二分图, 染色, 顶点覆盖
/* 思路:
 * 1. 将校园看作无向图，节点为 1…n，道路为无向边。
 * 2. 每只河蟹放置在一个节点，相当于选定一个点集 S，使得每条边至少有一个端点在 S 上（S 是顶点覆盖 Vertex Cover）。
 *    同时要求 S 中任意两点**不**相邻（不能在相邻节点都放河蟹），即 S 是一个独立集 Independent Set。
 * 3. 在图论中，独立集的补集是顶点覆盖，最小顶点覆盖 = n - 最大独立集大小。
 *    由 König 定理：对于**二分图**，最小顶点覆盖大小 = 最大匹配大小。
 * 4. 因此：
 *    - 首先判断图是否是二分图（染色法，BFS/DFS 颜色交替，检测冲突）。
 *    - 对每个连通块，分别染色并统计两色节点数 cnt[0],cnt[1]。
 *      若遇冲突则输出 Impossible 并结束。
 *    - 对该块的最大独立集，取两色中**较大**者：max(cnt[0],cnt[1])。
 *    - 累加所有连通块的最大独立集大小，记为 D。
 *    - 最少需要的河蟹数 = n - D。
 * 时间复杂度: O(n + m) (染色+统计)，空间 O(n + m).
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int> color(n + 1, -1), cnt(2);
    auto dfs = [&](auto &&self, int x)-> bool {
        int c = color[x], nc = 1 - color[x];
        ++cnt[c];
        for (auto &y: g[x]) {
            if (color[y] == -1) {
                color[y] = nc;
                if (!self(self, y)) return false;
            } else if (color[y] == c) {
                return false;
            }
        }
        return true;
    };
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (color[i] != -1 || g[i].empty()) continue;
        cnt[0] = cnt[1] = 0;
        color[i] = 0;
        if (!dfs(dfs, i)) {
            cout << "Impossible";
            return;
        }
        ans += std::min(cnt[0], cnt[1]);
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

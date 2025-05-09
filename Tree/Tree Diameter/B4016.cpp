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

/* 树的直径 B4016
 * link: https://www.luogu.com.cn/problem/B4016
 * 思路:
 *   1 建图——用邻接表存储无向树
 *   2 第一次DFS——从节点1出发记录最远节点node
 *   3 第二次DFS——从node出发记录最大距离maxD即为直径
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int maxD = 0, node = 0;
    vector<int> dis(n + 1);
    auto dfs = [&](auto &&self, int x, int fa, int d)-> void {
        dis[x] = d;
        if (d > maxD) {
            maxD = d;
            node = x;
        }
        for (auto &y: g[x])
            if (y != fa) self(self, y, x, d + 1);
    };
    dfs(dfs, 1, 0, 0);
    maxD = 0;
    dfs(dfs, node, 0, 0);
    cout << maxD;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

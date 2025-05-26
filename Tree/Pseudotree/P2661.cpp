//
// Created by 幻 on 2025/5/25.
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

/* P2661 [NOIP 2015 提高组] 信息传递
 * link: https://www.luogu.com.cn/problem/P2661
 * 思路:
 * 每个同学只向一个人传递信息，图中每个点出度为1，形成若干个基环树
 *
 * Step1: 拓扑排序“撕链”
 * 将所有在树上的点（非环内）剥离掉，只留下若干个环（即拓扑排序剥掉所有入度为0的点）
 *
 * Step2: 遍历所有未访问点（即环中点），DFS求环长
 * 每个基环树中只有一个环，我们DFS即可求出环的长度，取所有环的最小值
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector g(n + 1, vector<int>());
    vector<int> in(n + 1);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        g[i].push_back(x);
        ++in[x];
    }
    std::queue<int> q;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            q.emplace(i);
            vis[i] = true;
        }
    }
    while (q.size()) {
        auto x = q.front();
        q.pop();
        for (auto &y: g[x]) {
            if (!--in[y]) {
                q.emplace(y);
                vis[y] = true;
            }
        }
    }
    int ans = INF;
    auto dfs = [&](auto &&self, int x, int d)-> void {
        vis[x] = true;
        bool tag = false;
        for (auto &y: g[x]) {
            if (!vis[y]) {
                self(self, y, d + 1);
                tag = true;
            }
        }
        if (!tag) ans = std::min(ans, d);
    };
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(dfs, i, 1);
    }
    cout << ans << "\n";
}

/*
 * 思路:
 * 功能图(每点出度=1)上标记遍历每个未处理节点i并记录路径下标
 * 遇到已处理节点u若在当前路径(idx[u]!=-1)则环长 = path.size() - idx[u]
 * 全局取最小
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF2() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        g[i].push_back(x);
    }
    vector<bool> done(n + 1, false);
    vector<int> idx(n + 1, -1);
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        if (done[i]) continue;
        vector<int> path;
        int u = i;
        while (!done[u]) {
            done[u] = true;
            idx[u] = path.size();
            path.push_back(u);
            u = g[u][0];
        }
        if (idx[u] != -1) {
            ans = std::min(ans, (int) path.size() - idx[u]);
        }
        for (int v: path) {
            idx[v] = -1;
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        // HuanF();
        HuanF2();
    return 0;
}

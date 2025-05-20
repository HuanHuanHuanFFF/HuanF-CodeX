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

/* 1915G-Bicycles
 * link: https://codeforces.com/problemset/problem/1915/G
 * 思路:
 * 1 状态定义 dist[u][k] 表示到达城市 u 时手持迟缓因子为 k 的最短时间
 * 2 初始化 dist[1][s[1]] = 0 并将 (1,s[1]) 入最小堆
 * 3 每次从堆中取出当前最小时间状态 (u,k)，若已访问或 dist[u][k]==INF 则跳过，否则标记访问
 * 4 遍历所有邻边 (u→v,w)，计算 nk = min(k, s[v]) 表示到 v 后可持有的最优自行车迟缓因子
 *   转移代价 = dist[u][k] + w * k，若更优则更新 dist[v][nk] 并将 (v,nk) 入堆
 * 5 最终答案 = min_{k=1..1000} dist[n][k]
 *
 * 时间复杂度 O(m·S·log(n·S))，其中 S = 最大迟缓因子 ≤1000，m,n≤1000 可接受
 * 空间复杂度 O(n·S)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > g[n + 1];
    vector<int> s(n + 1);
    vector dis(n + 1, vector<ll>(1001, INF));
    vector vis(n + 1, vector<bool>(1001, false));
    for (int i = 0, x, y, w; i < m; ++i) {
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    for (int i = 1; i <= n; ++i) cin >> s[i];
    std::priority_queue<std::array<ll, 3> > heap;
    dis[1][s[1]] = 0;
    heap.push({0, 1, s[1]});
    while (heap.size()) {
        auto [c,x,k] = heap.top();
        heap.pop();
        if (vis[x][k] || dis[x][k] == INF) continue;
        vis[x][k] = true;
        for (auto &[y,w]: g[x]) {
            int nk = std::min(s[y], static_cast<int>(k));
            if (dis[y][nk] > dis[x][k] + 1ll * w * k) {
                dis[y][nk] = dis[x][k] + 1ll * w * k;
                heap.push({-dis[y][nk], y, nk});
            }
        }
    }
    ll ans = INF;
    for (int i = 1; i <= 1000; ++i) {
        ans = std::min(ans, dis[n][i]);
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

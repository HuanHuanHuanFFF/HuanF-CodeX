//
// Created by 幻 on 2025/5/14.
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

/* Police Station
 * link: https://codeforces.com/problemset/problem/208/C
 * 思路:
 * 1 BFS 两次得到 dist1 与 distn 计算最短路长度 D
 * 2 对每条无向边 {u,v} 若满足 dist1[u]+1+distn[v]==D 或对称条件
 *   则定向为 u->v 构成最短路 DAG 同时建反向图
 * 3 在 DAG 上拓扑 DP
 *   - dp1[v] 统计 1→v 最短路条数
 *   - dpn[v] 统计 v→n 最短路条数
 * 4 对 DAG 中每条边 u->v 计算概率 p=dp1[u]*dpn[v]/dp1[n]
 *   将 p 加到端点 u 与 v 得到各城市期望安全边数
 * 5 枚举城市取最大期望输出
 * 时间复杂度: O(n+m)
 * 空间复杂度: O(n+m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<PII> edges(m);
    vector g(n + 1, vector<int>());
    for (auto &[x,y]: edges) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    auto bfs = [&](int s) {
        vector<int> dis(n + 1, 0);
        vector<bool> vis(n + 1);
        vis[s] = true;
        std::queue<int> q;
        q.push(s);
        while (q.size()) {
            auto x = q.front();
            q.pop();
            for (auto &y: g[x])
                if (!vis[y]) {
                    vis[y] = true;
                    q.push(y);
                    dis[y] = dis[x] + 1;
                }
        }
        return dis;
    };
    vector<int> dis1 = bfs(1);
    vector<int> disn = bfs(n);
    vector g2(n + 1, vector<int>()), g2r(n + 1, vector<int>());
    vector<int> in(n + 1), out(n + 1);
    int D = dis1[n];
    for (auto &[x,y]: edges) {
        if (dis1[x] + 1 == dis1[y] && dis1[x] + 1 + disn[y] == D)
            g2[x].push_back(y), ++in[y], g2r[y].push_back(x), ++out[x];
        if (dis1[y] + 1 == dis1[x] && dis1[y] + 1 + disn[x] == D)
            g2[y].push_back(x), ++in[x], g2r[x].push_back(y), ++out[y];
    }
    auto DP = [n](int s, vector<vector<int> > &g, vector<int> &in) {
        std::queue<int> q;
        vector<ll> dp(n + 1);
        dp[s] = 1;
        q.push(s);
        while (q.size()) {
            auto x = q.front();
            q.pop();
            for (auto &y: g[x]) {
                dp[y] += dp[x];
                if (--in[y] == 0)
                    q.push(y);
            }
        }
        return dp;
    };
    vector dp1 = DP(1, g2, in);
    vector dpn = DP(n, g2r, out);
    long double ans = 0;
    vector<long double> E(n + 1);
    for (auto &[x,y]: edges) {
        if (dis1[x] + 1 == dis1[y] && dis1[x] + 1 + disn[y] == D) {
            long double p = dp1[x] * dpn[y] / (long double) dp1[n];
            E[x] += p;
            E[y] += p;
        } else if (dis1[y] + 1 == dis1[x] && dis1[y] + 1 + disn[x] == D) {
            long double p = dp1[y] * dpn[x] / (long double) dp1[n];
            E[x] += p;
            E[y] += p;
        }
    }
    ans = *max_element(E.begin() + 1, E.end());
    printf("%.17Lf", ans);
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

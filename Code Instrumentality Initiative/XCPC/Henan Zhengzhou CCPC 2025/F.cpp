//
// Created by 幻 on 2025/6/7.
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

/* 2025CCPC-F
 * link: https://codeforces.com/gym/105941
 * 标签: BFS, 多源最短路, 网格
 * 思路:
 *   1. 忽略障碍，从起点(1,1)和终点(n,m)各自做一次DFS/BFS，分别得到起点可达集合 start 和 终点可达集合 end
 *   2. 将 start 中所有点作为多源 BFS 的初始队列（初始 dis=1），在“不考虑障碍”的网格上计算到任意点的最短距离 dis
 *   3. 对 end 中每个点 (x,y)，它到最近 start 点的步数为 dis[x][y]，由于初始值为1，去初始点要减2，因此答案即 min(dis[x][y]−2)
 * 时间复杂度: O(nm)
 * 空间复杂度: O(nm)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    vector dis(n, vector<int>(m));
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    auto bfs = [&](int sx, int sy) {
        std::queue<PII> q;
        vector<PII> block;
        q.emplace(sx, sy);
        dis[sx][sy] = 1;
        block.emplace_back(sx, sy);
        while (q.size()) {
            auto [x,y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !dis[nx][ny] && g[nx][ny] == '.') {
                    q.emplace(nx, ny);
                    dis[nx][ny] = 1;
                    block.emplace_back(nx, ny);
                }
            }
        }
        return block;
    };
    auto start = bfs(0, 0);
    auto end = bfs(n - 1, m - 1);
    for (auto &[x,y]: end) dis[x][y] = 0;
    std::queue<PII> q;
    for (auto &[x,y]: start) q.emplace(x, y);
    while (q.size()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !dis[nx][ny]) {
                q.emplace(nx, ny);
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
    int ans = INF;
    for (auto &[x,y]: end) ans = std::min(dis[x][y] - 2, ans);
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more)
        cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

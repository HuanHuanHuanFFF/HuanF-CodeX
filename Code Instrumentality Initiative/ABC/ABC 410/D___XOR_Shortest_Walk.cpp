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

constexpr bool more = false;

// AtCoder Beginner Contest 410 
/* D - XOR 最短路径
 * link: https://atcoder.jp/contests/abc410/tasks/abc410_d
 * 标签: BFS, 图论, 状态拓展, 按位异或
 * 思路:
 * 将原图中每个顶点 x 扩展为状态 (x, s)，其中 s 表示从 1 到 x 的路径 XOR 值
 * 在隐式状态图上从 (1,0) 开始做 BFS，状态转移：(x,s) --(边 x→y, 权重 w)--> (y, s⊕w)
 * BFS 结束后，枚举 s=0..1023，第一个 vis[N][s] 为 true 即为最小 XOR，若无则 -1
 * 时间复杂度: O((N+M) * 1024)
 * 空间复杂度: O(N * 1024)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII> > g(n + 1);
    for (int i = 0, x, y, w; i < m; ++i) {
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
    }
    vector vis(n + 1, vector<bool>(1 << 10 | 1));
    vis[1][0] = true;
    std::queue<PII> q;
    q.emplace(1, 0);
    while (q.size()) {
        auto [x,d] = q.front();
        q.pop();
        for (auto &[y,w]: g[x]) {
            if (!vis[y][d ^ w]) {
                vis[y][d ^ w] = true;
                q.emplace(y, d ^ w);
            }
        }
    }
    for (int i = 0; i <= 1 << 10; ++i) {
        if (vis[n][i]) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

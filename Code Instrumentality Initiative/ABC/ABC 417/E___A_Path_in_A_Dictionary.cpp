//
// Created by 幻 on 2025/8/2.
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = true;

// AtCoder Beginner Contest 417 
/* ABC417-E
 * link: https://atcoder.jp/contests/abc417/tasks/abc417_e
 * 标签: 最小字典序, 简单路径, DFS, 贪心
 * 思路: 将邻接表按编号升序排序后深搜
 *       DFS 每次优先走编号最小的未访问邻居
 *       由于第一次到达某点时前缀已最小 且 全局 vis 禁止再次访问
 *       故找到终点的那条路径即为字典序最小的简单路径
 *       找到终点即可回溯输出路径
 * 时间复杂度: O(N+M)
 * 空间复杂度: O(N+M)
 */
void HuanF() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        std::ranges::sort(g[i]);
    }
    vector<bool> vis(n + 1, false);
    vector<int> ans;
    ans.reserve(n + 1);
    auto dfs = [&](auto &&self, int x)-> bool {
        if (x == end) {
            ans.emplace_back(x);
            return true;
        }
        vis[x] = true;
        for (auto &y: g[x]) {
            if (!vis[y])
                if (self(self, y)) {
                    ans.emplace_back(x);
                    return true;
                }
        }
        return false;
    };
    dfs(dfs, start);
    for (auto x: std::views::reverse(ans)) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

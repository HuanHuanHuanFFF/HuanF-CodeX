//
// Created by 幻 on 2026/10/22.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

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

/* CF1611-E2 - Escape The Maze (hard version)
 * link: https://codeforces.com/contest/1611/problem/E2
 * 标签: 树, 多源 BFS, DFS, 贪心, 剪枝计数
 * 思路: 多源 BFS 求最近朋友距离, 从根搜索首次满足 dis[x] <= 深度的位置。
 * 每遇到一个拦截点便计数并停止向下, 其子树由一个朋友封住; 若能逃到叶子则输出 -1。
 * 时间复杂度: O(n), 空间复杂度: O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> friends(k);
    for (auto &x: friends) cin >> x;
    vector g(n + 1, vector<int>());
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    vector<int> dis(n + 1, -1);
    for (auto &x: friends)
        dis[x] = 0;
    vector<int> queue(friends);
    int d = 0;
    while (!queue.empty()) {
        vector<int> nqueue;
        ++d;
        for (auto &x: queue)
            for (auto &y: g[x]) {
                if (dis[y] != -1) continue;
                dis[y] = dis[x] + 1;
                nqueue.emplace_back(y);
            }
        queue = std::move(nqueue);
    }

    vector<bool> vis(n + 1);
    int ans = 0;
    auto dfs = [&](int x, int di, auto &&self)-> bool {
        vis[x] = true;
        if (dis[x] <= di) {
            ++ans;
            return false;
        }
        bool leaf = true;
        for (auto &y: g[x]) {
            if (!vis[y]) {
                if (self(y, di + 1, self)) return true;
                leaf = false;
            }
        }
        if (leaf) return true;
        return false;
    };

    cout << (dfs(1, 0, dfs) ? -1 : ans) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

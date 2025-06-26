//
// Created by 幻 on 2025/6/23.
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

// Educational Codeforces Round 180 (Rated for Div. 2)
/* 2112D- Reachability and Tree
 * link: https://codeforces.com/contest/2112/problem/D
 * 标签: 树, 构造, DFS
 * 思路:
 *  1 找到度为2的节点 root, 删除后分两棵子树, 若没有则无解
 *  2 分别从 root 的两条边起点 do 交替 DFS, 使得两棵子树节点交替染色
 *  3 对每条边 (x,y), 保证输出时 col[x]==1,col[y]==0, 输出 x->y
 * 时间复杂度 O(n), 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 2) {
            root = i;
            break;
        }
    }
    if (root == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    auto dfs = [&](auto &&self, int x, int p, bool dir)-> void {
        if (dir) {
            cout << x << " " << p << "\n";
        } else cout << p << " " << x << "\n";
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self, y, x, !dir);
        }
    };
    dfs(dfs, g[root][0], root, true);
    dfs(dfs, g[root][1], root, false);
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

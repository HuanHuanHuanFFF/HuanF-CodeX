#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* ABC404-C
 * link: https://atcoder.jp/contests/abc404/tasks/abc404_c
 * 思路:
 * 1 检查 M 是否等于 N, 若不等 则输出 No
 * 2 计算并检查每个顶点度数是否均为 2, 若存在不为 2 则输出 No
 * 3 从顶点 1 开始 DFS 判断是否所有顶点均被访问, 若未全部访问 则输出 No
 * 连通且 2-正则的简单图必为单一环
 * 时间复杂度 O(N+M)
 * 空间复杂度 O(N+M)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    if (n != m) {
        cout << "No\n";
        return;
    }
    vector g(n + 1, vector<int>());
    vector<int> deg(n + 1);
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        ++deg[x];
        ++deg[y];
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] != 2) {
            cout << "No\n";
            return;
        }
    }

    vector<bool> vis(n + 1);
    auto dfs = [&](auto &&self, int x, int fa)-> void {
        if (vis[x]) return;
        vis[x] = true;
        for (auto &y: g[x]) {
            if (y == fa) continue;
            self(self, y, x);
        }
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

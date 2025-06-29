//
// Created by 幻 on 2025/5/22.
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

/* P3047-Nearby Cows G
 * link: https://www.luogu.com.cn/problem/P3047
 * 思路:
 * 1 下DP: dfs1(x,p) 计算 down[x][d] 表示子树内恰好 d 步的权重和
 * 2 重根DP: dfs2(x,p) 计算 up[y][d] 表示除自身子树外恰好 d 步的权重和
 * 3 合并答案: 对每个 x 累加 down[x][0..k] + up[x][0..k] 即为 M(x)
 * 时间复杂度 O(n·k) 空间复杂度 O(n·k)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector g(n + 1, vector<int>()); // 邻接表
    vector<int> w(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i]; // 节点权重
    }
    vector down(n + 1, vector<ll>(k + 1)), up(n + 1, vector<ll>(k + 1));

    // dfs1 下 DP 计算 down[x][d]
    auto dfs1 = [&](auto &&self, int x, int p)-> void {
        down[x][0] = w[x]; // 自身贡献
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self, y, x);
            for (int d = 0; d < k; ++d) {
                down[x][d + 1] += down[y][d]; // 累加子树深度为 d 的贡献
            }
        }
    };
    dfs1(dfs1, 1, 0);

    // dfs2 重根 DP 计算 up[y][d]
    auto dfs2 = [&](auto &&self, int x, int p)-> void {
        for (auto &y: g[x]) {
            if (y == p) continue;
            up[y][1] = w[x]; // 距离1 只能是父节点权重
            for (int d = 2; d <= k; ++d) {
                ll a = up[x][d - 1]; // 先走到 x 再向上 d-1 步
                ll b = down[x][d - 1] // x 向下 d-1 步所有贡献
                       - down[y][d - 2]; // 去掉回到 y 子树的部分
                up[y][d] = a + b; // 合并向上和向兄弟子树的贡献
            }
            self(self, y, x);
        }
    };
    dfs2(dfs2, 1, 0);

    // 合并 down 和 up 得到最终答案
    vector<ll> ans(n + 1);
    for (int x = 1; x <= n; ++x) {
        for (int d = 0; d <= k; ++d) {
            ans[x] += down[x][d] + up[x][d];
        }
        cout << ans[x] << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

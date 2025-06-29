//
// Created by 幻 on 2025/5/21.
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
constexpr int INF = 1e9 + 17;
constexpr int N = 3007;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* P1273-有线电视网
 * link: https://www.luogu.com.cn/problem/P1273
 * 思路:
 * 1 树形DP 定义 f[x][j] 为 以 x 为根的子树 恰选 j 个用户 的最大净收益
 * 2 叶子节点（用户）初始化 f[x][0]=0, f[x][1]=money[x] 并设 sz[x]=1
 * 3 对于每个内部节点 x，遍历其子节点 y，先递归 dfs(y)
 *   然后用「倒序背包(01背包)」将 y 的状态合并到 x：
 *   for j=sz[x]…0, for k=1…sz[y]:
 *     f[x][j+k]=max(f[x][j+k], f[x][j]+f[y][k]−cost_xy)
 *   合并后更新 sz[x]+=sz[y]
 * 4 最终在根节点 1 的 f[1][j] 中，最大满足 f[1][j]≥0 的 j 即为答案
 * 时间复杂度 O(m^2) m 为用户数  空间复杂度 O(n·m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector child(n + 1, vector<PII>());
    vector<int> money(n + 1);
    vector f(n + 1, vector<ll>(N, -INF));
    for (int i = 1, k; i <= n - m; ++i) {
        cin >> k;
        for (int j = 0, x, y; j < k; ++j) {
            cin >> x >> y;
            child[i].emplace_back(x, y);
        }
    }
    for (int i = n - m + 1; i <= n; ++i) {
        cin >> money[i];
    }
    vector<int> sz(n + 1, 0);
    auto dfs = [&](auto &&self, int x)-> void {
        f[x][0] = 0;
        if (child[x].empty()) {
            sz[x] = 1;
            f[x][1] = money[x];
            return;
        }
        for (auto &[y, w]: child[x]) {
            self(self, y);
            for (int j = sz[x]; j >= 0; --j) {
                if (f[x][j] <= -INF / 2) continue;
                for (int k = 1; k <= sz[y]; ++k) {
                    if (f[y][k] <= -INF / 2) continue;
                    f[x][j + k] = std::max(f[x][j + k], f[x][j] + f[y][k] - w);
                }
            }
            sz[x] += sz[y];
        }
    };
    dfs(dfs, 1);
    for (int i = N - 1; i >= 0; --i) {
        if (f[1][i] >= 0) {
            cout << i;
            return;
        }
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

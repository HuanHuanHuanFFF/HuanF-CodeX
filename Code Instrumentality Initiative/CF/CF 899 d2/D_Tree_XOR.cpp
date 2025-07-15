//
// Created by 幻 on 2025/7/14.
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

// Codeforces Round 899 (Div. 2) 
/* 1882D-1882D
 * link: https://codeforces.com/contest/1882/problem/D
 * 标签: 树, 重根DP, 异或运算
 * 思路:
 *   1. 将 a_v⊕a_par(v) 视为边权，先以 1 为根 dfs1 计算：
 *      sz[v]=v 的子树大小，cost[v]=a[v]⊕a[p]
 *      ans[1]=∑_{v=2..n} sz[v]*cost[v]
 *   2. 重根转移：若将根从 u 换到相邻 v，令 w=cost[v]，
 *      原贡献 sz[v]*w，变为 (n-sz[v])*w，
 *      ans[v]=ans[u] - sz[v]*w + (n-sz[v])*w
 *   3. dfs2 遍历所有 v 即可算出 ans[v]
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<ll> cost(n + 1), sz(n + 1, 1);
    auto dfs1 = [&](auto &&self, int x, int p)-> void {
        cost[x] = a[x] ^ a[p];
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self, y, x);
            sz[x] += sz[y];
        }
    };
    dfs1(dfs1, 1, 0);
    vector<ll> ans(n + 1);
    for (int i = 2; i <= n; ++i) {
        ans[1] += sz[i] * cost[i];
    }
    auto dfs2 = [&](auto &&self, int x, int p)-> void {
        for (auto &y: g[x]) {
            if (y == p) continue;
            ans[y] = ans[x] + (n - 2 * sz[y]) * cost[y];
            self(self, y, x);
        }
    };
    dfs2(dfs2, 1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

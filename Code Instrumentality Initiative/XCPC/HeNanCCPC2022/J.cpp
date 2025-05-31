//
// Created by 幻 on 2025/5/12.
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

/* Problem: J. Mex Tree
 * link: https://codeforces.com/gym/103941
 * 标签: 树, 子树最小值, DFS, Mex
 * 思路:
 *   1. 根据题意，当 mex=k 时，选择的连通子图不能包含权值为 k 的节点以及其子树中所有节点。
 *   2. 对于 k=n，直接整棵树都满足，答案为 n。
 *   3. 当 k<i<n 时，先找到权值为 0 的节点作为根 root，其他 k>0 的情况统一按下述步骤处理：
 *      a. 从根出发做一次 DFS，计算每个节点 x 的子树大小 sz[x]，并返回子树内的最小权值 mi[x]。
 *      b. 如果节点 y 的权值 w[y]=k 且它的子树内最小权值 mi[y] > k，说明子树内没有任何权值 < k 的冲突节点，此时去掉 y 的子树后，剩余节点数 n−sz[y] 即为 mex=k 时最大连通子图的节点数；否则该 k 对应答案为 0。
 *   4. 对于 k=0：任意连通子图都不能包含根自身（权值为 0），因此答案为其每个子树 sz[y] 的最大值。
 *   5. 最后，将所有 mex=i（i=0,1,…,n）对应的 ans[i] 输出即可。
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector g(n + 1, vector<int>());
    vector<int> w(n + 1);
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        if (w[i] == 0) root = i;
    }
    for (int i = 2, x; i <= n; ++i) {
        cin >> x;
        g[x].emplace_back(i);
        g[i].emplace_back(x);
    }
    vector<int> sz(n + 1), ans(n + 1);
    auto dfs = [&](auto &&self, int x, int p)-> int {
        sz[x] = 1;
        int mi = w[x];
        for (auto &y: g[x]) {
            if (y == p) continue;
            mi = std::min(self(self, y, x), mi);
        }
        sz[p] += sz[x];
        if (mi == w[x]) ans[w[x]] = n - sz[x];
        return mi;
    };
    dfs(dfs, root, 0);

    for (auto &y: g[root])
        ans[0] = std::max(sz[y], ans[0]);

    ans[n] = n;
    for (auto &x: ans) cout << x << " ";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

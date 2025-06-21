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

constexpr bool more = true;

// Ethflow Round 1 (Codeforces Round 1001, Div. 1 + Div. 2) 
/* 2062E1 - The Game (Easy Version)
 * link: https://codeforces.com/contest/2062/problem/E1
 * 标签: 树, 欧拉序 (Euler Tour), 前缀后缀最值, 博弈
 * 思路:
 *   1. 利用树的 **Euler Tour**（只记录进入时间）对每个节点做 DFS，得到进入时间 tin[u] 和出时间 tout[u]，并在 order[tin]=u 建序列映射。
 *   2. 子树在 Euler 序中对应连续区间 [tin[u], tout[u]]，子树外即前后两段序列。
 *   3. 构造序列的前缀最大 pre[i]=max(pre[i-1], w[order[i]])，后缀最大 suf[i]=max(suf[i+1], w[order[i]])。
 *   4. 对每个节点 u，检查子树外是否存在权值更大的节点：
 *        if max(pre[tin[u]-1], suf[tout[u]+1]) > w[u]，则 u 为合法起点。
 *   5. 为保证对手无路可走，Cirno 应选取合法节点中 w[u] 最大者，输出其编号。
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    vector<int> pre(n + 1), suf(n + 2), tin(n + 1), tout(n + 1), order(n + 1);
    int t = 0;
    auto dfs = [&](auto &&self, int x, int p)-> void {
        tin[x] = ++t;
        order[t] = x;
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self, y, x);
        }
        tout[x] = t;
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; ++i) {
        pre[i] = std::max(pre[i - 1], w[order[i]]);
    }
    for (int i = n; i > 0; --i) {
        suf[i] = std::max(suf[i + 1], w[order[i]]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (std::max(pre[tin[i] - 1], suf[tout[i] + 1]) > w[i] && w[i] > w[ans])
            ans = i;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/7.
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

/* M. 川陀航空学院
 *
 * 题意：
 *   给定 n 个节点、m 条无向边（可能重复或自环），想通过最少的 “增加/删除” 边操作使图变成一棵树。
 *   一棵树要求恰好 n−1 条边且连通无环。
 * 解法思路：
 *   - 使用并查集（DSU）统计多余边和连通分量数量。
 *   - 遍历每条输入边 (x,y)：若 x,y 已在同一集合，则说明该边是环（冗余），需要删除，ans++。否则合并它们。
 *   - 遍历 1..n，如果 i 是根节点（p[i]==i），表示一个连通分量，计数 comp++。
 *   - 要让 comp 个分量变成一棵树，需要删除所有环边（ans 已统计），再添加 (comp−1) 条桥边把分量连通：
 *       总操作数 = 多余边数 + (comp − 1)
 *   - 输出 ans + (comp − 1)；此处代码先把 ans += comp，最后输出 ans − 1。
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1), rank(n + 1, 0);
    std::ranges::iota(p, 0);
    auto find = [&](auto &&self, int x)-> int {
        return p[x] == x ? x : p[x] = self(self, p[x]);
    };
    auto merge = [&](int x, int y) {
        int xp = find(find, x), yp = find(find, y);
        if (rank[xp] > rank[yp]) p[yp] = xp;
        else if (rank[xp] < rank[yp]) p[xp] = yp;
        else {
            ++rank[xp];
            p[yp] = xp;
        }
    };
    int ans = 0;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        if (find(find, x) == find(find, y)) {
            ++ans;
        } else merge(x, y);
    }
    for (int i = 1; i <= n; ++i) {
        if (p[i] == i) ++ans;
    }
    cout << ans - 1;
}

signed main() {
    init();
    int T = 1;
    if (more)
        cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

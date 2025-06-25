//
// Created by 幻 on 2025/6/24.
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

// Codeforces Round 1000 (Div. 2) 
/* 2063C
 * link: https://codeforces.com/contest/2063/problem/C
 * 标签: 树 贪心 度数
 * 思路:
 * 1. 遍历所有边, 统计每个顶点的度 deg[i], 找到最大度 maxDeg
 *   并将所有 deg[i]==maxDeg 的顶点存入 mxdeg 列表
 * 2. 设 ans = maxDeg - 1
 * 3. 对 mxdeg 中的前两个顶点 ux:
 *    - 遍历所有其他顶点 v (v != ux)
 *    - 计算 sz = deg[v] - (g[v] 包含 ux ? 1 : 0)
 *    - 更新 ans = max(ans, (maxDeg - 1) + sz)
 * 4. 输出 ans
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<std::set<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace(y);
        g[y].emplace(x);
    }
    vector<bool> vis(n + 1);
    int max = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() >= max) {
            max = g[i].size();
        }
    }
    vector<int> mxdeg;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == max)
            mxdeg.emplace_back(i);
    }
    int ans = max - 1;
    for (int x = 0; x < std::min(2, (int) mxdeg.size()); ++x) {
        for (int i = 1; i <= n; ++i) {
            if (i == mxdeg[x]) continue;
            int sz = g[i].size() - g[i].contains(mxdeg[x]);
            ans = std::max(ans, max - 1 + sz);
        }
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

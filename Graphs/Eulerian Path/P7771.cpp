//
// Created by 幻 on 2025/5/26.
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

/* P7771 【模板】欧拉路径
 * link: https://www.luogu.com.cn/problem/P7771
 * 标签: 欧拉路径,Hierholzer,有向图,字典序,dfs
 * 思路:
 * 1. 入度出度检查 & 起点选择
 *    - 统计每个顶点 in[u], out[u]
 *    - 若有超过两个顶点满足 |out[u]-in[u]|>1，则无解
 *    - 若恰有一个 out-in=1 的顶点，则选它为 start；否则任选四边顶点
 * 2. 邻接表排序
 *    - 对每个 u，将所有 g[u] 按降序排序，保证 pop_back() 取到最小的 v
 *    - 这样保证每次贪心选择最小编号的下一跳，实现字典序最小
 * 3. Hierholzer 深度遍历
 *    dfs(u):
 *      while g[u] 非空:
 *        v = g[u].back(); g[u].pop_back();
 *        dfs(v);
 *      ans.emplace_back(u);
 *    - 回溯时记录顶点序列，最终逆序 ans 得到完整欧拉路径
 * 4. 输出
 *    - 若 ans 长度 != m+1，可届时检查无解；否则直接打印序列
 *
 * 时间复杂度: O(n + m log m) （排序）或 O(n + m)
 * 空间复杂度: O(n + m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    vector<int> in(n + 1), out(n + 1);
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        ++in[y];
        ++out[x];
    }
    int cnt1 = 0, cnt2 = 0, start = 1;
    for (int i = 1; i <= n; ++i) {
        if (in[i] != out[i]) {
            if (out[i] - in[i] == 1) {
                start = i;
                if (++cnt1 > 1) {
                    cout << "No";
                    return;
                }
            } else if (in[i] - out[i] == 1) {
                if (++cnt2 > 1) {
                    cout << "No";
                    return;
                }
            } else {
                cout << "No";
                return;
            }
        }
    }
    vector<int> ans;
    ans.reserve(2 * m);
    for (int i = 1; i <= n; ++i) std::sort(g[i].begin(), g[i].end(), std::greater<>());
    auto dfs = [&](auto &&self, int x)-> void {
        while (g[x].size()) {
            auto y = g[x].back();
            g[x].pop_back();
            self(self, y);
        }
        ans.emplace_back(x);
    };
    dfs(dfs, start);
    std::reverse(ans.begin(), ans.end());
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

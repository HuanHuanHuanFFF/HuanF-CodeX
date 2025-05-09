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

/* D. Apple Tree Traversing
 * link: https://codeforces.com/contest/2107/problem/D
 * 思路:
 * 1 维护 used[] 标记已摘除节点 和 seen[] 标记本轮已访问节点
 * 2 外层循环直到所有节点都 used 为止
 *    a 对每个连通分量的根 i 执行两次 DFS 求直径
 *    b 第一次 DFS 从 i 找最远节点 x
 *    c 第二次 DFS 从 x 找最远节点 y 及长度 d
 *    d 将 (d,max(x,y),min(x,y)) 保存在 ans
 *    e 通过 parent 数组从 y 回溯到 x 标记沿途节点 used=true
 * 3 重复处理所有分量
 * 时间复杂度 O(n * sqrt(n)) 或 O(n log n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    vector<std::tuple<int, int, int> > ans;
    vector<bool> used(n + 1), seen(n + 1);
    vector<int> p(n + 1, -1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    while (true) {
        if (std::count(used.begin() + 1, used.end(), false) == 0) break;
        std::fill(seen.begin(), seen.end(), false);

        auto dfs = [&](auto &&self, int x, int fa)-> PII {
            p[x] = fa;
            seen[x] = true;
            PII best = {1, x};
            for (auto &y: g[x]) {
                if (y == fa || used[y]) continue;
                auto res = self(self, y, x);
                ++res.first;
                best = std::max(best, res);
            }
            return best;
        };

        for (int i = 1; i <= n; ++i) {
            if (!used[i] && !seen[i]) {
                auto [d1,x] = dfs(dfs, i, -1);
                auto [d2,y] = dfs(dfs, x, -1);
                ans.emplace_back(d2, std::max(x, y), std::min(x, y));

                while (y != -1) {
                    used[y] = true;
                    y = p[y];
                }
            }
        }
    }
    std::sort(ans.begin(), ans.end(), std::greater<>());
    for (auto [d,x,y]: ans) cout << d << " " << x << " " << y << " ";
    cout << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

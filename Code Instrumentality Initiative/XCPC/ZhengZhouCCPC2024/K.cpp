#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 998244353;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 * 题目：树上问题
 * 前置知识：树的深度优先遍历（DFS）；树形 DP；重根 DP（Reroot DP）
 * 思路（遵循奥卡姆剃刀与模块化原则）：
 * 1. **什么**：给定一棵无根树和每个节点的权值，若将节点 u 作为根，则要求每条父→子边满足 子权 ≥ 父权/2。统计满足条件的所有根节点数。
 * 2. **为什么**：对每个节点逐一构建并检查 O(n²) 会超时。通过一次子树 DFS 累计违规边数，再利用重根技巧从父节点结果 O(1) 推导子节点结果，可在 O(n) 内完成。
 * 3. **怎么做**：
 *    - **第一次 DFS（固定根 1）**：计算 `cnt[x]`，表示以 x 为根的子树内的总违规边数。
 *    - **第二次 DFS（重根 DP）**：以 `ans[x]` 为基础，只调整边 x→y 的违规状态来得到 `ans[y]`。
 *    - **统计**：遍历 `ans[i]`，计数为 0 的节点即为“美丽节点”。
*/
void HuanF() {
    int n;
    cin >> n;
    // 邻接表 g 存储树，节点编号 1..n
    vector<vector<int> > g(n + 1);
    vector<int> ans(n + 1), cnt(n + 1), a(n + 1);

    // 1. 读入每个节点的权值
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 2. 读入 n-1 条边，构造无向树
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // 第一次 DFS：计算每个子树的违规边数 cnt[x]
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        for (auto &y: g[x]) {
            if (y == fa) continue; // 跳过父节点，避免回溯
            self(self, y, x);
            // a[y]*2 < a[x] 则 x→y 边违规
            cnt[x] += cnt[y] + (a[y] * 2 < a[x]);
        }
    };

    // 第二次 DFS：重根 DP，通过 ans[x] 推导 ans[y]
    auto DFS = [&](auto &&self, int x, int fa) -> void {
        for (auto &y: g[x]) {
            if (y == fa) continue;
            // 从 x 换根到 y：
            // 1) 减掉原来 x→y 边在 ans[x] 中的违规 (若 a[y]*2 < a[x])
            // 2) 加上新边 y→x 的违规 (若 a[x]*2 < a[y])
            ans[y] = ans[x]
                     - (a[y] * 2 < a[x])
                     + (a[x] * 2 < a[y]);
            self(self, y, x);
        }
    };

    // 执行两次 DFS：
    dfs(dfs, 1, 0); // cnt 计算完毕
    ans[1] = cnt[1]; // 根为 1 时的总违规边数
    DFS(DFS, 1, 0); // 计算所有节点为根时的违规边数 ans[i]

    // 统计 ans[i]==0 的节点数量
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 0) ++tot;
    }
    cout << tot << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

/*
3
 3
 1 2 3
 1 2
 2 3
 5
 3 2 2 2 1
 1 2
 3 1
 4 1
 1 5
 8
 699 673 592 276 600 343 369 374
 7 6
 8 5
 4 6
 7 1
 7 2
 1 8
 4 3
 */

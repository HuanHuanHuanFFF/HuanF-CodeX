#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 1946C – Tree Cutting
// Link: https://codeforces.com/problemset/problem/1946/C
// 思路：
// 1. 单调性（Monotonicity）
//    - 对树按每块 ≥ m 时切割,可以切出 ≥ k+1 个子树块，则可行。
//    - 对于任意更小的 m′ < m，这些块依然满足大小 ≥ m′，块数不会减少。
//    - 因此“可行性”关于 m 是单调的，允许使用二分查找最大 m。
//
// 2. 贪心切断（Greedy Cut）
//    - 在自底向上的 DFS 中，一旦某个子树累计节点数 sz ≥ m，
//      立即“切断”这条子树（cuts++），并返回 0。
//    - 这样做的理由：
//      a) 最早摘下满足条件的子树能为剩余树结构腾出最多节点，
//         增加其他区域形成更多块的可能性；
//      b) 如果不立即切断，而是让 sz 继续向上传递，
//         可能浪费多余节点在一个大块里，减少可切块的总数。
//
// 3. 状态重置（Reset State）
//    - 切断后返回 0，表示这部分节点已独立成块，
//      不再参与上层的 sz 累计，保证每个节点只归属于一个块，避免重复计数。
//
// 4. 时间复杂度（Efficiency）
//    - 单次 check(m) 做一次 O(n) 的 DFS。
//    - 二分 m 在 [1, n] 内进行约 O(log n) 步。
//    - 总体复杂度 O(n·log n)，满足 n ≤ 10^5 的规模要求。
void HuanF() {
    int n, k, cuts = 0;
    cin >> n >> k;
    vector g(n + 1, vector<int>());
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    auto dfs = [&](auto &self, int m, int x, int fa)-> int {
        int sz = 1;
        for (auto &y: g[x]) {
            if (y != fa)
                sz += self(self, m, y, x);
        }
        if (sz >= m) {
            ++cuts;
            return 0;
        }
        return sz;
    };

    auto check = [&](int x) {
        cuts = 0;
        dfs(dfs, x, 1, 0);
        return cuts >= k + 1;
    };

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
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

//
// Created by 幻 on 2025/8/8.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = false;

// OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
/* E - 树的路径分解
 * link: https://atcoder.jp/contests/abc397/tasks/abc397_e
 * 标签: 树, DFS, 贪心, 子树规模, 路径分解判定
 * 思路:
 * 定义 s_v 为以 v 为根的子树在尽量删去若干条长度为 k 的路径后剩余的节点数 0..k-1
 * 叶子 s_v=1; 对每个儿子 u 取返回 t=s_u 累加到 s_v, 记 c_v=子树内 t>0 的儿子个数
 * 判定三条充要约束:
 * 1) 若 s_v>k 则不可能
 * 2) 若 c_v>=3 则不可能 因为路径度数≤2
 * 3) 若 s_v<k 且 c_v>=2 则不可能 因路径需经过父边 使度数≥3
 * 若 s_v==k 则该子树恰能形成一条长度 k 的路径 将 s_v 置 0
 * 返回 s_v=k?0:s_v; 根返回 0 则可完全分解 输出 Yes 否则 No
 * 证明概述:
 * - t>0 表示一条“未闭合”的部分路径需要穿过 v 向上延伸; 任一点在所有路径中的度数≤2
 * - 因此 c_v≥3 或 s_v<k 且 c_v≥2 均违反度数约束; s_v==k 则能在 T_v 内闭合并删除
 * 时间复杂度: O(nk) 其中 nk 为节点总数
 * 空间复杂度: O(nk)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n * k + 1, 1);
    vector<vector<int> > g(n * k + 1);
    for (int i = 0, x, y; i < n * k - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    auto dfs = [&](auto &&self, int x, int p)-> int {
        int cnt = 0;
        for (auto &y: g[x]) {
            if (y == p) continue;
            int t = self(self, y, x);
            if (t == -1) return -1;
            dp[x] += t;
            if (t) ++cnt;
        }
        if (dp[x] > k || cnt > 2 || (dp[x] < k && cnt > 1)) return -1;
        return dp[x] % k;
    };
    auto x = dfs(dfs, 1, 0);
    if (x == 0) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

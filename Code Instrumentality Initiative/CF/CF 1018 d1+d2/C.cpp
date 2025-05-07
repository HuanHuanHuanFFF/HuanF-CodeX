#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;
using std::min;
using std::array;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e15 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* C. Wonderful City 2096C
 * link: https://codeforces.com/contest/2096/problem/C
 * 思路:
 *   1. 将行操作和列操作对水平冲突与垂直冲突的影响独立开来。
 *   2. 定义 dp[i][x] 表示处理到第 i 行，x=0/1 表示对该行不做/做加1操作的最小成本。
 *   3. 转移时枚举上一行状态 y，检查每列 j: h[i-1][j]+y != h[i][j]+x，若全不等则合法转移。
 *   4. 初始 dp[1][0]=0, dp[1][1]=cost[1]。最终取 min(dp[n][0], dp[n][1])。
 *   5. 对水平冲突，将矩阵转置后同样做上述行 DP。
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n^2)
 */
void HuanF() {
    int n;
    cin >> n;
    vector h(n + 1, vector<int>(n + 1));
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> h[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    // 行 DP 函数: 消除垂直相等冲突
    auto DP = [](int n, const vector<vector<int> > &h, const vector<ll> &cost) {
        // dp[i][x]: 处理到第 i 行，x=0/1 表示第 i 行不/做操作，加1后最小成本
        vector<array<ll, 2> > dp(n + 1, {INF, INF});
        dp[1][0] = 0; // 不对第1行操作，成本0
        dp[1][1] = cost[1]; // 对第1行操作，成本 cost[1]

        // 从第2行开始，逐行计算
        for (int i = 2; i <= n; ++i) {
            array<ll, 2> ndp = {INF, INF};
            // x = 是否对第 i 行加 1
            for (int x = 0; x < 2; ++x) {
                // y = 是否对第 i-1 行加 1
                for (int y = 0; y < 2; ++y) {
                    bool ok = true;
                    // 检查第 i-1 行与第 i 行在所有列 j 上，加 y 和 x 后是否都不相等
                    for (int j = 1; j <= n; ++j) {
                        if (h[i - 1][j] + y == h[i][j] + x) {
                            ok = false; // 发现冲突，不能同时选 y, x
                            break;
                        }
                    }
                    if (!ok) continue; // 有冲突则跳过此状态组合
                    // 合法转移：累加前一行 dp 和当前行操作成本（若 x=1）
                    ndp[x] = min(ndp[x], dp[i - 1][y] + (x ? cost[i] : 0));
                }
            }
            dp[i] = ndp; // 更新到第 i 行的最优
        }
        // 返回最后一行不/做操作的最优
        return min(dp[n][0], dp[n][1]);
    };

    ll cost = DP(n, h, a);

    // 转置矩阵，处理水平冲突
    vector<vector<int> > th = h;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            std::swap(th[i][j], th[j][i]);
        }
    }

    cost += DP(n, th, b);
    cout << (cost >= INF ? -1 : cost) << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

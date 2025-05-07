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

int dp[1005][1005][2];

/* Codeforces‑1498C Planar Reflections
 * link: https://codeforces.com/problemset/problem/1498/C
 * 思路:
 * 题目抽象:
 *   状态由三元组(i,k,d)确定
 *     i   当前所在平面 1..n
 *     k   剩余衰减度 1..K
 *     d   运动方向 0=左 1=右
 *
 *   记 dp[i][k][d] 为粒子处于状态(i,k,d) 时
 *   整个过程最终产生的粒子总数
 *
 *   边界: k==1 时粒子不再复制 仅剩自身
 *     dp[i][1][0]=dp[i][1][1]=1
 *
 *   转移(写成统一式):
 *     dp[i][k][d] =
 *       1                                           // 本身
 *       + (i+dir≤n) dp[i+dir][k]  [d]  -1           // 穿透 同向
 *       + (i-dir≥1) dp[i-dir][k-1][1-d] -1          // 反向 副本
 *   其中 dir = (d==1 ? +1 : -1)
 *   减 1 的原因: dp 子问题返回值已包含子粒子自身
 *   而本粒子与其副本在 ans 起始值 2 中已先计数
 *   故需各自抵消一次 以避免重复
 *
 *   计算顺序:
 *     按 k 从 1→K
 *     对每个 k:
 *       d=1 时 i 正序 1→n    保证前置状态已求
 *       d=0 时 i 逆序 n→1
 *
 * 时间复杂度: O(n*k)  每个状态仅计算一次
 * 空间复杂度: O(n*k*2) ≈ 2*1000*1000 = 2e6 整数
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    auto dfs = [&](auto &&self, int now, int old, int dir)-> int {
        if (old == 1) return 1;
        if (dp[now][old][dir] != -1) return dp[now][old][dir];
        int ans = 2;
        if (dir == 1) {
            if (now < n)
                (ans += self(self, now + 1, old, dir) - 1) %= MOD;
            if (now > 1)
                (ans += self(self, now - 1, old - 1, 1 - dir) - 1) %= MOD;
        } else {
            if (now > 1)
                (ans += self(self, now - 1, old, dir) - 1) %= MOD;
            if (now < n)
                (ans += self(self, now + 1, old - 1, 1 - dir) - 1) %= MOD;
        }
        return dp[now][old][dir] = ans;
    };
    cout << dfs(dfs, 1, k, 1) << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

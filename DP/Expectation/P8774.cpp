//
// Created by 幻 on 2025/5/31.
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
constexpr int MOD = 998244353;
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

/* P8774 [蓝桥杯 2022 省 A] 爬树的甲壳虫
 * link: https://www.luogu.com.cn/problem/P8774
 * 标签: 期望DP、线性方程、模逆运算
 * 思路:
 *   定义 f[i] 为从根爬到高度 i 的期望时间，故 f[0]=0。
 *   对于每个 i (1 ≤ i ≤ n)：
 *     - 成功（概率 1 - P_i）时：爬到 i,花费 1 并继续,期望为 (1 - P_i)*1
 *     - 失败（概率 P_i）时：花费 1 并回到根，再花费f[i]时间回到i,期望为P_i*(f[i] + 1)
 *     因此有方程：
 *       f[i] = (1 - P_i) + f[i-1] + P_i*(f[i] + 1)
 *     移项：
 *       f[i] = (f[i-1] + 1) / (1 - P_i)
 *   在模意义下:
 *     1 - P_i = (y[i] - x[i]) * inv(y[i]) mod M
 *     将除法用模逆 (快速幂) 实现。
 * 时间复杂度: O(n·log M)，空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    auto bpow = [&](ll x, ll n) {
        ll ans = 1, base = x;
        while (n) {
            if (n & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            n >>= 1;
        }
        return ans;
    };
    vector<ll> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<ll> f(n + 1);
    for (int i = 1; i <= n; ++i) {
        ll inv = bpow(y[i] - x[i], MOD - 2);
        f[i] = (f[i - 1] + 1) * y[i] % MOD * inv % MOD;
    }
    cout << f[n];
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

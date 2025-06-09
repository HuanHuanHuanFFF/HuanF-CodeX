//
// Created by 幻 on 2025/6/9.
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
constexpr int N = 1e6 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = false;

// Codeforces Round 988 (Div. 3)
/* 2037G-G
 * link: https://codeforces.com/contest/2037/problem/G
 * 标签: 线性筛, 容斥原理, 动态规划, 子集枚举
 * 思路:
 *   1 用线性筛预处理最大值的最小质因子 spf
 *   2 令 dp[i] 为到达第 i 城市的路径数 dp[1]=1 并维护 cnt[d] 累加所有 j<i 且 d|a[j] 的 dp[j]
 *   3 枚举 a[i] 的质因子子集 用容斥原理(奇加偶减)计算 dp[i]
 *   4 更新 cnt[d]+=dp[i]
 * 时间复杂度: O(maxA loglog maxA + n·2^{f(a_i)})
 * 空间复杂度: O(maxA + n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int maxA = std::ranges::max(a);
    vector<int> spf(maxA + 1); // smallest prime factor
    for (int i = 2; i <= maxA; ++i) {
        if (!spf[i]) {
            for (int j = i; j <= maxA; j += i) {
                if (!spf[j]) spf[j] = i;
            }
        }
    }
    vector<int> dp(n + 1), cnt(maxA + 1);
    dp[1] = 1; //
    {
        vector<int> pf;
        int x = a[1];
        while (x > 1) {
            int p = spf[x];
            pf.emplace_back(p);
            while (x % p == 0) x /= p;
        }
        int m = pf.size();
        for (int mask = 1; mask < 1 << m; ++mask) {
            int d = 1;
            for (int k = 0; k < m; ++k) {
                if (mask >> k & 1) d *= pf[k];
            }
            cnt[d] = (cnt[d] + dp[1]) % MOD;
        }
    }
    for (int i = 2; i <= n; ++i) {
        int x = a[i];
        vector<int> pf;
        while (x > 1) {
            int p = spf[x];
            pf.emplace_back(p);
            while (x % p == 0) x /= p;
        }
        int m = pf.size(), sum = 0;
        for (int mask = 1; mask < 1 << m; ++mask) {
            int d = 1;
            int bit = __builtin_popcount(mask);
            for (int k = 0; k < m; ++k) {
                if (mask >> k & 1) d *= pf[k];
            }
            if (bit & 1) sum = (sum + cnt[d]) % MOD;
            else sum = (sum - cnt[d] + MOD) % MOD;
        }
        dp[i] = sum;
        for (int mask = 1; mask < 1 << m; ++mask) {
            int d = 1;
            for (int k = 0; k < m; ++k) {
                if (mask >> k & 1) d *= pf[k];
            }
            cnt[d] = (cnt[d] + dp[i]) % MOD;
        }
    }
    cout << dp[n];
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

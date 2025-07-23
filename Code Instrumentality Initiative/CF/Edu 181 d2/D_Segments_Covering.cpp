//
// Created by 幻 on 2025/7/22.
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

constexpr bool more = false;

// Educational Codeforces Round 181 (Rated for Div. 2)
/* D. Segments Covering
 * link: https://codeforces.com/problemset/problem/2125/D
 * 标签: dp, 概率
 * 思路:
 *   1 none = ∏((q-p)/q) 记录所有区间不选概率乘积
 *   2 定义 dp[x] = 选出若干互不重叠区间刚好覆盖[1..x] 的权重和
 *      单个区间权重 w = p/(q-p)
 *   3 排序所有区间 按 r 升序扫描 更新
 *      dp[r] = (dp[r] + dp[l-1] * w % MOD) % MOD
 *   4 答案 = none * dp[m] % MOD
 * 时间复杂度 O(n log n + (n+m) log MOD)
 * 空间复杂度 O(n + m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<ll> dp(m + 1);
    vector<std::array<ll, 4> > edge(n);
    ll none = 1;
    auto bpow = [&](ll x, ll y = MOD - 2) {
        ll ans = 1;
        while (y) {
            if (y & 1) ans = ans * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return ans;
    };
    for (auto &[r,l,p,q]: edge) {
        cin >> l >> r >> p >> q;
        ll no = (q - p) * bpow(q) % MOD;
        none = none * no % MOD;
    }
    std::ranges::sort(edge);
    dp[0] = 1;
    for (auto &[r,l,p,q]: edge) {
        dp[r] = (dp[r] + dp[l - 1] * p % MOD * bpow(q - p) % MOD) % MOD;
    }
    cout << dp[m] * none % MOD << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

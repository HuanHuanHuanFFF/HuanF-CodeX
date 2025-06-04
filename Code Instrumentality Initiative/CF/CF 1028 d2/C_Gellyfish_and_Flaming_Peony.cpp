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
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 5e3 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Codeforces Round 1028 (Div. 2) 
/* C. Gellyfish and Flaming Peony
 * link: https://codeforces.com/contest/1028/problem/C
 * 标签: 数论, gcd, 动态规划（DP）
 * 思路:
 *   1. 先算全局 gcd = g，任何 ai := gcd(ai, aj) 操作只会让元素收敛到 g 的因子，因此最终所有元素都能变为 g。
 *   2. 把每个 a[i] 除以 g，得到 b[i] = a[i]/g，目标变为「让所有 b[i] 都变为 1」。若已有元素 b[i]==1，则后续只需每个其它元素一次 gcd 操作即可，答案 = n − cnt1。
 *   3. 否则，需要先让其中一个 b[i] 变成 1。定义 dp[x] 表示「最少操作数将某个元素恰好变为 x」。初始时，对所有 b[i] 令 dp[b[i]] = 0，其余 dp[*] = INF。
 *   4. 从 x = max(b) 递减到 1，遍历每个不同的 y ∈ b，做一次操作 x → gcd(x, y)，相当于：
 *        u = gcd(x, y)
 *        dp[u] = min(dp[u], dp[x] + 1)
 *      保证「大状态」的 dp[x] 已定后再更新「更小状态」dp[u]。
 *   5. 最终 dp[1] 为「先造出一个 1」的最少操作。答案 = max(dp[1] − 1, 0) + (n − cnt1)，
 *      其中 (n − cnt1) 是把其余元素一次与 1 做 gcd 收拢为 1 的操作数。
 * 时间复杂度: O(maxv * |unique(b)| * log(maxv))，其中 maxv ≤ 5000, |unique(b)| ≤ n ≤ 5000。
 * 空间复杂度: O(N + maxv)，N = 5000+7，用于存储 dp、原数组。
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    int g = a[0];
    for (int i = 1; i < n; ++i) {
        g = std::gcd(a[i], g);
    }
    vector<int> dp(N, INF);
    int cnt = 0;
    for (auto &x: a) {
        x /= g;
        dp[x] = 0;
        if (x == 1) ++cnt;
    }
    std::ranges::sort(a);
    a.erase(std::ranges::unique(a).begin(), a.end());
    auto max = a.back();
    for (int x = max; x >= 1; --x) {
        for (auto &y: a) {
            int u = std::gcd(x, y);
            dp[u] = std::min(dp[u], dp[x] + 1);
        }
    }
    cout << std::max(dp[1] - 1, 0) + n - cnt << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

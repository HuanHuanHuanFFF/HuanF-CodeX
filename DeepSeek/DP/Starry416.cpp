//
// Created by 幻 on 2025/6/25.
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
constexpr int N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = false;

/* 相邻最大公约数 [入门教育赛 416]
 * link: https://www.starrycoding.com/problem/416
 * 标签: 动态规划, 二状态, gcd, 状态机
 * 思路:
 *   定义 dp[i][0] 为处理到 i 时且 a[i] 未加 x 的最大相邻 gcd 和
 *   定义 dp[i][1] 为处理到 i 时且 a[i] 已加 x 的最大相邻 gcd 和
 *   转移时枚举前一元素是否加 x，共两种来源，累加相应的 gcd 值：
 *     dp[i][0] = max(
 *       dp[i-1][0] + gcd(a[i-1],     a[i]),
 *       dp[i-1][1] + gcd(a[i-1]+x,   a[i])
 *     )
 *     dp[i][1] = max(
 *       dp[i-1][0] + gcd(a[i-1],     a[i]+x),
 *       dp[i-1][1] + gcd(a[i-1]+x,   a[i]+x)
 *     )
 *   最终答案为 max(dp[n][0], dp[n][1])
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector dp(n + 1, vector<ll>(3));
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = std::max(dp[i - 1][0] + std::gcd(a[i - 1], a[i]),
                            dp[i - 1][1] + std::gcd(a[i - 1] + x, a[i]));
        dp[i][1] = std::max(dp[i - 1][0] + std::gcd(a[i - 1], a[i] + x),
                            dp[i - 1][1] + std::gcd(a[i - 1] + x, a[i] + x));
    }
    cout << std::max({dp[n][0], dp[n][1]});
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/8/14.
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

// Tokio Marine & Nichido Fire Insurance Programming Contest 2025  (AtCoder Beginner Contest 402) 
/* ABC402 E - Payment Required
 * link: https://atcoder.jp/contests/abc402/tasks/abc402_e
 * 标签: 状压DP 期望DP 贝尔曼方程 预算约束 自适应决策
 * 思路:
 * 定义 d[T][x]: 已解集合 T 且剩余经费 x 的最大期望
 * 对任意 i notin T 且 x >= C[i] 做一次尝试
 *   成功 概率 p_i 得到 S[i] 并转到状态 (T U {i}, x - C[i]) 贡献 S[i] + d[T U {i}][x - C[i]]
 *   失败 概率 1 - p_i 留在 (T, x - C[i]) 贡献 d[T][x - C[i]]
 * 转移:
 *   d[T][x] = max over i notin T of p_i * ( S[i] + d[T U {i}][x - C[i]] ) + (1 - p_i) * d[T][x - C[i]]
 * 递推顺序: 按 x = 0..X 枚举 尝试所有 T 与可选 i 保证用到的 x - C[i] 已被计算
 * 正确性: 成功與失败两分支互斥且覆盖全部结果 期望线性性成立 决策最优满足贝尔曼最优性
 * 答案: d[{}][X]
 * 时间复杂度: O(N * X * 2^N)
 * 空间复杂度: O(X * 2^N)
 */
void HuanF() {
    int n, x;
    cin >> n >> x;
    vector<int> s(n), c(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> c[i] >> p[i];
    }
    vector dp(1 << n, vector<double>(x + 1));
    for (int i = 0; i <= x; ++i) {
        for (int st = 0; st < 1 << n; ++st) {
            for (int j = 0; j < n; ++j) {
                int co = i - c[j], se = st | 1 << j;
                if (co < 0 || se == st) continue;
                double pi = p[j] / 100.0;
                double v = pi * (s[j] + dp[se][co]) + (1 - pi) * dp[st][co];
                dp[st][i] = std::max(dp[st][i], v);
            }
        }
    }
    printf("%.10lf", dp[0][x]);
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

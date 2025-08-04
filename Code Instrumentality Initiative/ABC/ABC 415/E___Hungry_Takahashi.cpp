//
// Created by 幻 on 2025/8/4.
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
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e17 + 17;
constexpr int N = 1e7 + 7;

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

// Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415) 
/* ABC415-E
 * link: https://atcoder.jp/contests/abc415/tasks/abc415_e
 * 标签: 动态规划, 网格, 最小初始资金
 * 思路:
 * 1 定义 dp[i][j] 为从 (i,j) 出发到终点 (H-1,W-1) 前，未收集当前格硬币时所需的最小初始资金
 * 2 终点状态 dp[H-1][W-1] = max(0, p[H+W-2] - a[H-1][W-1])
 * 3 状态转移：
 *   dp[i][j] = min( (i+1<H ? dp[i+1][j] : INF)
 *                , (j+1<W ? dp[i][j+1] : INF) )
 *   然后加上 p[i+j] - a[i][j]，再取 max(0, ·)
 * 4 答案为 dp[0][0]
 * 时间复杂度 O(HW)
 * 空间复杂度 O(HW)
 */
void HuanF() {
    int h, w;
    cin >> h >> w;
    vector a(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    vector<ll> p(h + w - 1);
    for (auto &x: p) cin >> x;
    vector dp(h, vector<ll>(w, INF));
    dp[h - 1][w - 1] = 0;
    for (int i = h - 1; i >= 0; --i) {
        for (int j = w - 1; j >= 0; --j) {
            if (i + 1 < h) dp[i][j] = std::min(dp[i + 1][j], dp[i][j]);
            if (j + 1 < w) dp[i][j] = std::min(dp[i][j + 1], dp[i][j]);
            dp[i][j] += p[i + j] - a[i][j];
            dp[i][j] = std::max(dp[i][j], 0ll);
        }
    }
    cout << dp[0][0] << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

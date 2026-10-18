//
// Created by 幻 on 2026/10/18.
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
constexpr ll INF = 1e15 + 17;
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

/* ABC303-D - Shift vs. CapsLock
 * link: https://atcoder.jp/contests/abc303/tasks/abc303_d
 * 标签: 动态规划, 状态机
 * 思路: dp[i][0/1] 表示输入前 i 个字符后, CapsLock 关闭/开启的最小代价。
 * 初始代价为 0 和 z; 转移比较保持状态、先切换再输入、先输入再切换。
 * x 与 y 没有固定大小关系, 切换前后的输入方式都要考虑, 不能漏掉对称方案。
 * 时间复杂度: O(n), 空间复杂度: O(n)
 */
void HuanF() {
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;
    int n = s.length();
    vector<std::array<ll, 2> > dp(n + 1);
    dp[0][0] = 0, dp[0][1] = z;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == 'a') {
            dp[i + 1][0] = std::min({dp[i][0] + x, dp[i][1] + z + x, dp[i][1] + y + z});
            dp[i + 1][1] = std::min(dp[i][0] + std::min(x, y) + z, dp[i][1] + y);
        } else {
            dp[i + 1][0] = std::min(dp[i][0] + y, dp[i][1] + std::min(x, y) + z);
            dp[i + 1][1] = std::min({dp[i][0] + z + x, dp[i][1] + x, dp[i][0] + y + z});
        }
    }
    cout << std::min(dp[n][0], dp[n][1]);
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

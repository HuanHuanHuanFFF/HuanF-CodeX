//
// Created by 幻 on 2026/4/19.
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

/* Educational DP Contest-F LCS
 * link: https://atcoder.jp/contests/dp/tasks/dp_f
 * 标签: LCS, DP, 路径还原
 * 思路:
 * 设 dp[i][j] 表示 s 的前 i 个字符和 t 的前 j 个字符的最长公共子序列长度.
 * 若 s[i - 1] == t[j - 1], 说明这两个字符可以一起作为结尾, 则 dp[i][j] = dp[i - 1][j - 1] + 1.
 * 否则这两个字符不能同时取, 至少要舍弃一个, 所以 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]).
 * 求完 dp 后从 (n, m) 反推答案. 若当前两个字符相等, 说明它们一定可以作为某个最优解的结尾, 加入答案并同时左上移动.
 * 否则就在上方和左方中, 向 dp 值更大的那个状态移动. 这样最终得到一条合法的最长公共子序列.
 * 时间复杂度: O(nm)
 * 空间复杂度: O(nm)
 */
void HuanF() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int x = n, y = m;
    vector<char> ans;
    ans.reserve(dp[n][m]);
    while (x != 0 && y != 0) {
        if (s[x - 1] == t[y - 1]) {
            ans.emplace_back(s[x - 1]);
            --x, --y;
        } else if (dp[x - 1][y] >= dp[x][y - 1])
            --x;
        else --y;
    }
    for (auto &c: ans | std::views::reverse)
        cout << c;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

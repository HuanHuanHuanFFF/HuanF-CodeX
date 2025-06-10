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
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* ABC408-D
 * link: https://atcoder.jp/contests/abc408/tasks/abc408_d
 * 标签: 字符串, 贪心, kadane
 * 思路:
 *   1 统计字符串中总1数 all
 *   2 将 each s[i] 映射为 x = (s[i]=='1'?1:-1)
 *   3 用 Kadane 算法求 maxSubarray 和 max：now = max(now + x, 0), max = max(max, now)
 *   4 最少操作数 = all - max
 * 时间复杂度 O(N)
 * 空间复杂度 O(1)
 */
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    int all = std::ranges::count(s, '1');
    int max = 0, now = 0;
    for (int i = 0; i < n; ++i) {
        int x = s[i] == '1' ? 1 : -1;
        now = std::max(now + x, 0);
        max = std::max(max, now);
    }
    cout << all - max << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

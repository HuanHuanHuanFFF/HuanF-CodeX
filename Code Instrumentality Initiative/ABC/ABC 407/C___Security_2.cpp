//
// Created by 幻 on 2025/5/24.
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

// AtCoder Beginner Contest 407
/* C-Security 2
 * link: https://atcoder.jp/contests/abc407/tasks/abc407_c
 * 标签: 模拟, 贪心
 * 思路:
 * - 初始化 ans = |S|, 对应按 A 的次数
 * - 遍历 i = 1..l-1, 令 pre = s[i-1], now = s[i], 若 pre < now 则 pre += 10, 累加 pre - now 到 ans
 * - 最后累加 s[l-1] 到 ans
 * 时间复杂度 O(|S|) 空间复杂度 O(1)
 */
void HuanF() {
    string s;
    cin >> s;
    ll ans = s.size(), l = s.size();
    for (int i = 1; i < l; ++i) {
        int pre = s[i - 1] - '0';
        int now = s[i] - '0';
        if (pre < now) pre += 10;
        ans += pre - now;
    }
    ans += s[l - 1] - '0';
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

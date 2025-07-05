//
// Created by 幻 on 2025/7/4.
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

constexpr bool more = true;

// Codeforces Round 833 (Div. 2)
/* B. Diverse Substrings
 * link: https://codeforces.com/problemset/problem/1748/B
 * 标签: 枚举；剪枝；频次统计
 * 思路:
 *  1 从每个起点 i 暴力向右枚举子串 j
 *  2 用 cnt 记录当前子串每个数字出现次数 并维护 max = 最大频次
 *  3 若 max>10 则可剪枝 终止枚举
 *  4 否则 若 不同字符数 cnt.size() >= max 则满足条件 ans++
 * 时间复杂度 O(n*100) 空间复杂度 O(1)
 */
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        std::map<int, int> cnt;
        int max = 0;
        for (int j = 0; j <= 100 && i + j < n; ++j) {
            max = std::max(max, ++cnt[s[i + j] - '0']);
            if (max > 10) break;
            if (max <= cnt.size()) ++ans;
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

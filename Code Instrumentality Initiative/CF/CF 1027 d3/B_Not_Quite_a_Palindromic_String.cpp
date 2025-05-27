//
// Created by 幻 on 2025/5/26.
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

// Codeforces Round  1027 (Div. 3) 
/* B. Not Quite a Palindromic String
 * link: https://codeforces.com/contest/2114/problem/B
 * 标签: 贪心, 计数, 数学, 奇偶
 * 思路:
 *  1. 统计字符串中 '0' 和 '1' 的数量 cnt0, cnt1
 *  2. 总对数为 n/2，想要恰好 k 个“好对”（两端相同），则需要 c = n/2 - k 个“不好对”（两端不同）
 *  3. 每个不好对消耗 1 个 '0' 和 1 个 '1'，所以要保证 min(cnt0, cnt1) ≥ c 且 c ≥ 0
 *  4. 剩下的字符用于好对，每种字符剩余数量 (cnt? - c) 必须为偶数，才能两两配对，所以检查 (cnt1 - c) % 2 == 0
 * 时间复杂度 O(n)，空间复杂度 O(1)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(2);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - '0'];
    }
    int c = n / 2 - k;
    bool ok = std::min(cnt[0], cnt[1]) >= c && c >= 0 && ((cnt[1] - c & 1) == 0);
    cout << (ok ? "yes" : "no") << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

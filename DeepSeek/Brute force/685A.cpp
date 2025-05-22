//
// Created by 幻 on 2025/5/22.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
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

/* A. 强盗的表
 * link: https://codeforces.com/problemset/problem/???
 * 思路:
 * 1. 计算小时和分钟分别需要的7进制位数：初始位数为1，每次 i *= 7 直到 i >= n 或 i >= m。
 * 2. 如果两部分位数之和 > 7，则7进制数字不可能全部互异，直接输出0剪枝。
 * 3. 枚举所有合法时间 (i, j)：
 *    - 对 i（小时）做 a 次7进制拆分（不足高位自动补0），对 j（分钟）做 b 次拆分，
 *      用 used[0..6] 计数每个数字的出现次数。
 *    - 若所有 used[d] ≤ 1，则说明所有位数字互异，ans++。
 * 时间复杂度：O(n * m * (a + b))，在 a + b ≤ 7 且 n ≤ 7^a, m ≤ 7^b 时，最坏约 7^7 * 7 ≈ 6e6，可在2s内通过。
 * 空间复杂度：O(7)（used数组固定大小）。
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    int a = 1, b = 1;
    for (int i = 7; i < n; i *= 7) {
        ++a;
    }
    for (int i = 7; i < m; i *= 7) {
        ++b;
    }
    if (a + b > 7) {
        cout << 0;
        return;
    }
    ll ans = 0;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            vector<int> used(7);
            for (int k = 0, ka = i; k != a; ka /= 7, ++k) {
                ++used[ka % 7];
            }
            for (int k = 0, kb = j; k != b; kb /= 7, ++k) {
                ++used[kb % 7];
            }
            if (*std::max_element(used.begin(), used.end()) <= 1)
                ++ans;
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

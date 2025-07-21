//
// Created by 幻 on 2025/7/17.
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

// Codeforces Round 1037 (Div. 3)
/* G1. 大胜利！（简易版）
 * link: https://codeforces.com/contest/2126/problem/G1
 * 标签: 前缀和·枚举·中位数
 * 思路:
 *   - 枚举中位数阈值 m，从 1 到 100
 *   - b[i] = +1 若 a[i] ≥ m，否则 -1
 *   - 计算前缀和 pref，维护 prefmn 和 suffmx
 *   - 若存在以 j 为端点的子数组使得和 > 0，则该子数组中位数 ≥ m
 *   - 对所有满足条件的位置计算 m - a[j]，取最大值
 * 时间复杂度: O(100·n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for (int m = 1; m <= 100; ++m) {
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + (a[i] >= m ? 1 : -1);
        }
        vector<int> pre_min(n + 1), suf_max(n + 2);
        for (int i = 1; i <= n; ++i) {
            pre_min[i] = std::min(pre_min[i - 1], pre[i]);
        }
        suf_max[n] = pre[n];
        for (int i = n - 1; i > 0; --i) {
            suf_max[i] = std::max(suf_max[i + 1], pre[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (pre[i] >= pre_min[i - 1] || pre[i - 1] <= suf_max[i])
                ans = std::max(ans, m - a[i]);
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

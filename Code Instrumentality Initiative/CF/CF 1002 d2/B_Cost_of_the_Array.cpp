//
// Created by 幻 on 2025/6/13.
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

// Codeforces Round 1002 (Div. 2) 
/* 2059B - Cost of the Array
 * link: https://codeforces.com/contest/2059/problem/B
 * 标签: 枚举段首、贪心、鸽巢原理
 * 思路:
 *   • 若 k==n，仅有每个元素单独成段这一种划分，
 *     b 即取偶数下标元素 + 0，直接线性检查求最小 i 使 bi≠i。
 *
 *   • 否则 (k<n):
 *       – 若能令 **第二段** 首元素 ≠1，则 b1≠1 → cost=1。
 *       – 若第二段首元素只能是 1，则最优让它包含 **至少两个 1**，
 *         此时 b1=1, b2≠2 → cost=2。
 *     枚举第二段起点 s∈[2, n−k+2]，
 *     检查区间 a[s … s+(k−2)] (长度 ≥2) 是否全为 1：
 *       · 若存在非 1，答案 = 1 (立即结束)；
 *       · 否则答案 = 2。
 *
 *   • 复杂度: 对每个 s 最多看 O(1) 元素 ⇒ 总 O(n)。
 * 时间复杂度: O(n) / 用前缀和可降至 O(n)
 * 空间复杂度: O(1)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n == k) {
        for (int i = 2; i <= n; i += 2) {
            if (a[i] != i / 2) {
                cout << i / 2 << "\n";
                return;
            }
        }
        cout << n / 2 + 1 << "\n";
        return;
    }
    for (int i = 2; i <= n - k + 2; ++i) {
        if (a[i] != 1) {
            cout << 1 << "\n";
            return;
        }
    }
    cout << 2 << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

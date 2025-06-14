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
/* 2059C - Customer Service
 * link: https://codeforces.com/contest/2059/problem/C
 * 标签: 贪心、排序、MEX、区间覆盖
 * 思路:
 *   • 定义 suf[i] 为队列 i 末尾连续为 1 的长度 k
 *     —— 该队列最终可留下的最大人数即 k（0‥k 均可实现）
 *   • 将 suf 升序排序后贪心扫描
 *       cur = 0
 *       遍历 suf:
 *         若 suf[i] ≥ cur → 用该队列留下 cur, cur++
 *       扫描结束的 cur 即最大 MEX
 *   • 证明:
 *       若存在更优方案, 必定可按右端点升序重排而不变差
 *       （经典区间贪心交换论证）, 因此本算法最优
 * 时间复杂度: O(n²)   — 计算后缀 + 排序
 * 空间复杂度: O(n)    — 只存 suf 数组
 */
void HuanF() {
    int n;
    cin >> n;
    vector a(n, vector<ll>(n));
    vector<int> suf(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (a[i][j] != 1) break;
            ++suf[i];
        }
    }
    std::ranges::sort(suf);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (suf[i] >= ans) ++ans;
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

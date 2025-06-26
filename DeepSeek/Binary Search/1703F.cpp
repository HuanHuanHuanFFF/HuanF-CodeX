//
// Created by 幻 on 2025/6/26.
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

// Codeforces Round 806 (Div. 4) 
/* 1703F
 * link: https://codeforces.com/problemset/problem/1703/F
 * 标签: 排序, 二分, 贪心
 * 思路:
 * 1 筛选所有满足 a[i]<i 的下标 i 并按遍历顺序保存到 pre（单调递增）
 * 2 当遇到新的 i 且 a[i]<i 时：
 *   用 std::lower_bound 在已升序的 pre 上查找第一个 ≥ a[i] 的位置 pos，
 *   则 pos 即满足 j<a[i] 的 j 数量，将其累加到 ans
 * 3 将当前 i 插入 pre 末尾
 * 时间复杂度 O(n log n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    vector<int> pre;
    pre.reserve(n);
    for (int i = 1; i <= n; ++i) {
        if (a[i] < i) {
            auto it = std::lower_bound(pre.begin(), pre.end(), a[i]);
            int d = 0;
            if (it == pre.end()) d = (int) pre.size();
            else d = it - pre.begin();
            ans += d;
            pre.emplace_back(i);
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

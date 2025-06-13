//
// Created by 幻 on 2025/6/11.
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

// Codeforces Round 1004 (Div. 2)
/* B. 两个大包-2067B
 * link: https://codeforces.com/problemset/problem/2067/B
 * 标签: 贪心 排序 模拟
 * 思路:
 *   1. 对数组排序，保证成对检查时顺序最小
 *   2. 维护当前门槛 mx=0，表示下一对数字至少要能提升到此值
 *   3. 每次取一对相邻元素 a[i], a[i+1]：
 *      - 通过 max(mx, a[i]) 和 max(mx, a[i+1]) 判断二者是否能同步达到同值
 *      - 若不同，说明无法配对，输出 No 并立即返回
 *      - 若相同，则将 mx 更新为该值+1，继续下一对
 * 时间复杂度: O(n log n)  （排序 O(n log n) + 扫描 O(n)）
 * 空间复杂度: O(n)       （存储数组）
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::ranges::sort(a);
    int mx = 0;
    for (int i = 0; i < n; i += 2) {
        if (std::max(mx, a[i]) != std::max(mx, a[i + 1])) {
            cout << "No\n";
            return;
        }
        mx = std::max(mx, a[i]) + 1;
    }
    cout << "Yes\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

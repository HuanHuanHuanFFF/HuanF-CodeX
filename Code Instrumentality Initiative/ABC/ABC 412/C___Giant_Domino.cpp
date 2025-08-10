//
// Created by 幻 on 2025/6/28.
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

// AtCoder Beginner Contest 412
/* C - Giant Domino
 * link: https://atcoder.jp/contests/abc412/tasks/abc412_c
 * 标签: 贪心 multiset 上界查询
 * 思路: 固定首尾多米诺 1 与 N 必选
 *       1. 先将中间区间 [2,N−1] 根据尺寸升序排序
 *       2. 维护指针 last 表示当前最右已选位置
 *          - 若 2·S_last 已覆盖 S_N 直接计入末牌 结束
 *          - 否则在区间内扩展 now 到满足 S_now ≤ 2·S_last 的最右下标
 *            · 若区间空则无解
 *            · 否则把 last←now 继续循环
 * 时间复杂度: O(N log N) （排序）
 * 空间复杂度: O(1)  额外常数
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::sort(a.begin() + 1, a.end() - 1);
    int ans = 1, now = 1, last = 0;
    while (now < n) {
        while (now + 1 < n && a[now + 1] <= a[last] * 2) ++now;
        if (a[last] * 2 >= a.back()) {
            cout << ans + 1 << "\n";
            return;
        }
        if (a[now] > a[last] * 2) {
            cout << "-1\n";
            return;
        }
        last = now;
        ++ans;
        ++now;
    }
    if (last != n - 1) cout << "-1\n";
    else cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

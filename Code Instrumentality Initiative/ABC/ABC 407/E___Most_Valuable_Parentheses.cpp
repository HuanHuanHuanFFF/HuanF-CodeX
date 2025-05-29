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
/* E-Most Valuable Parentheses
 * link: https://atcoder.jp/contests/abc407/tasks/abc407_e
 * 标签: 贪心, 优先队列
 * 思路:
 *  - 初始化最大堆 heap 和 ans = 0
 *  - 对 i = 1..n:
 *      if (i == 1)
 *          heap.emplace(a[1])
 *      else {
 *          heap.emplace(a[2*i - 2])
 *          heap.emplace(a[2*i - 1])
 *      }
 *      弹出堆顶加入 ans
 *  - 输出 ans
 * 时间复杂度 O(n log n) 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n << 1 | 1);
    for (int i = 1; i <= n << 1; ++i) cin >> a[i];
    ll ans = 0;
    std::priority_queue<ll> heap;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) heap.emplace(a[1]);
        else {
            heap.emplace(a[i * 2 - 2]);
            heap.emplace(a[i * 2 - 1]);
        }
        ans += heap.top();
        heap.pop();
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/9.
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

// Codeforces Round 988 (Div. 3) 
/* 2037F - Ardent Flames
 * link: https://codeforces.com/contest/2037/problem/F
 * 标签: 二分查找, 扫描线, 差分数组, 前缀和
 * 思路:
 *   1. 对答案 q（攻击次数）二分：检查是否能在 q 次攻击内击败 ≥k 个敌人
 *   2. 对每个敌人 i，用 ceil(h[i]/q) 表示每次攻击需至少造成的伤害：D=⌈h_i/q⌉
 *      - 如果 D>m，则 q 次内无法击杀，跳过该敌人
 *      - 否则满足 m - |p - x_i| ≥ D ⇔ |p - x_i| ≤ m - D
 *      - 由此得到 p 的可行区间 [x_i - (m-D), x_i + (m-D)]
 *   3. 收集所有可行区间的差分事件：+1 于 L，-1 于 R+1，按坐标排序，
 *      累加前缀和判断是否存在点覆盖 ≥k 个区间
 *   4. 若存在可覆盖 ≥k，则 r=mid，否则 l=mid
 *   5. 二分范围为 [1, max(h_i)]，若最终 r=max(h_i)+1 则输出 -1
 * 时间复杂度: O(n log n log max(h))
 */
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n), x(n);
    for (auto &i: h) cin >> i;
    for (auto &i: x) cin >> i;

    auto check = [&](ll cnt) {
        std::map<ll, int> d;
        for (int i = 0; i < n; ++i) {
            ll dis = m - (h[i] + cnt - 1) / cnt;
            if (dis < 0) continue;
            ++d[x[i] - dis];
            --d[x[i] + dis + 1];
        }
        int die = 0;
        for (auto &[x,y]: d) {
            die += y;
            if (die >= k) return true;
        }
        return false;
    };

    ll l = 0, r = INF;
    while (l + 1 < r) {
        int mid = l + (r - l >> 1);
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << (r == INF ? -1 : r) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

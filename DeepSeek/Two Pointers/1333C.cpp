//
// Created by 幻 on 2025/6/18.
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

constexpr bool more = false;

// Codeforces Round 632 (Div. 2) 
/* C. 赫纳根与一个数组
 * link: https://codeforces.com/problemset/problem/1333/C
 * 标签: 前缀和、滑动窗口、双指针、集合
 * 思路:
 *  1. 计算前缀和 pre[i] = a[0] + … + a[i-1]
 *  2. 用窗口 [l, r) 维护当前前缀和集合 s = { pre[l], …, pre[r-1] }，保证无重复
 *  3. 右指针 r 尽可能右扩：当 pre[r] ∉ s 时，插入 s 并 r++
 *  4. 对每个 l，窗口内所有子数组都“好”，贡献 r−l 个解
 *  5. 收缩时移除 pre[l]，l++
 * 时间复杂度 O(n·log n)，空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i];
    }
    ll ans = 0;
    std::set<ll> s{0};
    int l = 0, r = 0;
    while (l < n) {
        while (r < n && !s.contains(pre[r + 1])) {
            s.insert(pre[r + 1]);
            ++r;
        }
        ans += r - l;
        s.erase(pre[l]);
        ++l;
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

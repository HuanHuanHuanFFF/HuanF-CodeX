//
// Created by 幻 on 2025/6/8.
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

// Codeforces Round 962 (Div. 3)
/* 1996F - 炸弹
 * link: https://codeforces.com/contest/1996/problem/F
 * 标签：二分查找、前k大、等差数列求和
 * 思路：
 * 1. 二分确定一个阈值 kth，使得至少有 k 次操作的得分不小于 kth
 * 2. 对每个位置 i，计算在得分序列 a[i],a[i]-b[i],a[i]-2b[i],… 中，需要多少次才能降到低于 kth；这些得分都 ≥ kth
 * 3. 对于每个 i，对前 times 次高分操作使用求和符号表示：
 *    sum_{j=0..times-1}(a[i] - j*b[i])，累加到总得分 ans，并统计操作次数 cnt
 * 4. 若 cnt>k，多余 (cnt-k) 次操作的得分均为 kth，用 ans -= kth*(cnt-k) 修正
 * 整体时间复杂度：O(n log max(a))，用于处理前 k 大问题
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    auto check = [&](int m) {
        ll all = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= m)
                all += (a[i] - m) / b[i] + 1;
            if (all >= k) return true;
        }
        return all >= k;
    };

    ll kth; {
        ll l = 0, r = INF;
        while (l + 1 < r) {
            ll mid = l + r >> 1;
            if (check(mid)) l = mid;
            else r = mid;
        }
        kth = l;
    }
    ll ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= kth) {
            ll c = (a[i] - kth) / b[i];
            ans += (c + 1) * (a[i] + a[i] - c * b[i]) / 2;
            cnt += c + 1;
        }
    }
    ans -= kth * (cnt - k);
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

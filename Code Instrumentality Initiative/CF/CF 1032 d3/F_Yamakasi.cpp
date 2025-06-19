//
// Created by 幻 on 2025/6/17.
//
#include <bits/stdc++.h>

using namespace std;

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

// Codeforces Round 1032 (Div. 3) 
/* F. Yamakasi
 * link: https://codeforces.com/contest/???/problem/F
 * 标签: 前缀和·哈希  贡献拆分  容斥
 * 思路:
 *   1. 设 f(p) =  子段和 = s 且 max ≤ p 的子段数
 *      则答案 = f(x) − f(x−1)       (只留下 max 恰为 x 的子段)
 *
 *   2. 计算 f(p)
 *      • 顺扫数组，遇到 a[i] > p 立即清空计数器，等价于把
 *        子段断开（这些子段里 max 已经 > p）
 *      • 对于当前合法段，用 map cnt 记录前缀和出现次数：
 *          pre[i] = ∑ a[1..i]
 *          若 pre[i]−s 在 map 中出现 t 次，则产生 t 条
 *          右端点为 i、和 = s 的子段
 *        然后把当前 pre[i] 写回 map
 *
 *   3. 复杂度
 *      时间:  O(n log n)（map）·O(n) (unordered_map)
 *      空间:  O(n)  (最坏所有前缀互异)
 *
 *   4. 证明
 *      • 清空 map 保证所有被统计的子段 max ≤ p
 *      • Inclusion-Exclusion 保证最后剩下 max = x
 *
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    ll n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n + 1);
    for (auto &i: a | views::drop(1)) cin >> i;
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }

    auto f = [&](ll p) {
        ll ans = 0;
        map<ll, int> cnt;
        ++cnt[0];
        for (int i = 1; i <= n; ++i) {
            if (a[i] > p) {
                cnt.clear();
            }
            if (cnt.contains(pre[i] - s)) ans += cnt[pre[i] - s];
            ++cnt[pre[i]];
        }
        return ans;
    };

    ll ans = f(x) - f(x - 1);
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

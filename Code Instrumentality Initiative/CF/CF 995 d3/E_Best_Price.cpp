//
// Created by 幻 on 2025/6/27.
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
constexpr int INF = 2e9 + 17;
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

// Codeforces Round 995 (Div. 3) 
/* 2051E-BestPrice
 * link: https://codeforces.com/contest/2051/problem/E
 * 标签: 排序, 事件扫描
 * 思路:
 *   1 将每个顾客的 a_i(开始差评) 与 b_i(停止购买) 作为两个事件 (value,type) 存入数组
 *   2 按 value 升序排序, 单调扫描价 x, 维护 cnt(当前买家数) 与 bad(差评数)
 *   3 遇新价 x 前若 bad<=k, 更新 ans=max(ans, cnt*x)
 *   4 对所有事件值==x: type==0 时 bad++; type==1 时 cnt-- 且 bad--
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    vector<PII> p;
    p.reserve(n << 1);
    for (int i = 0; i < n; ++i) {
        p.emplace_back(a[i], 0);
        p.emplace_back(b[i], 1);
    }
    std::ranges::sort(p);
    ll ans = 0, bad = 0, cnt = n, i = 0;
    while (i < n * 2) {
        auto &[x,y] = p[i];
        if (bad <= k) ans = std::max(ans, cnt * x);
        while (i < n * 2 && p[i].first == x) {
            bad += p[i].second == 0;
            bad -= p[i].second == 1;
            cnt -= p[i].second == 1;
            ++i;
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

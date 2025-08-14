//
// Created by 幻 on 2025/8/7.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e17 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = true;

// Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2)
/* 2127C-Trip Shopping
 * link: https://codeforces.com/contest/2127/problem/C
 * 标签: 区间建模, 排序, 相交判定, 贪心博弈等价, 相邻性
 * 思路:
 * 1. 规范化: 把每对 (a_i,b_i) 排成区间 [l_i,r_i] (代码里 first=r_i≥second=l_i), 初始值 S=∑(r_i-l_i)
 * 2. 单次操作只作用于两段 [l1,r1],[l2,r2](设 r1≤r2, l1≤l2), 巴哈明可在四端点间任意重配, 仅有三种本质配对:
 *    保持: (r1-l1)+(r2-l2)
 *    交叉1: |r2-l1|+|r1-l2|
 *    交叉2: |r2-r1|+|l1-l2|
 *    (其它排列与此等价, 因两数组整体同置换不变)
 * 3. 关键结论(证明):
 *    若两段相交(l2≤r1):
 *      |r2-l1|+|r1-l2| ≤ (r1-l1)+(r2-l2), 且 |r2-r1|+|l1-l2| ≤ (r1-l1)+(r2-l2)
 *      ⇒ max(三式) = (r1-l1)+(r2-l2) = 原和 (巴哈明无法提升)
 *    若两段不相交(r1<l2):
 *      交叉1 = 交叉2 = (r1-l1)+(r2-l2)+2(l2-r1) ⇒ 提升量 = 2×(间距)
 * 4. 全局策略:
 *    - 若存在任意一对相交区间, 阿里总能给出这对 → 最终值=S
 *    - 否则(全不相交), 选择最近的两段, 巴哈明最多提升 2×minGap → 最终值=S+2×minGap
 * 5. 实现: 按 r 升序只需检查相邻两段:
 *    若 dis[i]+dis[i-1] ≥ max(交叉1,交叉2) ⇒ 存在相交 → 直接输出 S
 *    否则记录 S - dis[i]-dis[i-1] + max(交叉1,交叉2) 的最小值 (等价 S+2×minGap)
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<PII> a(n);
    std::set<ll> st;
    for (int i = 0; i < n; ++i) cin >> a[i].first;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
        st.insert(a[i].first);
        st.insert(a[i].second);
        if (a[i].second > a[i].first)
            std::swap(a[i].second, a[i].first);
    }
    std::ranges::sort(a);
    ll ans = 0;
    vector<ll> dis(n);
    for (int i = 0; i < n; ++i) {
        dis[i] = abs(a[i].first - a[i].second);
    }
    ans = std::accumulate(dis.begin(), dis.end(), ans);

    ll min = INF;
    for (int i = 1; i < n; ++i) {
        if (dis[i] + dis[i - 1] >= std::max(abs(a[i].first - a[i - 1].second) + abs(a[i - 1].first - a[i].second),
                                            abs(a[i].first - a[i - 1].first) + abs(a[i - 1].second - a[i].second))) {
            cout << ans << "\n";
            return;
        }
        if (dis[i] + dis[i - 1] < std::max(abs(a[i].first - a[i - 1].second) + abs(a[i - 1].first - a[i].second),
                                           abs(a[i].first - a[i - 1].first) + abs(a[i - 1].second - a[i].second))) {
            min = std::min(
                ans - dis[i] - dis[i - 1] + std::max(
                    abs(a[i].first - a[i - 1].second) + abs(a[i - 1].first - a[i].second),
                    abs(a[i].first - a[i - 1].first) + abs(a[i - 1].second - a[i].second)),
                min);
        }
    }
    cout << min << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

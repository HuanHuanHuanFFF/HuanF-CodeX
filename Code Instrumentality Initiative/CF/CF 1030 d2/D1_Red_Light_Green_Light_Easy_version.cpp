//
// Created by 幻 on 2025/6/12.
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

// Codeforces Round 1030 (Div. 2) 
/* 2118D1 - Red Light, Green Light (easy version)
 * link: https://codeforces.com/problemset/problem/2118/D1
 * 标签: 模拟, 环检测, 二分搜索
 * 思路:
 *   1. **找前方最近红灯**
 *      - 维护方向 dir∈{+1,-1}
 *      - dir>0 用 lower_bound 找 ≥pos 的第一盏; dir<0 用 upper_bound-1 找 ≤pos 的最后一盏
 *   2. **判断是否撞灯**
 *      - 到达时间 t+|p[i]-pos| 与 d[i] 同余 mod k ⇒ 红灯
 *      - 若不是红灯, 沿当前方向线性扫下一个灯
 *   3. **撞灯→掉头→继续**
 *      - 记录状态 (i,dir,(t mod k)) 到集合; 若重复则形成环, 输出 NO
 *      - 否则更新时间 t, 位置 pos=p[i]+dir, 方向取反, 重复步骤 1
 *   4. **越界即成功离开**
 *      - 无灯 or 走出 [1,1e15] 区间立即输出 YES
 * 时间复杂度: 每次查询最坏 O(n²) (n≤500, q≤500 总量受限)
 * 空间复杂度: O(n) 存储位置与延迟, 以及两个集合
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<ll> p(n), d(n);
    for (auto &x: p) cin >> x;
    for (auto &x: d) cin >> x;
    int q;
    cin >> q;
    for (ll i = 0, a; i < q; ++i) {
        cin >> a;
        int v = 1;
        std::set<int> st1, st2;
        auto next = std::ranges::lower_bound(p, a) - p.begin();
        ll t = 0;
        bool ok = true;
        while (next >= 0 && next < n) {
            while ((t + abs(p[next] - a)) % k != d[next] && next < n && next >= 0) {
                if (v > 0) ++next;
                else --next;
            }
            if (next == n || next < 0) break;
            if (v > 0) {
                if (st1.contains(next)) {
                    cout << "NO\n";
                    ok = false;
                    break;
                }
                st1.insert(next);
            } else {
                if (st2.contains(next)) {
                    cout << "NO\n";
                    ok = false;
                    break;
                }
                st2.insert(next);
            }
            v = -v;
            t += abs(p[next] - a) + 1;
            a = p[next] + v;
            if (v > 0) next = std::ranges::lower_bound(p, a) - p.begin();
            else next = std::ranges::upper_bound(p, a) - p.begin() - 1;
        }
        if (ok) cout << "YES\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

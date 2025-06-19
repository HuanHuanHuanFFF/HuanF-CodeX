//
// Created by 幻 on 2025/6/17.
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

// Codeforces Round 1006 (Div. 3)
/* 2072E - Do You Love Your Hero and His Two-Hit Multi-Target Attacks
 * link: https://codeforces.com/problemset/problem/2072/E
 * 标签: 组合构造、曼哈顿距离、欧氏距离、贪心
 * 思路:
 *   条件 ρ(a,b)=d(a,b) 当且仅当 xa=xb 或 ya=yb
 *   因此满足条件的 unordered 对只能出现在同一列或同一行
 *
 *   目标: 构造 ≤500 个整点, 使合法对数恰为 k
 *
 *   贪心拆分 k
 *   1. 记 g(m)=m(m-1)/2 为 m 个点同列能产生的合法对数
 *   2. 反复取最大 m 使 g(m)≤k
 *        • 在竖线 x 上放 m 个点 (y 连续), 贡献 g(m) 对
 *        • k←k-g(m), 坐标系整体斜向下移 (x+=2, y+=m+1) 避免重叠
 *   3. 当 m=1 时, g(1)=0, 剩余 k≤446
 *        • 用若干形如 {(x,y),(x,y+1)} 的小竖线, 每次再贡献 1 对, 直至 k=0
 *
 *   点数上界
 *     k≤1e5 ⇒ 最大一次取 m=447
 *     剩余 ≤446, 2×⌈√(2k)⌉≈43 个点即可清零
 *     总点数 ≤447+43=490<500
 *
 * 时间复杂度 O(√k)
 * 空间复杂度 O(1)
 */
void HuanF() {
    int k;
    cin >> k;
    int x = 0, y = 0;
    vector<PII> ans;
    ans.reserve(500);
    while (k) {
        ll l = -1, r = 500;
        while (l + 1 < r) {
            ll mid = l + r >> 1;
            ll p = mid * (mid - 1) / 2;
            if (p > k) r = mid;
            else l = mid;
        }
        if (l == 1) {
            while (k) {
                ans.emplace_back(x, y);
                ans.emplace_back(x, y + 1);
                x += 2;
                y += 2;
                --k;
            }
        } else {
            k -= l * (l - 1) / 2;
            for (int i = 0; i < l; ++i) {
                ans.emplace_back(x, y + i);
            }
            x += 2;
            y += l + 1;
        }
    }
    cout << ans.size() << "\n";
    for (auto &[x,y]: ans) cout << x << " " << y << "\n";
}


signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

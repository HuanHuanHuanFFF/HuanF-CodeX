//
// Created by 幻 on 2025/6/4.
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

// Codeforces Round 1009 (Div. 3) 
/* D - Counting Points
 * link: https://codeforces.com/contest/2074/problem/D
 * 标签: 几何, 模拟
 * 思路:
 * 1. 枚举所有圆在每个整数 x 纵坐标的覆盖范围，用 map 储存每个 x 对应的最大 |y| 范围 high[x]。
 *   对于第 i 个圆，遍历 xi - ri 到 xi + ri 的所有整数 x，计算当前圆在该 x 的最大 y 范围为 floor(sqrt(ri^2 - (x - xi)^2))，更新 high[x] 为所有圆的最大值。
 * 2. 最后，对 map 中每个 x，存在 2*high[x] + 1 个整数点满足条件（y 从 -high[x] 到 +high[x]），累加得到答案。
 * 时间复杂度: O(m log m)，其中 m = ∑ ri；空间复杂度: O(m)。
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    std::map<ll, ll> high;
    vector<ll> x(n), r(n);
    for (auto &i: x) cin >> i;
    for (auto &i: r) cin >> i;
    for (int i = 0; i < n; ++i) {
        for (int xi = x[i] - r[i]; xi <= x[i] + r[i]; ++xi) {
            high[xi] = std::max(high[xi], (ll) sqrt(r[i] * r[i] - (x[i] - xi) * (x[i] - xi)));
        }
    }
    ll ans = 0;
    for (auto &[k,v]: high) {
        ans += v;
    }
    cout << (ans << 1) + high.size() << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

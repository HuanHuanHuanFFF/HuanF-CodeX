//
// Created by 幻 on 2025/5/14.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* 552D-Vanya and Triangles
 * link: https://codeforces.com/problemset/problem/552/D
 * 思路:
 * 模块1 统计所有三点组合数 C(n,3)
 * 模块2 退化三角形数 dis 由每个点作为基点 枚举其他点 计算归一化斜率 分组得到共线点数 m 累加 C(m,2)
 * 模块3 因为每个退化三角形被三个顶点各自统计 所以 dis 最终除以 3
 * 最终答案 = C(n,3) - dis
 * 时间复杂度 O(n^2 log n) 空间复杂度 O(n)
 */
void HuanF() {
    ll n;
    cin >> n;
    vector<int> x(n), y(n);
    // 模块1 计算所有三角形总数
    ll ans = n * (n - 1) * (n - 2) / 6; // C(n,3)
    ll dis = 0; // 退化三角形计数
    // 读入所有点坐标
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    // 模块2 对每个基点 i 枚举其余点 分组统计共线点对
    for (int i = 0; i < n; ++i) {
        std::map<PII, ll> cnt; // <归一化方向, 数量>
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            int g = std::gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            // 统一方向正向
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            ++cnt[{dx, dy}];
        }
        // 累加 C(m,2)
        for (auto &[dir, m]: cnt) {
            dis += m * (m - 1) / 2;
        }
    }
    // 模块3 消除重复
    dis /= 3;
    cout << ans - dis;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

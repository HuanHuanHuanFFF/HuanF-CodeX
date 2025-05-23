//
// Created by 幻 on 2025/5/22.
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

/* B. Slice to Survive
 * link: https://codeforces.com/contest/2042/problem/B
 * 思路:
 *   枚举第一次切割方向 只与第一次切割后剩余子网格尺寸有关
 *   对每种 (x,y) 回合数为 ⌈log2(x)⌉ + ⌈log2(y)⌉
 *   用 __lg(x*2-1) 计算 ⌈log2(x)⌉
 * 时间复杂度: O(1) 每个测试
 * 空间复杂度: O(1)
 */
void HuanF() {
    int ans = INF, n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<PII> ps({
        {a, m}, {n, b},
        {n - a + 1, m}, {n, m - b + 1}
    });
    for (auto [x,y]: ps) {
        ans = std::min(std::__lg(x * 2 - 1) + std::__lg(y * 2 - 1), ans);
    }
    cout << 1 + ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

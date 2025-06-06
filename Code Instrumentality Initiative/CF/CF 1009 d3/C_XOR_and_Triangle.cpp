//
// Created by 幻 on 2025/6/2.
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
/* 2074C
 * link: https://codeforces.com/problemset/problem/2074/C
 * 标签: 位运算, 贪心, 枚举
 * 思路:
 *   1. 将三角形不等式转为位运算条件
 *      * x&y>0 保证 x+y>x⊕y
 *      * x&(x⊕y)>0 保证 x+(x⊕y)>y
 *      * y&(x⊕y)>0 保证 y+(x⊕y)>x
 *   2. 从上述条件推导出 y 的二进制必须同时满足
 *      * 在某个位 i 上 x_i=1 且 y_i=1（保证 x&y>0）
 *      * 在某个位 j 上 x_j=0 且 y_j=1（保证 y&(x⊕y)>0）
 *      * 在其他所有 x 为 1 的位都让 y 对应位为 0，则这位 x_i=1,y_i=0 可使 (x⊕y)_i=1，从而 x&(x⊕y)>0
 *   3. 为了构造最小的 y，只需在最低的“x 为 1 的位”上放一个 1（标记 u1），
 *      并在最低的“x 为 0 的位”上放一个 1（标记 u0），其余位都为 0
 *   4. 从 i=0 到 29 依次扫描：
 *      * 如果 x 在 i 位为 1 且还未选过 u1，则令 u1=true, ans|=(1<<i)
 *      * 否则如果 x 在 i 位为 0 且还未选过 u0，则令 u0=true, ans|=(1<<i)
 *   5. 最终若 ans<x 则输出 ans，否则输出 -1
 * 时间复杂度: O(log x)
 * 空间复杂度: O(1)
 */
/*void HuanF() {
    int x;
    cin >> x;
    int ans = 0;
    bool u1 = false, u0 = false;
    for (int i = 0; i < 30; ++i) {
        if (x >> i & 1) {
            if (!u1) {
                u1 = true;
                ans |= 1 << i;
            }
        } else {
            if (!u0) {
                u0 = true;
                ans |= 1 << i;
            }
        }
    }
    if (ans < x) cout << ans << "\n";
    else cout << -1 << "\n";
}*/
// 感觉还是有点难以理解,用暴力吧

/* 2074C-异或与三角形
 * link: https://codeforces.com/problemset/problem/2074/C
 * 标签: 位运算, 枚举, 三角形不等式
 * 思路:
 *   为了让三边 (x, y, x ⊕ y) 构成非退化三角形，等价于位运算条件：
 *     1. x & y > 0               （保证 x + y > x⊕y）
 *     2. y & (x⊕y) > 0           （保证 y + (x⊕y) > x）
 *     3. x & (x⊕y) > 0           （保证 x + (x⊕y) > y）
 *
 *   推导可知，这三条同时成立，当且仅当：
 *     - y 必须至少在一个位 i 上使 x_i = 1 且 y_i = 1    （满足 x & y > 0）
 *     - y 必须至少在一个位 k 上使 x_k = 0 且 y_k = 1    （满足 y & (x⊕y) > 0）
 *     - 其余 x 为 1 的位都让 y 对应位为 0，则这位 x_j=1, y_j=0 会令 (x⊕y)_j=1，从而 x & (x⊕y) > 0
 *
 *   因此只需构造 y 恰好在「一个 x 的 1 位」和「一个 x 的 0 位」上各放一个 1，其余位为 0。
 *   这就要求枚举所有“两个 1 位”的组合：一个位 i 取自 x 的 1 位集合，另一个位 j 取自 x 的 0 位集合。
 *   只要 y < x 且满足三角形两个不等式，就可以直接返回 y；否则无解输出 -1。
 *
 * 时间复杂度: O((log x)^2)，枚举 i,j ∈ [0,29]
 * 空间复杂度: O(1)
 */
void HuanF() {
    int x;
    cin >> x;
    int ans = -1;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            int y = 1 << i | 1 << j;
            if (y < x && x + y > (x ^ y) && y + (x ^ y) > x)
                ans = y;
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/11.
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

// Codeforces Round 1004 (Div. 2) 
/* C. Devyatkino - 2067C
 * link: https://codeforces.com/problemset/problem/2067/C
 * 标签: 数位 模拟 贪心
 * 思路:
 *   1. 枚举所有形如 9, 99, 999, ... 的加数（最多 9 位全 9），分别尝试作为连续加数
 *   2. 对于每个加数 add:
 *      - 从原数 n 开始，重复加 add，计数 cnt 增 +1
 *      - 每次加后检查当前数 nx 的各位，若出现数字 7，则用 cnt 更新最小答案 ans
 *      - 若 cnt 已超当前最优 ans，可提前终止该加数的模拟
 *   3. 遍历完所有 add，输出 ans
 * 时间复杂度: 最多 9 种加数，每种最坏循环至 ans，初始 ans=INF，实际 cnt 受最优限制且 ans ≤ 7
 *             数字检查每次 O(log n) → 近似常数，总体可接受
 * 空间复杂度: O(1)
 */
void HuanF() {
    ll n;
    cin >> n;
    ll ans = INF, add = 9;
    for (int i = 0; i < 9; ++i) {
        ll cnt = 0, nx = n;
        while (cnt <= ans) {
            ll p = nx;
            while (p) {
                int x = p % 10;
                p /= 10;
                if (x == 7) {
                    ans = std::min(cnt, ans);
                }
            }
            ++cnt;
            nx += add;
        }
        add = add * 10 + 9;
    }
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

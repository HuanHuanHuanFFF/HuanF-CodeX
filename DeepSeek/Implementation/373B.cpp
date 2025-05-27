//
// Created by 幻 on 2025/5/24.
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

// Codeforces Round 219 (Div. 2) 
/* Making Sequences is Fun - Codeforces 373B
 * link: https://codeforces.com/problemset/problem/373/B
 * 标签: 模拟、位数计数
 * 思路:
 *  1. 计算可用总权重 nsum = w / k
 *  2. 得到当前起点 m 的位数 n, 下一个位数变化点 next = 10^n
 *  3. 分段处理:
 *     - 每段长度为 (next - m), 单价为 n
 *     - 若 nsum 足以买完整段, 扣费并进入下一段, n++, m = next, next *= 10
 *     - 否则仅购买 nsum / n 个数, 剩余权重清零
 *  4. 累加购买数量 ans 即答案
 * 时间复杂度: O(log10 m)
 * 空间复杂度: O(1)
 */
void HuanF() {
    ll w, m, k;
    cin >> w >> m >> k;
    ll nsum = w / k;
    ll n = 0, p = m;
    while (p) {
        n++;
        p /= 10;
    }
    ll next = pow(10, n), ans = 0;
    while (nsum > 0) {
        if (nsum >= (next - m) * n) {
            nsum -= (next - m) * n;
            n++;
            ans += next - m;
            m = next;
            next *= 10;
        } else {
            ans += nsum / n;
            nsum = 0;
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

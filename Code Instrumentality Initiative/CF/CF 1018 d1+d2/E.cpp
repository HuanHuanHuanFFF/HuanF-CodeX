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

/*
 * E. Wonderful Teddy Bears
 * link: https://codeforces.com/contest/2096/problem/E
 * 标签: 贪心, 逆序对, 模2不变式, 二进制排序
 *
 * 思路:
 * 1. 将 'B' 视作 0, 'P' 视作 1, 目标是把所有 0 移到左侧, 即排序二进制数组。
 * 2. 统计逆序对 rev：每个 1 (P) 与其右侧所有 0 (B) 构成逆序。rev 为总逆序数。
 * 3. 统计 cntB = 总 0 数, even = 0 在偶数下标(1-based)的数量。
 * 4. 最终前 cntB 个一定是 0, 它们在区间 [1..cntB] 内, 偶数位置应有 floor(cntB/2) 个 0。
 *    初始 even 个, 差值 d = |floor(cntB/2) - even|，需要 d 次能调节偶数位 0 的操作(A/C)。
 * 5. 每次调节操作(A/C)消 1 个逆序; 其余逆序用操作(B/D)每次消 2 个。
 * 6. 最少操作 = d + (rev - d)/2 = (rev + d)/2。
 *
 * 时间复杂度: O(n)，空间复杂度: O(1)
 */
void HuanF() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll cntB = 0, rev = 0, even = 0;
    // 从右往左遍历, 一次计算 rev, cntB, even
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'B') {
            ++cntB;
            if (!(i + 1 & 1)) ++even;
        } else rev += cntB;
    }
    // 目标区间 [1..cntB] 中偶数位置应有 floor(cntB/2) 个 0
    ll d = abs(cntB / 2 - even);
    // 最少操作 = (rev + d) / 2
    cout << (rev + d >> 1) << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

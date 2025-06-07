//
// Created by 幻 on 2025/6/7.
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

long long query(long long n) {
    cout << n << endl;
    long long res;
    cin >> res;
    return res;
}

long long end_query() {
    cout << "!" << endl;
    long long res;
    cin >> res; // m = x ^ y
    return res;
}

// Codeforces Round 1008 (Div. 2) 
/* https://codeforces.com/contest/2078/problem/E
 * 2077B - Finding OR Sum
 * 交互式题 解题思路：
 *  1. 构造两个掩码：
 *     n0 = 奇数位全1（0101...010），用于提取偶数位信息
 *     n1 = 偶数位全1（1010...101），用于提取奇数位信息
 *  2. 第一次 query(n0) 得到 q0，第二次 query(n1) 得到 q1，再 end_query() 得到 m = x ^ y。
 *  3. 从 q0 中按 base-4 拆出每个偶数位的 (x_i+y_i)：
 *      - 高位 curf = (q0 >> (i+1))&1, 低位 curb = (q0 >> i)&1
 *      - curf=1 => "10" => x_i=y_i=1
 *      - curf=0, curb=1 => "01" => 一零组合
 *      - 处理后 q0 -= 4*2^i
 *  4. 类似方式从 q1 中恢复每个奇数位(先 q1-=2)。
 *  5. 根据 m, val_and, val_or 逐位累加 x+y：
 *      if m_i=1 或 val_and_i=1 => 2*2^i
 *      else if val_or_i=1       => 1*2^i
 *      else 0
 */
// 思路会了,代码写不出来🥺
void HuanF() {
    long long n0 = 0, n1 = 0;
    for (int i = 1; i < 30; i += 2) n0 |= 1LL << i; // 奇数位掩码
    for (int i = 0; i < 30; i += 2) n1 |= 1LL << i; // 偶数位掩码

    long long q0 = query(n0); // a
    long long q1 = query(n1); // b
    long long m = end_query(); // m = x ^ y

    long long val_and = 0, val_or = 0;

    /* ---------- 解析偶数位 (来自 q0) ---------- */
    for (int i = 0; i < 30; i += 2) {
        long long pos = 1LL << i; // 2^i
        long long curb = (q0 >> i) & 1; // base-4 的低位
        long long curf = (q0 >> (i + 1)) & 1; // base-4 的高位

        if (curf) {
            // '10' → x[i]=y[i]=1
            val_and |= pos;
            val_or |= pos;
        } else if (curb) {
            // '01' → 只有一个 1
            val_or |= pos;
        }
        q0 -= 4LL * pos; // 抹掉本 base-4 位，供后续位正确右移
    }

    /* ---------- 解析奇数位 (来自 q1) ---------- */
    q1 -= 2; // 题解里的小技巧：先对整体做一次 -2
    for (int i = 1; i < 30; i += 2) {
        long long pos = 1LL << i;
        long long curb = (q1 >> i) & 1;
        long long curf = (q1 >> (i + 1)) & 1;

        if (curf && !curb) {
            // '10'
            val_and |= pos;
            val_or |= pos;
        } else if (!curf && curb) {
            // '01'
            val_or |= pos;
        }
        q1 -= 4LL * pos;
    }

    /* ---------- 由 m, val_and, val_or 复原 x + y ---------- */
    long long ans = 0;
    for (int i = 0; i < 30; ++i) {
        long long bit = 1LL << i;
        if ((m >> i) & 1) {
            // m 位=1 → x[i] ^ y[i] =1 → x+y 在该 bit 贡献 2
            ans += 2LL * bit;
        } else if ((val_and >> i) & 1) {
            ans += 2LL * bit; // x[i]=y[i]=1 也贡献 2
        } else if ((val_or >> i) & 1) {
            ans += bit; // 只有一个 1 → 贡献 1
        }
    }
    cout << ans << endl; // 输出 x + y
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/12.
//

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 4000000; // A, B, C, D 最大值为 10^6，因此最大 N = A + B + C + D

// 用于存储阶乘和逆阶乘
vector<long long> fac(MAXN + 1), ifac(MAXN + 1);

// 快速幂计算
long long fpow(long long a, long long n) {
    long long r = 1;
    for (; n; n >>= 1, a = a * a % MOD) {
        if (n & 1) {
            r = r * a % MOD;
        }
    }
    return r;
}

// 初始化阶乘和逆阶乘
void init() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[MAXN] = fpow(fac[MAXN], MOD - 2); // 计算最大阶乘的逆元
    for (int i = MAXN - 1; i >= 0; --i) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
}

// 计算组合数 C(n, k) % MOD
long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

/* E - Fruit Lineup
 * link: https://atcoder.jp/contests/abc405/tasks/abc405_e
 * 思路:
 * 1 设 N=A+B+C+D
 * 2 枚举最后一个苹果所在位置 i 使得 A≤i≤A+B
 * 3 左侧 i-1 个位置放剩余 A-1 只苹果和 B 橘子 方案数 C(i-1, A-1)
 * 4 右侧 N-i 个位置放 C 只香蕉和 D 葡萄 方案数 C(N-i, C)
 * 5 累加所有 i 的乘积即为答案
 * 时间复杂度 O(N)
 * 空间复杂度 O(N)
 */
long long solve(long long A, long long B, long long Cb, long long D) {
    // 预处理阶乘和逆阶乘
    init();

    // 总元素个数 N = A + B + C + D
    long long N = A + B + Cb + D;
    long long ans = 0;

    // 遍历最右边的苹果位置 i (从 A 到 A+B)
    for (long long i = A; i <= A + B; ++i) {
        // 计算组合数，并累加结果
        ans = (ans + C(i - 1, A - 1) * C(N - i, Cb)) % MOD;
    }

    return ans;
}

int main() {
    // 输入 A, B, C, D
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    // 输出结果
    cout << solve(A, B, C, D) << endl;

    return 0;
}

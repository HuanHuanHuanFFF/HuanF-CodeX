//
// Created by 幻 on 2025/6/21.
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
constexpr int N = 1e5 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


vector<ll> inv(N);

void init() {
    IOS();
    inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

constexpr bool more = true;

// Codeforces Round 1033 (Div. 2) and CodeNite 2025 
/* Matrix k-Colored Submatrix
 * link: https://codeforces.com/contest/2120/problem/D
 * 标签: 鸽巢原理, 组合计数, 同色子矩阵
 * 思路:
 *   题目要求在 k 色 n×m 网格中找到 a×b 的同色子矩阵, 并使 (n,m) 字典序最小.
 *   1. 行数 n = (a-1) * k + 1. 由鸽巢原理可知, 任意一列必有某颜色出现 ≥ a 次.
 *   2. 每列的 "安排" = (颜色, 选出的 a 行集合) 有 k * C(n, a) 种, 设为 t.
 *   3. 列数 m = (b-1) * t + 1. 若列数超过 (b-1) 个安排, 根据鸽巢原理必有同一安排重复 ≥ b 列, 交叉即得 a×b 同色矩阵.
 *   4. 计算 t 需取模 1e9+7: t = k * C(n, a) (mod MOD). 使用预处理好的 inv[i] 快速求逆元.
 *   5. 输出行数 n 与列数 m 皆取模.
 *   时间复杂度: O(a)
 *   空间复杂度: O(1) (除预处理逆元数组)
 */
void HuanF() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll n = ((a - 1) * k + 1) % MOD;
    ll an = k;
    for (int i = 1; i <= a; ++i) {
        an = an * (n - i + 1) % MOD * inv[i] % MOD;
    }
    ll m = ((b - 1) * an + 1) % MOD;
    cout << n << " " << m << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

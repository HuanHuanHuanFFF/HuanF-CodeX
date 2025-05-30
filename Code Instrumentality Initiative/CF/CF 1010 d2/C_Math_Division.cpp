//
// Created by 幻 on 2025/5/30.
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
constexpr ll inv = 500000004;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Codeforces Round 1010 (Div. 2, Unrated) 
/* 2082C - Math Division
 * link: https://codeforces.com/contest/2082/problem/C
 * 标签: 概率DP、二进制建模、模逆运算
 * 思路:
 *   维护 ans 为当前累计的进位概率 f_i
 *   inv = 2^{-1} mod MOD 表示 模意义下的 1/2
 *   从最低位 i = n-1 向上遍历到 i = 1：
 *     每步先加上当前位是否为 '1'（会产生新进位），再乘以 inv 进行“衰减”
 *     即 f_i = (f_{i-1} + (s[i]=='1')) / 2
 *   最终期望 E = (n-1) + f_{n-1}
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
void HuanF() {
    ll ans = 0, n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = n - 1; i > 0; --i) {
        ans = (ans + (s[i] == '1')) * inv % MOD;
    }
    cout << (n - 1 + ans) % MOD << "\n";
}

signed main() {
    init();
    // auto bpow = [&](ll x, ll n) {
    //     ll ans = 1, base = x;
    //     while (n) {
    //         if (n & 1) ans = ans * base % MOD;
    //         base = base * base % MOD;
    //         n >>= 1;
    //     }
    //     return ans;
    // };
    // cout << bpow(2, MOD - 2) << endl;
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

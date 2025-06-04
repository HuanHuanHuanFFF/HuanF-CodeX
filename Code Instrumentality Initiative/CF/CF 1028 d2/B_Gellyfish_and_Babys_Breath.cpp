//
// Created by 幻 on 2025/5/31.
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
constexpr int MOD = 998244353;
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

/* Codeforces Round 1028 B
 * link: https://codeforces.com/contest/2116/problem/B
 * 标签: 前缀扫描, 指数比较, 快速幂, 模运算
 * 思路:
 *   1. 预处理 max1[i], max2[i]：前缀 [0..i] 中 p 和 q 的最大值下标。
 *   2. 对每个 i 构造两对指数
 *      A = (p[j1], q[i - j1])，其中 j1 = max1[i]
 *      B = (p[i - k2], q[k2])，其中 k2 = max2[i]
 *   3. 先比较 A/B 的最大指数，若相同再比较次大指数，以此判定“不取模时哪个 2^x+2^y 更大”。
 *   4. 选出更大的那一对后，再用快速幂分别计算 2^x % MOD 和 2^y % MOD，相加 % MOD 得到 ans[i]。
 * 时间复杂度: O(n·logMOD)，空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> p(n), q(n), ans(n), max1(n), max2(n);
    for (auto &x: p) {
        cin >> x;
    }
    for (auto &x: q) {
        cin >> x;
    }
    max1[0] = max2[0] = 0;
    for (int i = 1; i < n; ++i) {
        max1[i] = max1[i - 1];
        max2[i] = max2[i - 1];
        if (p[i] > p[max1[i]]) max1[i] = i;
        if (q[i] > q[max2[i]]) max2[i] = i;
    }
    auto bpow = [](ll x, ll n) {
        ll res = 1, base = x;
        while (n) {
            if (n & 1) res = res * base % MOD;
            base = base * base % MOD;
            n >>= 1;
        }
        return res;
    };
    for (int i = 0; i < n; ++i) {
        ll maxA = std::max(p[max1[i]], q[i - max1[i]]),
                maxB = std::max(q[max2[i]], p[i - max2[i]]),
                minA = std::min(p[max1[i]], q[i - max1[i]]),
                minB = std::min(q[max2[i]], p[i - max2[i]]);
        bool first = false;
        if (maxA > maxB) first = true;
        else if (maxA < maxB) first = false;
        else if (minA > minB) first = true;
        if (first) ans[i] = (bpow(2, p[max1[i]]) + bpow(2, q[i - max1[i]])) % MOD;
        else ans[i] = (bpow(2, q[max2[i]]) + bpow(2, p[i - max2[i]])) % MOD;
    }
    for (auto &x: ans) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

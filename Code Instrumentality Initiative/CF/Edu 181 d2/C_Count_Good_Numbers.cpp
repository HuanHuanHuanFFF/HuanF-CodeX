//
// Created by 幻 on 2025/7/22.
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

// Educational Codeforces Round 181 (Rated for Div. 2) 
/* 2125C
 * link: https://codeforces.com/problemset/problem/2125/C
 * 标签: 数论, 容斥原理
 * 思路:
 *   1 定义 f(N) = # {1 ≤ x ≤ N | gcd(x,210)=1}，即与 2,3,5,7 都不整除的数
 *   2 用容斥枚举子集 S ⊆ {2,3,5,7}：
 *      若 P=∏_{p∈S} p，位数 |S|，则对 N/ P 做加减
 *      f(N) = ∑_{S} (-1)^{|S|} ⌊N/ P⌋
 *   3 区间答案 = f(r) - f(l-1)
 * 时间复杂度 O(2^4)=O(16)，空间复杂度 O(1)
 */
void HuanF() {
    ll l, r;
    cin >> l >> r;
    auto f = [&](ll x) {
        vector<ll> p = {2, 3, 5, 7};
        ll ans = 0;
        for (int mask = 0; mask < 16; ++mask) {
            ll prod = 1, bit = 0;
            for (int i = 0; i < 4; ++i) {
                if (mask >> i & 1) prod *= p[i], ++bit;
            }
            ll cnt = x / prod;
            ans += (bit & 1 ? -cnt : cnt);
        }
        return ans;
    };
    cout << f(r) - f(l - 1) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

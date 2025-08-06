//
// Created by 幻 on 2025/8/6.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 998244353;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = false;

// Mirrativ Programming Contest 2025 (AtCoder Beginner Contest 414) 
/* ABC414-E Count A%B=C
 * link: https://atcoder.jp/contests/abc414/tasks/abc414_e
 * 标签: 整除分块、数学计数、O(√N)
 * 思路:
 *   ● 目标三元组满足 1≤a,b,c≤N 且 a>b, a%b=c, 且三者两两不同
 *   ● 若 a<b 则 a=c ⇒ 与 b 不同却与 a 相同, 不符合要求, 故必须 a>b
 *   ● 对任意 a>b 都对应唯一 c=a%b∈[1,b-1] 与 a,b 均不同
 *     ⇒ 总候选有 N(N-1)/2
 *   ● 唯一需剔除 a%b=0 的情形(即 b|a, c=0 不合法)
 *     — 对固定 b, 需减去 ⌊N/b⌋−1 个 a(去除 a=b 本身)
 *   ● 答案 = N(N-1)/2 − Σ_{b=1}^{N}(⌊N/b⌋−1)
 *   ● 用整除分块法在 O(√N) 计算后者:
 *       枚举区间 [l,r) 使得 ∀b∈[l,r) 有同一商 q = ⌊N/b⌋
 *       r = ⌊N/q⌋+1, 区间贡献 (r-l)(q-1)
 * 时间复杂度: O(√N)
 * 空间复杂度: O(1)
 */
void HuanF() {
    constexpr ll INV2 = (MOD + 1) / 2; // 2 的逆元
    ll n;
    cin >> n;
    auto mul_mod = [&](__uint128_t a, __uint128_t b) {
        return ll(a * b % MOD);
    };
    ll all = n % MOD * ((n - 1) % MOD) % MOD * INV2 % MOD;
    ll bad = 0;
    for (ll l = 1; l <= n;) {
        ll q = n / l;
        ll r = n / q + 1;
        ll cnt = r - l;
        bad += mul_mod(cnt % MOD, (q - 1) % MOD);
        bad %= MOD;
        l = r;
    }
    ll ans = all - bad;
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

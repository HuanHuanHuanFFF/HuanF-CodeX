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
constexpr int MOD = 998244353;
constexpr int INF = 1e9 + 17;
constexpr int N = 63;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector c(N + 1, vector<ll>(N + 1)), s(N + 1, vector<ll>(N + 1));

void init() {
    IOS();
    // 预计算 DP，i 从 0 到 N-1
    c[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            // 在第 i 位插 0：popcount 不变，数值不变
            c[i + 1][j] = (c[i + 1][j] + c[i][j]) % MOD;
            s[i + 1][j] = (s[i + 1][j] + s[i][j]) % MOD;
            // 在第 i 位插 1：popcount +1，数值 += 2^i
            c[i + 1][j + 1] = (c[i + 1][j + 1] + c[i][j]) % MOD;
            ll add = (s[i][j] + c[i][j] * ((1LL << i) % MOD)) % MOD;
            s[i + 1][j + 1] = (s[i + 1][j + 1] + add) % MOD;
        }
    }
}

// Panasonic Programming Contest 2025（AtCoder Beginner Contest 406）
/* E - Popcount Sum 3
 * link: https://atcoder.jp/contests/abc406/tasks/abc406_e
 * 思路:
 *   1. 预计算 c[i][j] 与 s[i][j]：
 *      - c[i][j] = |{0 ≤ x < 2^i 且 popcount(x)=j}|
 *      - s[i][j] = Σ{x | 0 ≤ x < 2^i 且 popcount(x)=j}
 *      用 DP 转移：在第 i 位插 0/1 两种情况，时间 O(N^2)，N≈63。
 *   2. 对每个测试 (n,k)，将 n 的二进制从高位到低位扫描，
 *      维护：
 *        cur    = 已“跟随”并置 1 的位数（已用 1 的个数）
 *        offset = 这些高位前缀构成的数值和
 *      每遇到一个 1 位：
 *        A) “断开”该位设 0：低 i 位凑 need=k-cur 个 1，
 *           贡献 = s[i][need] + offset * c[i][need]
 *        B) “跟随”该位设 1：cur++, offset += 2^i
 *   3. 扫完后若 cur==k，再加上 offset（即 n 本身）。
 *   4. 所有累加均对 MOD=998244353 取余。
 *   复杂度：O(63^2 + T·63)，足够快。
 */

void HuanF() {
    ll n, k;
    cin >> n >> k;
    vector<int> bit(N);
    for (int i = 0; i < N; ++i) {
        bit[i] = n >> i & 1;
    }
    ll ans = 0;
    ll offset = 0; // 已“跟随”高位的数值
    ll cur = 0; // 已“跟随”高位中 1 的个数
    for (int i = N - 1; i >= 0; --i) {
        if (bit[i]) {
            int need = k - cur;
            // 情况 A：断开第 i 位为 0，低 i 位凑 need 个 1
            if (need >= 0 && need <= i) {
                // 贡献 = s[i][need] + offset * c[i][need]
                (ans += s[i][need] + offset * c[i][need]) %= MOD;
            }
            // 情况 B：跟随第 i 位为 1
            ++cur;
            (offset += 1ll << i) %= MOD;
        }
    }
    // 如果完全跟随后恰有 k 个 1，则加上 n 本身
    if (cur == k) (ans += offset) %= MOD;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

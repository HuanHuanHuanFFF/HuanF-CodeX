//
// Created by 幻 on 2025/5/15.
//
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

/* C. 魔法五
 * link: https://codeforces.com/contest/628/problem/B
 * 思路:
 * 1 遍历原串位置 i 从 0 开始
 * 2 若 s[i]=='0' 或 '5' 则该位置可结尾
 * 3 单次串内 对应方案数为 2^i
 * 4 串重复 k 次 后 相同位置的贡献需乘上等比级数和
 *   公比 r=2^n mod M, 求和 S=(r^k -1)/(r-1) mod M
 * 5 最终答案为 sum(2^i * S) mod M
 * 时间复杂度 O(n + log(nk))
 * 空间复杂度 O(1)
 */
void HuanF() {
    string s;
    int k;
    cin >> s >> k;
    ll n = s.size();
    auto bpow = [&](ll x, ll y) {
        ll ans = 1;
        for (ll base = x; y; y >>= 1, base = base * base % MOD)
            if (y & 1) ans = ans * base % MOD;
        return ans;
    };
    ll a = bpow(2, n), b = bpow(2, n * k) - 1, inv = bpow(a - 1, MOD - 2);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' || s[i] == '5')
            ans = (ans + bpow(2, i) * b % MOD * inv % MOD) % MOD;
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

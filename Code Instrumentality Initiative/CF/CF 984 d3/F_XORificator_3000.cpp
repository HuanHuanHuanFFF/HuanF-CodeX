//
// Created by 幻 on 2025/7/16.
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
    // int ans = 0;
    // for (int i = 1; i <= 50; ++i) {
    //     ans ^= i;
    //     cout << i << " " << ans << endl;
    // }
}

constexpr bool more = true;

// Codeforces Round 984 (Div. 3) 
// F. XORificator 3000
// https://codeforces.com/contest/2036/problem/F
// 通过打表可以归纳出异或从0到n的公式
// 两次异或会抵消掉,先利用公式得出l到r的全部异或
// 计 m=1<<i ,对于 t*m+k 的无趣数,计l到r中包含cnt个
// 对于k,如果cnt为偶数则异或后k被抵消掉,如果为奇数则保留k与结果异或
// 对于前面的 t*m ,可以得知t一定是连续的,那么可以先计算连续的t的异或
// 最后再乘上m计算,即移位到高位,对结果的影响是一样的
// 计算l和r的t0,t1,以计算连续异或
// 注意当r<k时,不会有任何无趣数,而此时l和r都取到0,导致错误,把r变成-1
// 异或上所有的部分即为答案
void HuanF() {
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    auto f = [](ll n) -> ll {
        int m = n % 4;
        if (m == 0) return n;
        if (m == 1) return 1;
        if (m == 2) return n + 1;
        return 0;
    };
    auto xor_range = [&](ll l, ll r) { return f(l - 1) ^ f(r); };
    ll ans = xor_range(l, r);
    ll m = 1 << i;
    ll t0 = (l - k + m - 1) / m, t1;
    if (r < k) t1 = -1;
    else t1 = (r - k) / m;
    if (t0 <= t1) {
        ll cnt = t1 - t0 + 1;
        if (cnt & 1) ans ^= k;
        ans ^= xor_range(t0, t1) << i;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

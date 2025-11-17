//
// Created by 幻 on 2025/8/21.
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
constexpr ll MOD = 1e9 + 7;
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

vector<ll> sum(16);

void init() {
    IOS();
    ll p = 9;
    sum[1] = p;
    for (int i = 2; i < 16; ++i) {
        p *= 10;
        sum[i] = sum[i - 1] + p * i;
    }
}

constexpr bool more = true;

// Codeforces Round 1043 (Div. 3)
// D. From 1 to Infinity
/* From 1 to Infinity
 * link: https://codeforces.com/contest/2132/problem/D
 * 标签: 数位分块, 块定位, 按位计数, 数学
 * 思路:
 * 1. 预处理 sum[i]: 进入位长为 i 的数段前已用总位数 sum[1]=9, sum[i]=sum[i-1]+9*10^(i-1)*i
 * 2. 定位长度块: upper_bound(sum, k) 得 len 使 sum[len-1] < k <= sum[len], 令 k-=sum[len-1], 设 x=10^(len-1)
 * 3. 0基分桶再转回1基: n = x + (k-1)/len, r = (k-1)%len + 1
 *    说明: k 为1基而整除取模天然为0基, 用 k-1 可避免 r=0 的栅栏错误
 * 4. 数位和函数 g(m)=S(0..m): 对每位权 p=1,10,... 设 higher=m/(10p), cur=(m/p)%10, lower=m%p
 *    该位贡献 = higher*45*p + cur*(cur-1)/2*p + cur*(lower+1)
 *    证明: 每 10p 个数该位完成 0..9 循环各出现 p 次得 45p, 残留到 cur-1 各 p 次, cur 档出现 lower+1 次
 *    补零不影响和因补零位贡献为 0
 * 5. 答案 = g(n-1) + n 的前 r 位之和
 * 时间复杂度: O(log n)
 * 空间复杂度: O(1)
 */
void HuanF() {
    ll k;
    cin >> k;
    auto it = std::ranges::upper_bound(sum, k);
    --it;
    k -= *it;
    int len = int(it - sum.begin()) + 1;
    ll x = 1;
    for (int i = 1; i < len; ++i) {
        x *= 10;
    }
    ll n = x + (k - 1) / len, m = (k - 1) % len + 1;
    auto g = [](ll x) {
        ll ans = 0;
        for (ll p = 1; p <= x; p *= 10) {
            ll h = x / (p * 10), cur = x / p % 10, l = x % p;
            ans += h * 45 * p;
            ans += cur * (cur - 1) / 2 * p;
            ans += cur * (l + 1);
        }
        return ans;
    };
    ll ans = g(n - 1);
    string s = std::to_string(n);
    for (int i = 0; i < m; ++i) {
        ans += s[i] - '0';
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

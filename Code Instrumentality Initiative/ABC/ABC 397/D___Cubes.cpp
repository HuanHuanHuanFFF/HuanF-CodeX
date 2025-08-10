//
// Created by 幻 on 2025/8/8.
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
constexpr ll INF = 8e8 + 17;
constexpr ll N = 1e6 + 1;

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
}

constexpr bool more = false;

// OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397) 
/* D - Cubes
 * link: https://atcoder.jp/contests/abc397/tasks/abc397_d
 * 标签: 数学变形, 因子枚举, 二次方程, 单调性二分
 * 思路:
 * 设 x>y, 令 d=x-y, k=y
 * 则 N=x^3-y^3=(x-y)(x^2+xy+y^2)=d( (k+d)^2+k(k+d)+k^2 )=d(3k^2+3dk+d^2)
 * 因 x^2+xy+y^2≥(x-y)^2=d^2 ⇒ d^3≤N, 故仅需枚举 d∈[1,⌊N^{1/3}⌋] 且 d|N
 * 设 m=N/d, 对 f(k)=3k^2+3dk+d^2-m 求非负整数根 k
 * 因 f'(k)=6k+3d>0 (k≥0), f 单调递增 ⇒ 可二分判根; 若 f(k)=0 且 k>0, 则 (x,y)=(k+d,k)
 * 实现细节: 用 long long; 二分 mid 写成 (l+r)>>1 避免优先级错误; 仅当 f(l)==0 接受
 * 时间复杂度: O(N^{1/3} log N)
 * 空间复杂度: O(1)
 */
void HuanF() {
    ll n;
    cin >> n;

    // a(x^2)+bx+c=0
    auto solve = [](ll a, ll b, ll c) {
        ll l = 0, r = INF;
        while (l + 1 < r) {
            ll mid = l + r >> 1;
            if (a * mid * mid + b * mid + c <= 0) l = mid;
            else r = mid;
        }
        if (a * l * l + b * l + c == 0) return l;
        return -1ll;
    };

    // d=x-y   k=y
    // d^3+3k(d^2)+3(k^2)d=n
    // 3(k^2)+3kd+d^2-n/d=0
    // 枚举d求k
    for (ll d = 1; d * d * d <= n; ++d) {
        if (n % d != 0) continue;
        ll m = n / d;
        ll k = solve(3, 3 * d, d * d - m);
        if (k > 0) {
            cout << k + d << " " << k;
            return;
        }
    }
    cout << -1;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

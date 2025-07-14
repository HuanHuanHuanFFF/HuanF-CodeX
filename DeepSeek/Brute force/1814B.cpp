//
// Created by 幻 on 2025/7/14.
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
constexpr ll INF = 1e17 + 17;
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

// Educational Codeforces Round 146 (Rated for Div. 2) 
// B. Long Legs
// https://codeforces.com/contest/1814/problem/B
// 暴力这一块
// ans=x-1+(a+i-1)/x+(b+i-1)/x
// x-1增长的速率恒定是1,a/x的下降速率越来越慢
// 函数单调性不好判定,但是a/x,从1到2的时候就下降了一倍
// 而后面下降越来越慢,所以最小的x一定不会很大,考虑到t=100,直接枚举到1e6
// 时间间复杂度:O(t · 10^6)
// 证明:
/* 思路:
 *   令最终腿长为 x:
 *     先增长 x-1 次达到腿长 x
 *     然后按步长 x 在横纵方向跳跃，需 ceil(a/x) + ceil(b/x) 步
 *   得到离散函数 f(x) = (x-1) + ceil(a/x) + ceil(b/x)
 *   近似连续函数 g(x) = x-1 + (a+b)/x
 *   求导 g'(x) = 1 - (a+b)/x^2 = 0 → 极小点 x0 = √(a+b)
 *   g(x) 在 x<x0 时递减，x>x0 时递增；f(x) 与 g(x) 相差 O(1)
 *   因此 f 的最优解位于 x0 附近整数
 *   又 √(a+b) ≤ √(2·10^9) ≈ 4.5·10^4 ≪ 10^6
 *   故枚举 x ∈ [1,10^6] 必能覆盖最优点
 */
void HuanF() {
    ll a, b;
    cin >> a >> b;
    ll ans = INF;
    if (a < b) std::swap(a, b);
    for (int i = 1; i <= std::min(a, (ll) 1e6); ++i) {
        ll now = i - 1 + (a + i - 1) / i + (b + i - 1) / i;
        ans = std::min(ans, now);
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

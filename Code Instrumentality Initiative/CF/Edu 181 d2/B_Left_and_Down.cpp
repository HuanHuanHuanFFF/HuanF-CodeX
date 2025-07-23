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
using i128 = __int128;
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
/* 2125B
 * link: https://codeforces.com/problemset/problem/2125/B
 * 标签: 数论, 贪心
 * 思路:
 *   1 令 g = gcd(a,b)
 *   2 若 g * k >= a 且 g * k >= b, 则选择步长 (a/g,b/g) 重复 g 次可到达(ans=1)
 *      否则无法一步完成, 至少需两种步长(ans=2)
 * 时间复杂度 O(log min(a,b))
 * 空间复杂度 O(1)
 */
void HuanF() {
    ll a, b, k;
    cin >> a >> b >> k;
    i128 g = std::gcd(a, b);
    if (g * k < a || g * k < b)
        cout << "2\n";
    else cout << "1\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/23.
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

// Educational Codeforces Round 180 (Rated for Div. 2) 
/* C. Coloring Game
 * link: https://codeforces.com/problemset/problem/2112/C
 * 标签: 双指针、排序、枚举、计数
 * 思路:
 *  1. 题目等价于计数所有三元组 (i<j<k)，满足 a[i]+a[j]+a[k]>M 且 a[i]+a[j]>a[k]
 *  2. 设 M=a.back(), L=M-(a[i]+a[j]), R=a[i]+a[j]，需满足 L< a[k] < R
 *  3. 固定 i,j 后，用 l 从右向左收缩至第一个 a[l] ≤ L，用 r 从左向右推进至最后一个 a[r] < R
 *  4. 合法 k 在区间 (l, r] 中，排除 k≤j，通过 r - max(l,j) 累加计数
 * 时间复杂度 O(n^2)，空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = n - 1, r = 0;
        for (int j = i + 1; j < n; ++j) {
            while (l > j && a[i] + a[j] + a[l] > a.back()) --l;
            while (r + 1 < n && a[i] + a[j] > a[r + 1]) ++r;
            if (l < r) ans += r - std::max(l, j);
        }
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

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// 非官解
/* 1022A-Permutation Warm-Up
 * link: https://codeforces.com/contest/2108/problem/A
 * 思路:
 * 对于位置i最大偏移为abs((n-i+1)-i)
 * 将所有i的最大偏移累加得到fmax=\u2211_{i=1..n}abs(n-2i+1)
 * 任意交换只会使f值增减2的倍数因此f(p)在[0,fmax]的所有偶数值均可达到
 * 故不同f值个数= fmax/2 + 1
 * 时间复杂度O(n)
 * 空间复杂度O(1)
 */
void HuanF() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(n - i - i + 1);
    }
    cout << ans / 2 + 1 << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

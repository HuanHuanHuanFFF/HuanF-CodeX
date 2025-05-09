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

/* 2098B - Sasha and the Apartment Purchase
 * link: https://codeforces.com/contest/2098/problem/B
 * 思路:
 *   1 对酒吧位置数组 a 排序
 *   2 计算保留酒吧数量 m = n - k
 *   3 若 m 为奇数, 则 t = (m - 1) / 2, 可选区间 [a[t], a[t + k]]
 *      否则 t = m / 2, 可选区间 [a[t - 1], a[t + k]]
 *   4 答案为区间长度 = 右端 - 左端 + 1
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::sort(a.begin(), a.end());

    int m = n - k; // 保留的酒吧数量
    ll ans;
    if (m % 2 == 1) {
        // m = 2*t + 1
        int t = (m - 1) / 2;
        // 可选区间 [ a[t], a[t + k] ]
        ans = a[t + k] - a[t] + 1;
    } else {
        // m = 2*t
        int t = m / 2;
        // 可选区间 [ a[t-1], a[t + k] ]
        ans = a[t + k] - a[t - 1] + 1;
    }

    cout << ans << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

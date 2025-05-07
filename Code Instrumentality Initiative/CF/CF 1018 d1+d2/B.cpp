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

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* 1018B-精妙手套
 * link: https://codeforces.com/contest/2096/problem/B
 * 思路:
 * 1. 设 m = k - 1，用于表示最多允许的配对数（我们要在最坏情况下保证第 k 对出现）。
 * 2. 对每个颜色 i：
 *    - 计算 a[i] = max(l[i], r[i])，表示不形成配对时可拿的最大手套数。
 *    - 计算 b[i] = min(l[i], r[i])，表示可用于形成配对的剩余手套数。
 * 3. 初始 y = sum(a[i])，这是配对数为 0 时能拿的最大手套数。
 * 4. 将 b 数组降序排列，取前 m 个最大的 b[i] 累加到 y，表示在最多 m 对配对时能拿的最大手套数。
 * 5. 答案 x = y + 1，即再取一只手套，保证第 k 对配对必现。
 * 时间复杂度: O(n log n)  （排序开销）
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<ll> l(n), r(n), b(n);
    for (auto &x: l) cin >> x;
    for (auto &x: r) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x = std::max(l[i], r[i]);
        b[i] = std::min(l[i], r[i]);
        ans += x;
    }
    std::sort(b.begin(), b.end(), std::greater<>());
    for (int i = 0; i < k - 1; ++i) {
        ans += b[i];
    }
    cout << ans + 1 << "\n";
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

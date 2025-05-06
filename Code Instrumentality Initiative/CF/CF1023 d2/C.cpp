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
constexpr ll INF = 1e13;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* 2107C - Maximum Subarray Sum
 * link: https://codeforces.com/contest/2107/problem/C
 * 思路
 * 1 Kadane先算当所有si=0的位置填-INF时的最大子段和mx
 * 2 若mx>k 或 mx!=k且没有si=0的位置 则无解
 * 3 在任意一个si=0的位置pos
 *   3.1 扫描pos右侧 求最大前缀和r
 *   3.2 扫描pos左侧 求最大后缀和l
 *   3.3 将a[pos]=k-l-r 其余si=0的位置仍为-INF
 * 4 输出结果
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 */
void HuanF() {
    ll n, k, pos = -1;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (pos == -1)
                pos = i;
            a[i] = -INF;
        }
    }

    ll max = 0, now = 0;
    for (int i = 0; i < n; ++i) {
        now = std::max(a[i], now + a[i]);
        max = std::max(now, max);
    }
    if (max > k || max != k && pos == -1) {
        cout << "no\n";
        return;
    }
    if (pos != -1) {
        max = now = 0;
        ll l = 0, r = 0;
        for (int i = pos + 1; i < n; ++i) {
            now += a[i];
            max = std::max(now, max);
        }
        r = max;
        max = now = 0;
        for (int i = pos - 1; i >= 0; --i) {
            now += a[i];
            max = std::max(now, max);
        }
        l = max;
        a[pos] = k - l - r;
    }
    cout << "yes\n";
    for (auto &x: a) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

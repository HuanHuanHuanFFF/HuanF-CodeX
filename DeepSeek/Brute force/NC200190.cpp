//
// Created by 幻 on 2025/6/20.
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

constexpr bool more = false;

// 矩阵消除游戏
// https://ac.nowcoder.com/acm/problem/200190
// 暴力枚举 集合 贪心
// 枚举子集,2^n种选择行,然后再贪心选择列的,最后取最大值
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    vector a(n, vector<int>(m));
    vector<ll> sum(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
    }
    if (k >= n || k >= m) {
        cout << std::accumulate(sum.begin(), sum.end(), 0ll);
        return;
    }
    ll ans = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
        ll now = 0;
        int chose = __builtin_popcount(mask);
        if (chose > k) continue;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) now += sum[i];
        }
        int last = k - chose;
        vector<ll> s;
        s.reserve(m);
        for (int i = 0; i < m; ++i) {
            ll x = 0;
            for (int j = 0; j < n; ++j) {
                if (!(mask >> j & 1)) x += a[j][i];
            }
            s.emplace_back(x);
        }
        std::ranges::sort(s, std::greater<>());
        for (int i = 0; i < last; ++i) {
            now += s[i];
        }
        ans = std::max(ans, now);
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

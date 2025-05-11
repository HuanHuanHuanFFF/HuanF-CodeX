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

// https://codeforces.com/contest/2094/problem/E
// 先统计每一位,然后每个数去计算一次,最后比较记录答案
void HuanF() {
    int n;
    cin >> n;
    vector<ll> cnt(32), a;
    a.reserve(n);
    for (ll i = 0, x; i < n; ++i) {
        cin >> x;
        a.push_back(x);
        int idx = 0;
        while (x) {
            if (x & 1) ++cnt[idx];
            ++idx;
            x >>= 1;
        }
    }
    ll ans = 0;
    for (int k = 0; k < n; ++k) {
        ll now = 0, x = a[k];
        for (ll i = 0, base = 1; i < 32; ++i, base <<= 1) {
            if (x & 1) {
                now += (n - cnt[i]) * base;
            } else {
                now += cnt[i] * base;
            }
            x >>= 1;
        }
        if (now > ans) ans = now;
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

//
// Created by 幻 on 2025/6/27.
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

// Codeforces Round 995 (Div. 3) 
// D. Counting Pairs
// https://codeforces.com/contest/2051/problem/D
// 二分左右界,计数相加
void HuanF() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x: a) {
        cin >> x;
        sum += x;
    }
    std::ranges::sort(a);
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum -= a[i];
        int l = i, r = n;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (sum - a[mid] >= x) l = mid;
            else r = mid;
        }
        int p = l;
        l = i, r = n;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (sum - a[mid] <= y) r = mid;
            else l = mid;
        }
        ans += std::max(p - r + 1, 0);
        sum += a[i];
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

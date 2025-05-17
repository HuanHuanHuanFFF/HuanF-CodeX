//
// Created by 幻 on 2025/5/17.
//
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

void HuanF() {
    ll n, k;
    cin >> n >> k;
    ll l = -1, r = 1e9 + 17;
    if (n > k && n % k) l = 1;
    while (l + 1 < r) {
        ll mid = l + (r - l >> 1);
        if (mid * n >= k) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

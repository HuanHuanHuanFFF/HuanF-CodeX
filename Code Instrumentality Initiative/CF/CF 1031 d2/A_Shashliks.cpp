//
// Created by 幻 on 2025/6/15.
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

// Codeforces Round 1031 (Div. 2) 
// A. Shashliks
void HuanF() {
    ll k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    ll ans = 0;
    if (x < y) {
        if (k >= a)
            ans += (k - a + x) / x;
        k -= ans * x;
    } else if (x > y) {
        if (k >= b)
            ans += (k - b + y) / y;
        k -= ans * y;
    } else {
        if (k >= std::min(a, b))
            ans += (k - std::min(a, b) + x) / x;
        k -= ans * x;
    }
    if (k >= a)
        ans += (k - a + x) / x;
    if (k >= b)
        ans += (k - b + y) / y;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

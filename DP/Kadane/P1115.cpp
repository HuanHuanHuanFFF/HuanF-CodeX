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

// https://www.luogu.com.cn/problem/P1115
// 典中典之Kadane
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    ll ans = -INF, now = a[0];
    for (int i = 1; i < n; ++i) {
        now = std::max(now + a[i], a[i]);
        ans = std::max(ans, now);
    }
    cout << ans;
}

signed main() {
    IOS();
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

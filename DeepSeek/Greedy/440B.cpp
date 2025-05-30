//
// Created by 幻 on 2025/5/31.
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

// Testing Round 10 
// B. Balancer
// https://codeforces.com/problemset/problem/440/B
// what can i say?
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    auto sum = std::accumulate(a.begin(), a.end(), 0ll);
    ll k = sum / n, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > k) {
            ans += a[i] - k;
            a[i + 1] += a[i] - k;
            a[i] = k;
        }
        if (a[i] < k) {
            ans += k - a[i];
            a[i + 1] -= k - a[i];
            a[i] = k;
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/3.
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

vector<ll> f(13);

void init() {
    IOS();
    f[2] = f[1] = 1;
    for (int i = 3; i < 12; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

// Educational Codeforces Round 179 (Rated for Div. 2) 
// B. Fibonacci Cubes
// 斐波那契本来增长就快,更何况3次方,只用管最大的两个就行
// https://codeforces.com/contest/2111/problem/B
void HuanF() {
    ll n, m;
    cin >> n >> m;
    ll a = f[n + 1], b = f[n];
    for (ll i = 0, w, l, h; i < m; ++i) {
        cin >> w >> l >> h;
        ll maxl = std::ranges::max({w, l, h});
        ll minl = std::ranges::min({w, l, h});
        if (maxl >= a + b && minl >= a) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

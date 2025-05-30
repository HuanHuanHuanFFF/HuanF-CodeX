//
// Created by 幻 on 2025/5/29.
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

// Codeforces Round 1007 (Div. 2) 
// B. Perfecto
void HuanF() {
    ll n;
    cin >> n;
    ll k = floor(sqrt(n * (n + 1) / 2));
    if (k * k == n * (n + 1) / 2) {
        cout << -1 << "\n";
        return;
    }
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    ll sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += a[i];
        ll x = std::floor(sqrt(sum));
        if (x * x == sum) {
            sum -= a[i];
            sum += a[i + 1];
            std::swap(a[i], a[i + 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
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

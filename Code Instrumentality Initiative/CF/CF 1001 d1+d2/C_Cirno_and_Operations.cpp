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

constexpr bool more = true;

// Ethflow Round 1 (Codeforces Round 1001, Div. 1 + Div. 2) 
// C. Cirno and Operations
// 只有50个,如果逆序再转化,就会变成转化后的-sum,直接暴力枚举所有状态计算取最大值
// https://codeforces.com/contest/2062/problem/C
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    ll ans = std::accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            a[j] = a[j + 1] - a[j];
        }
        ll sum = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            sum += a[j];
        }
        sum = abs(sum);
        ans = std::max(ans, sum);
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

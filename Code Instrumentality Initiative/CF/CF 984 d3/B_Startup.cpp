//
// Created by 幻 on 2025/7/16.
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

// Codeforces Round 984 (Div. 3) 
// B. Startup
// https://codeforces.com/contest/2036/problem/B
// 排序
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> brand(k + 1);
    for (int i = 0, x, y; i < k; ++i) {
        cin >> x >> y;
        brand[x] += y;
    }
    std::ranges::sort(brand, std::greater<>());
    ll ans = 0;
    for (int i = 0; i <= std::min(k, n - 1); ++i) {
        ans += brand[i];
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

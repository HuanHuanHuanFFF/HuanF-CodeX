//
// Created by 幻 on 2025/7/17.
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

// Codeforces Round 1037 (Div. 3) 
// C. I Will Definitely Make It
// https://codeforces.com/contest/2126/problem/C
// 模拟
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &x: h) cin >> x;
    int now = h[k - 1];
    std::ranges::sort(h);
    auto p = std::ranges::lower_bound(h, now) - h.begin();
    int water = 1;
    for (int i = p; i < n - 1; ++i) {
        if (now - water + 1 < h[i + 1] - now) {
            cout << "NO\n";
            return;
        }
        water += h[i + 1] - now;
        now = h[i + 1];
    }
    cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

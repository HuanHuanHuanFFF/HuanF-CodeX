//
// Created by 幻 on 2025/7/27.
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

// Codeforces Round 1039 (Div. 2) 
// A. Recycling Center
// https://codeforces.com/contest/2128/problem/A
// 贪心 排序
// 大的不管,优先选离阈值最近的,维护一个倍数
void HuanF() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    std::ranges::sort(a, std::ranges::greater());
    int ans = 0, idx = n;
    ll p = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] > c) {
            ++ans;
        } else {
            idx = i;
            break;
        }
    }
    for (int i = idx; i < n; ++i) {
        if (a[i] * p <= c) {
            p <<= 1;
        } else {
            ++ans;
        }
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

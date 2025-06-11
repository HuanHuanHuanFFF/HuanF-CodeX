//
// Created by 幻 on 2025/6/7.
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

constexpr bool more = false;

// AtCoder Beginner Contest 409 
// C - Equilateral Triangle
// https://atcoder.jp/contests/abc409/tasks/abc409_c
// 模拟,乘法原理,计数
void HuanF() {
    int n, l;
    cin >> n >> l;
    vector<ll> cnt(l);
    cnt[0] = 1;
    int now = 0;
    if (l % 3 != 0) {
        cout << 0;
        return;
    }
    for (int i = 0, x; i < n - 1; ++i) {
        cin >> x;
        now = (now + x) % l;
        ++cnt[now];
    }
    ll ans = 0;
    for (int i = 0; i < l / 3; ++i) {
        ans += (cnt[i] * cnt[i + l / 3] * cnt[i + l / 3 + l / 3]);
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

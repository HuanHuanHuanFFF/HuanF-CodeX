//
// Created by 幻 on 2025/8/10.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = false;

// Tokio Marine & Nichido Fire Insurance Programming Contest 2025  (AtCoder Beginner Contest 402) 
// D - Line Crossing
// https://atcoder.jp/contests/abc402/tasks/abc402_d
// (Ai+Bi)%N后相同的平行
// 再用乘法原理计算 累加
void HuanF() {
    ll n, m;
    cin >> n >> m;
    std::map<int, ll> cnt;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        ++cnt[(x + y) % n];
    }
    ll ans = 0;
    for (auto &[x,y]: cnt) {
        ans += y * (m - y);
    }
    ans >>= 1;
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

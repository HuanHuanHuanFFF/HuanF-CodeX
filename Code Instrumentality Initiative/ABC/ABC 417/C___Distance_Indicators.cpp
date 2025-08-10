//
// Created by 幻 on 2025/8/2.
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

// AtCoder Beginner Contest 417 
// C - Distance Indicators
// https://atcoder.jp/contests/abc417/tasks/abc417_c
// j-i=Ai+Aj  ->  j-Aj=i+Ai
// 使用map记录这个值,然后扫一遍
void HuanF() {
    int n;
    cin >> n;
    std::map<int, int> cnt;
    ll ans = 0;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        ans += cnt[i - x];
        ++cnt[i + x];
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

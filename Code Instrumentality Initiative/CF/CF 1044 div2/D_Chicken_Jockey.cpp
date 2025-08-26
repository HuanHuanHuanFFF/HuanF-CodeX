//
// Created by 幻 on 2025/8/24.
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

constexpr bool more = true;

// Codeforces Round 1044 (Div. 2) 
// D. Chicken Jockey
// https://codeforces.com/contest/2133/problem/D
// DP
// 满足无后效性,定义打死高度为i以下的怪物最小值为dp[i]
// 对于每个高度大于2的怪物有两种情况
// 1.下面的怪物在最下面被打死,他受到1点伤害
// 2.当前怪物在最高(初始位置)时,下面的怪物被打死,受到最大的掉落伤害
// 取两个的小值
void HuanF() {
    int n;
    cin >> n;
    vector<ll> h(n), dp(n + 1);
    for (auto &x: h) cin >> x;
    dp[1] = h[0];
    for (int i = 1; i < n; ++i) {
        dp[i + 1] = std::min(dp[i] + h[i] - 1, dp[i - 1] + h[i - 1] + std::max(0ll, h[i] - i));
    }
    cout << dp[n] << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

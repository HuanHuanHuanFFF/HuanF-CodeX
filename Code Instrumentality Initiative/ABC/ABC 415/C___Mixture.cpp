//
// Created by 幻 on 2025/8/4.
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

constexpr bool more = true;

// Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415) 
// C - Mixture
// https://atcoder.jp/contests/abc415/tasks/abc415_c
// 状态DP
// 我们只需要关心到达当前状态的上一个状态是否可达就行
// 枚举所有状态
// 看这些状态是否能通过之前的某个状态得到
// 即是否能去掉某个1,通过加上这个1达到当前状态
// 同时过滤掉不安全的状态
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    std::set<int> unsafe;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') unsafe.insert(i + 1);
    }
    vector<bool> dp(1 << n);
    dp[0] = true;
    for (int mask = 1; mask < 1 << n; ++mask) {
        if (unsafe.contains(mask)) continue;
        for (int i = 0; i <= std::log2(mask); ++i) {
            if (mask >> i && dp[mask ^ 1 << i])
                dp[mask] = dp[mask ^ 1 << i];
        }
    }
    if (dp.back()) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

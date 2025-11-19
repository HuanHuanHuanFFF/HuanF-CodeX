//
// Created by 幻 on 2025/11/17.
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

// Codeforces Round 1059 (Div. 3) 
// B. Beautiful String
// https://codeforces.com/contest/2162/problem/B
// 去除全部的0或1后,剩下的一定是回文串
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ans.emplace_back(i + 1);
    }
    cout << ans.size() << "\n";
    for (auto &x: ans) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

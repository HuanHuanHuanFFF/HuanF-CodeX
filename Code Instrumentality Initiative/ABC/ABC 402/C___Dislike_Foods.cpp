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
// C - Dislike Foods
// https://atcoder.jp/contests/abc402/tasks/abc402_c
// 按查询不断更新就行
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > need(n + 1);
    vector<int> in(m);
    for (int i = 0, k, x; i < m; ++i) {
        cin >> k;
        in[i] = k;
        for (int j = 0; j < k; ++j) {
            cin >> x;
            need[x].emplace_back(i);
        }
    }
    int ans = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        for (auto &f: need[x])
            if (--in[f] == 0) ++ans;
        cout << ans << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

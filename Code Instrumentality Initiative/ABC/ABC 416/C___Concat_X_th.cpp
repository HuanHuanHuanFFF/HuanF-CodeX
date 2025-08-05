//
// Created by 幻 on 2025/7/26.
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

// AtCoder Beginner Contest 416 
// C - Concat (X-th)
// https://atcoder.jp/contests/abc416/tasks/abc416_c
// 全排列,DFS,暴力
void HuanF() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> ss(n);
    for (auto &s: ss) cin >> s;
    vector<string> ans;
    ans.reserve(pow(n, k));
    auto dfs = [&](auto &&self, int used, string now)-> void {
        if (used == k) {
            ans.emplace_back(now);
            return;
        }
        for (auto s: ss) {
            self(self, used + 1, now + s);
        }
    };
    for (auto s: ss) dfs(dfs, 1, s);
    std::ranges::sort(ans);
    cout << ans[x - 1];
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

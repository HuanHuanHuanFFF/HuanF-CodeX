//
// Created by 幻 on 2025/6/30.
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

// Codeforces Round 383 (Div. 1) 
// A. Arpa's loud Owf and Mehrdad's evil plan
// https://codeforces.com/problemset/problem/741/A
// 题目要求对所有人满足(我没读出来这个意思)
// 典中典有向基环树,但是不能有链,不然无法满足
// 最终答案是所有环环长的lcm
void HuanF() {
    int n;
    cin >> n;
    vector<int> to(n + 1), in(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> to[i];
        ++in[to[i]];
    }
    std::queue<int> q;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            cout << -1;
            return;
        }
    }
    auto dfs = [&](auto &&self, int x)-> int {
        vis[x] = true;
        if (!vis[to[x]])
            return self(self, to[x]) + 1;
        return 1;
    };
    vector<int> cyc;
    cyc.reserve(n);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            int now = dfs(dfs, i);
            if (now % 2 == 0) now >>= 1;
            cyc.emplace_back(now);
        }
    }
    ll ans = 1;
    for (auto &x: cyc) ans = std::lcm(x, ans);
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

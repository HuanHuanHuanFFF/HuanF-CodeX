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
// E - Pair Annihilation
// https://atcoder.jp/contests/abc409/tasks/abc409_e
// 如果都去最近能湮灭的点那么无论是移动正电子还是电子都一样
// 那么现在当前子树中进行湮灭,一定是最近的
// 如果子树中湮灭不完,就把剩下的移到父节点继续湮灭
// 这样可以保证一定都是在最近节点湮灭的
void HuanF() {
    int n;
    cin >> n;
    vector<ll> ele(n + 1);
    vector g(n + 1, vector<PII>());
    for (int i = 1; i <= n; ++i) {
        cin >> ele[i];
    }
    for (int i = 0, x, y, w; i < n - 1; ++i) {
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    vector<ll> ans(n + 1);
    auto dfs = [&](auto &&self, int x, int p)-> void {
        for (auto &[y,w]: g[x]) {
            if (y == p) continue;
            self(self, y, x);
            ele[x] += ele[y];
            ans[x] += std::abs(ele[y]) * w;
            ans[x] += ans[y];
        }
    };
    dfs(dfs, 1, 0);
    cout << ans[1];
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

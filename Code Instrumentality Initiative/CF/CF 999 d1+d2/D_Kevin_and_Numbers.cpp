//
// Created by 幻 on 2025/6/28.
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

constexpr bool more = true;

// IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2) 
// D. Kevin and Numbers
// https://codeforces.com/contest/2061/problem/D
// 如何合成b[i]?
// 注意到|x-y|<=1,就是说每个数必须由x/2的向上取整和向下取整合成而来
// 那么就可以分治地去看能否合成每个x/2的上下取整
void HuanF() {
    int n, m;
    cin >> n >> m;
    std::map<int, int> cnt;
    vector<int> b(m);
    ll suma = 0, sumb = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ++cnt[x];
        suma += x;
    }
    for (auto &x: b) {
        cin >> x;
        sumb += x;
    }
    if (suma != sumb) {
        cout << "No\n";
        return;
    }
    auto dfs = [&](auto &&self, int x)-> bool {
        if (cnt[x] > 0) {
            --cnt[x];
            return true;
        }
        if (x / 2 == 0) return false;
        return self(self, x / 2) && self(self, (x + 1) / 2);
    };
    for (int i = 0; i < m; ++i) {
        if (!dfs(dfs, b[i])) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

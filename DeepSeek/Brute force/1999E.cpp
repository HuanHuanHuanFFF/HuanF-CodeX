//
// Created by 幻 on 2025/6/25.
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
constexpr int N = 2e5 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> a(N), pre(N);

void init() {
    IOS();
    auto f = [&](int x) {
        int cnt = 0;
        while (x) {
            x /= 3;
            ++cnt;
        }
        return cnt;
    };
    for (int i = 1; i < N; ++i) {
        a[i] = f(i);
        pre[i] = pre[i - 1] + a[i];
    }
}

constexpr bool more = true;

// Codeforces Round 964 (Div. 4) 
// E. Triple Operations
// 前缀和加速查询
// https://codeforces.com/problemset/problem/1999/E
void HuanF() {
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] + a[l] << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/28.
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

// Codeforces Round 987 (Div. 2) 
// B. Penchick and Satay Sticks
// https://codeforces.com/problemset/problem/2031/B
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    vector<PII> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = {a[i], i};
    }
    std::ranges::sort(p);
    for (int i = 0; i < n; ++i) {
        if (abs(p[i].second - i) > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

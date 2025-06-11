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
// A - Conflict
// https://atcoder.jp/contests/abc409/tasks/abc409_a
void HuanF() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'o' && b[i] == 'o') {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

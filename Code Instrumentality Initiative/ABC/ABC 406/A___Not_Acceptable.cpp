//
// Created by 幻 on 2025/5/23.
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

// Panasonic Programming Contest 2025（AtCoder Beginner Contest 406） 
// A - Not Acceptable
// https://atcoder.jp/contests/abc406/tasks/abc406_a
void HuanF() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d <= b && c == a) cout << "Yes";
    else if (c < a) cout << "Yes";
    else cout << "No";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

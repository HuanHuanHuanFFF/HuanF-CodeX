//
// Created by 幻 on 2025/5/12.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// https://atcoder.jp/contests/abc405/tasks/abc405_a
void HuanF() {
    int r, x;
    cin >> r >> x;
    bool tag = false;
    if (x == 1 && r >= 1600 && r <= 2999) tag = true;
    if (x == 2 && r >= 1200 && r <= 2399) tag = true;
    cout << (tag ? "Yes" : "No");
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

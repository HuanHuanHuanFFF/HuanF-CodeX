//
// Created by 幻 on 2025/6/11.
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

// Codeforces Round 1004 (Div. 2) 
// A. Adjacent Digit Sums
void HuanF() {
    int x, y;
    cin >> x >> y;
    bool tag = false;
    if (y > x) {
        if (y - x == 1) tag = true;
    } else if ((x % 9 + 1) % 9 == y % 9) tag = true;
    cout << (tag ? "Yes" : "No") << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

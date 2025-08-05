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
// A - Vacation Validation
void HuanF() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;
    for (int i = l - 1; i < r; ++i) {
        if (s[i] != 'o') {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

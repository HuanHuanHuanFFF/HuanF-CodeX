//
// Created by 幻 on 2025/5/26.
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

// Codeforces Round  1027 (Div. 3) 
// A. Square Year
// 暴力枚举
void HuanF() {
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < 4; ++i) {
        x += (s[i] - '0') * pow(10, 3 - i);
    }
    for (int i = 0; i < 100; ++i) {
        if (i * i == x) {
            cout << i << " " << 0 << "\n";
            return;
        }
    }
    cout << "-1\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/16.
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

// Codeforces Round 984 (Div. 3) 
// C. Anya and 1100
// https://codeforces.com/contest/2036/problem/C
// 暴力 模拟
void HuanF() {
    string s;
    int q;
    cin >> s >> q;
    int cnt = 0;
    for (int i = 0; i < s.length() - 3; ++i) {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') ++cnt;
    }
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        --x;
        for (int j = 0; j <= std::min(x, 3); ++j) {
            if (x - j + 3 < s.length())
                if (s[x - j] == '1' && s[x - j + 1] == '1' && s[x - j + 2] == '0' && s[x - j + 3] == '0') --cnt;
        }
        s[x] = (char) ('0' + y);
        for (int j = 0; j <= std::min(x, 3); ++j) {
            if (x - j + 3 < s.length())
                if (s[x - j] == '1' && s[x - j + 1] == '1' && s[x - j + 2] == '0' && s[x - j + 3] == '0') ++cnt;
        }
        if (cnt > 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/2.
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

// Codeforces Round 295 (Div. 2) 
// A. Pangram
void HuanF() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> vis(26);
    for (int i = 0; i < n; ++i) {
        vis[tolower(s[i]) - 'a'] = true;
    }
    cout << (std::ranges::count(vis, false) == 0 ? "YES" : "NO");
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

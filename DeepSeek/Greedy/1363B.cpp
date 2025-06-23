//
// Created by 幻 on 2025/6/23.
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

// Codeforces Round 646 (Div. 2) 
// B. Subsequence Hate
// 枚举分割点 取最小
// https://codeforces.com/contest/1363/problem/B
void HuanF() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (s[i] == '1');
    }
    for (int i = n; i > 0; --i) {
        suf[i] = suf[i + 1] + (s[i - 1] == '1');
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int c10 = i - pre[i] + suf[i + 1];
        int c01 = pre[i] + n - i - suf[i + 1];
        ans = std::min({c10, c01, ans});
    }
    ans = std::min({ans, n - pre[n], pre[n]});
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

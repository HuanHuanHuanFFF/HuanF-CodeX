//
// Created by 幻 on 2025/6/8.
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

// Codeforces Round 962 (Div. 3) 
// C. Sort
// https://codeforces.com/contest/1996/problem/C
// 前缀和
void HuanF() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector cnt_a(n + 1, vector<int>(26));
    vector cnt_b(n + 1, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        char ca = a[i], cb = b[i];
        for (int j = 0; j < 26; ++j) {
            cnt_a[i + 1][j] = cnt_a[i][j];
            cnt_b[i + 1][j] = cnt_b[i][j];
        }
        ++cnt_a[i + 1][ca - 'a'];
        ++cnt_b[i + 1][cb - 'a'];
    }
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        int ans = 0;
        for (int j = 0; j < 26; ++j) {
            ans += std::abs(cnt_a[r][j] - cnt_a[l - 1][j] - (cnt_b[r][j] - cnt_b[l - 1][j]));
        }
        cout << ans / 2 << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

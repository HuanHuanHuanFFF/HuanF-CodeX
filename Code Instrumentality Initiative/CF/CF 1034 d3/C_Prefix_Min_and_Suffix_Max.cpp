//
// Created by 幻 on 2025/7/1.
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

// Codeforces Round 1034 (Div. 3) 
// C. Prefix Min and Suffix Max
// https://codeforces.com/contest/2123/problem/C
// 每次操作必须从头或者从尾到当前位置,所以必须是前缀最小值或者是后续最大值才行
//O(N)
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    pre[0] = INF;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = std::min(pre[i - 1], a[i]);
    }
    for (int i = n; i > 0; --i) {
        suf[i] = std::max(suf[i + 1], a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == suf[i] || a[i] == pre[i]) {
            cout << 1;
        } else cout << 0;
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

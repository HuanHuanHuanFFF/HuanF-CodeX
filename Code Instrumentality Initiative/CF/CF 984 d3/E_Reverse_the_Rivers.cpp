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

constexpr bool more = false;

// Codeforces Round 984 (Div. 3) 
// E. Reverse the River
// https://codeforces.com/contest/2036/problem/E
// 二分 位运算
// 注意! 或 导致只会单调递增
// 所以对每个条件进行二分,然后取交集的L
// 1600不存在你没学过的算法,如果不会那一定是没发现什么性质
void HuanF() {
    int n, k, q;
    cin >> n >> k >> q;
    vector a(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            cin >> a[i][j];
            a[i][j] |= a[i - 1][j];
        }
    }
    for (int i = 0, m; i < q; ++i) {
        cin >> m;
        int L = 1, R = n;
        for (int j = 0, re, c; j < m; ++j) {
            char x;
            cin >> re >> x >> c;
            bool big = true;
            if (x == '<') big = false;
            int l = L - 1, r = R + 1;
            while (l + 1 < r) {
                int mid = l + r >> 1;
                if (big) {
                    if (a[mid][re] > c) r = mid;
                    else l = mid;
                } else {
                    if (a[mid][re] < c) l = mid;
                    else r = mid;
                }
            }
            if (big) L = std::max(r, L);
            else R = std::min(l, R);
        }
        if (L <= R) cout << L << "\n";
        else cout << "-1\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

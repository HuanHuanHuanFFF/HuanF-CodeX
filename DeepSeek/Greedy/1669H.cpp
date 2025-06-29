//
// Created by 幻 on 2025/6/29.
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

// Codeforces Round 784 (Div. 4) 
// H. Maximal AND
// https://codeforces.com/problemset/problem/1669/H
// 贪心 位运算
// 需要每位都是1,这位才能计入答案
// 先统计每个位的1个数,然后再从最高位看能不能补满,计算答案
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(31);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        for (int j = 0; j <= 30 && x; ++j, x >>= 1) {
            if (x & 1) ++cnt[j];
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        if (n - cnt[i] <= k) {
            ans += 1 << i;
            k -= n - cnt[i];
        } else if (n == cnt[i])
            ans += 1 << i;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

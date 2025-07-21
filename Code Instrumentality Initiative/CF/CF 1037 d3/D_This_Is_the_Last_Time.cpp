//
// Created by 幻 on 2025/7/17.
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

// Codeforces Round 1037 (Div. 3) 
// D. This Is the Last Time
// https://codeforces.com/contest/2126/problem/D
// 贪心 排序
// 因为l<=real<=r
// 所以能变大就变大一定不会亏
// 按门槛排序,如果够门槛,一直real取最大值
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<std::array<int, 3> > cas(n);
    for (auto &[l,r,real]: cas) cin >> l >> r >> real;
    std::ranges::sort(cas);
    int ans = k;
    for (int i = 0; i < n; ++i) {
        if (ans >= cas[i][0] && ans <= cas[i][1])
            ans = std::max(ans, cas[i][2]);
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

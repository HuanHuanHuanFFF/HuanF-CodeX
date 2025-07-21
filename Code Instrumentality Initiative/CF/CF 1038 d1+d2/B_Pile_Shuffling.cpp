//
// Created by 幻 on 2025/7/19.
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

// Order Capital Round 1 (Codeforces Round 1038, Div. 1 + Div. 2) 
// B. Pile Shuffling
// https://codeforces.com/contest/2122/problem/B
// 我们不必关心当前堆缺少的情况,我们只关心当前堆多了,要拿出去需要移几次
// 如果需要移下面的1,那上面的0必定全都要动,已经动了,就不用管移到哪了
// 如果不移下面的1,那么就看需要移多少0
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] > d[i]) ans += a[i] + b[i] - d[i];
        else if (a[i] > c[i]) ans += a[i] - c[i];
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

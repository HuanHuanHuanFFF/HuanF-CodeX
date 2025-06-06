//
// Created by 幻 on 2025/6/3.
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
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Educational Codeforces Round 179 (Rated for Div. 2) 
// C. Equal Values
// https://codeforces.com/contest/2111/problem/C
// 压缩字段,一次计算  取最小值
void HuanF() {
    int n;
    cin >> n;
    vector<PII> a;
    for (ll i = 0, x; i < n; ++i) {
        cin >> x;
        if (a.empty() || x != a.back().first) {
            a.emplace_back(x, 1);
        } else ++a.back().second;
    }
    ll ans = INF;
    ll pre = 0;
    for (int i = 0; i < a.size(); ++i) {
        ll now = pre * a[i].first + (n - pre - a[i].second) * a[i].first;
        ans = std::min(now, ans);
        pre += a[i].second;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

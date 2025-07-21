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
// B. No Casino in the Mountains
// https://codeforces.com/contest/2126/problem/B
// 字段压缩然后模拟
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    vector<PII> p;
    p.reserve(n);
    p.emplace_back(a[0], 1);
    for (int i = 1; i < n; ++i) {
        if (a[i] != p.back().first) {
            p.emplace_back(a[i], 1);
        } else {
            ++p.back().second;
        }
    }
    int ans = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i].first == 0) {
            if (p[i].second == k) ++ans;
            else ans += p[i].second / (k + 1) + p[i].second % (k + 1) / k;
        }
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

//
// Created by 幻 on 2025/6/20.
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

// AtCoder Beginner Contest 410 
// A - G1
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int k, ans = 0;
    cin >> k;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= k)++ans;
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

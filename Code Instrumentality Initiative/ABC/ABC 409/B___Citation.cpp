//
// Created by 幻 on 2025/6/7.
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

// AtCoder Beginner Contest 409 
// B - Citation
// https://atcoder.jp/contests/abc409/tasks/abc409_b
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    std::map<int, int> cnt;
    for (auto &x: a) {
        cin >> x;
        ++cnt[x];
    }
    int ans = 0, pre = 0;
    vector<int> big(101, 0);
    for (auto &[x,y]: cnt) {
        for (int i = 0; i <= std::min(100, x); ++i) {
            big[i] += y;
        }
    }
    for (int i = 0; i <= 100; ++i) {
        if (big[i] >= i) ans = i;
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/21.
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

// UNIQUE VISION Programming Contest 2025 Summer (AtCoder Beginner Contest 411) 
// C - Black Intervals
// https://atcoder.jp/contests/abc411/tasks/abc411_c
// 模拟 联通 计数
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<bool> a(n + 1);
    int cnt = 0;
    for (int i = 0, x; i < q; ++i) {
        cin >> x;
        if (!a[x]) {
            ++cnt;
            if (x > 1 && a[x - 1]) --cnt;
            if (x < n && a[x + 1]) --cnt;
        } else {
            --cnt;
            if (x > 1 && a[x - 1]) ++cnt;
            if (x < n && a[x + 1]) ++cnt;
        }
        a[x] = a[x] ^ true;
        cout << cnt << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

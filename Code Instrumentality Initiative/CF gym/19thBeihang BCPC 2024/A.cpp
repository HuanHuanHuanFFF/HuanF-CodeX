//
// Created by 幻 on 2025/5/16.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// https://codeforces.com/gym/105615
void HuanF() {
    int x;
    cin >> x;
    ll ans = 0, max = 0;
    for (int i = 1; i < 2024; ++i) {
        int now = x * i % 2024;
        if (now > max) {
            max = now;
            ans = i;
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

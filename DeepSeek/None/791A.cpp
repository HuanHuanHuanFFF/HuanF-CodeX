//
// Created by 幻 on 2025/5/21.
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

// https://codeforces.com/problemset/problem/791/A
// 蚌埠住了,又在写水题
void HuanF() {
    int a, b;
    cin >> a >> b;
    ll ans = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        ++ans;
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

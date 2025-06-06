//
// Created by 幻 on 2025/6/5.
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

// Codeforces Round 1009 (Div. 3) 
// E. Empty Triangle
// https://codeforces.com/contest/2074/problem/E
// 三个依次换不行,两个依次换然后就过了,纯试
void HuanF() {
    int n;
    cin >> n;
    assert(n!=-1);
    int res, i = 1, j = 2, k = 3;
    cout << std::format("? {} {} {}", i, j, k) << endl;
    cin >> res;
    int cnt = 0;
    while (res) {
        if (cnt & 1) i = res;
        else j = res;
        cout << std::format("? {} {} {}", i, j, k) << endl;
        cin >> res;
        ++cnt;
    }
    cout << std::format("! {} {} {}", i, j, k) << endl;
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

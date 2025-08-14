//
// Created by 幻 on 2025/7/31.
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = true;

// Codeforces Round 1040 (Div. 2) 
// B. Pathless
// https://codeforces.com/contest/2130/problem/B
// 模拟 构造
void HuanF() {
    int n, s;
    cin >> n >> s;
    int cnt1 = 0, cnt2 = 0, cnt0 = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x == 1) ++cnt1;
        else if (x == 2) ++cnt2;
        else ++cnt0;
    }
    if (s == (cnt1 + cnt2 * 2) || s - (cnt1 + cnt2 * 2) >= 2) {
        cout << "-1";
    } else {
        for (int i = 0; i < cnt0; ++i) {
            cout << 0 << " ";
        }
        for (int i = 0; i < cnt2; ++i) {
            cout << 2 << " ";
        }
        for (int i = 0; i < cnt1; ++i) {
            cout << 1 << " ";
        }
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

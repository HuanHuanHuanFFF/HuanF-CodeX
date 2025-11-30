//
// Created by 幻 on 2025/11/20.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

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

// Codeforces Round 1065 (Div. 3) 
// C1. Renako Amaori and XOR Game (easy version)
// https://codeforces.com/contest/2171/problem/C1
// 1.如果a的异或和和b的异或和一样,那么一定会平局
// 2.谁能最后一个交换有用的下标,谁就一定能赢,因为之前的状态都已经确定了
void HuanF() {
    int n, s = 0, idx = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
        s ^= x;
    }
    for (auto &x: b) {
        cin >> x;
        s ^= x;
    }
    if (!s) {
        cout << "Tie\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] ^ b[i]) idx = i;
    }
    cout << (idx & 1 ? "Mai" : "Ajisai") << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

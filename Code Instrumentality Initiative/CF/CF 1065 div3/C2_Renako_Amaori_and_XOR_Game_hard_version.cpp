//
// Created by 幻 on 2025/11/30.
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
// C2. Renako Amaori and XOR Game (hard version)
// https://codeforces.com/contest/2171/problem/C2
// 1.如果a的异或和和b的异或和一样,那么一定会平局
// 2.全部异或后的留下的最高位,一定是能决定胜负的位
// 3.只用关心这个最高位,谁能决定最后一个拥有最高位的数字对,谁就一定能赢
void HuanF() {
    int n, s = 0, idx = 0, bit = 0;
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
    for (int i = 1, c = 0; i <= 1e6; i <<= 1, ++c) {
        if (s & i) bit = c;
    }
    for (int i = 0; i < n; ++i) {
        if ((a[i] ^ b[i]) & 1 << bit)
            idx = i;
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

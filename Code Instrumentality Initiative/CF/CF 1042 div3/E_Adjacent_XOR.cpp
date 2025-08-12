//
// Created by 幻 on 2025/8/10.
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

// Codeforces Round 1042 (Div. 3) 
// E. Adjacent XOR
// https://codeforces.com/contest/2131/problem/E
// a[n]必须等于b[n]
// a[i]!=b[i]时要么a[i]^a[i+1]=b[i]要么a[i]^b[i+1]=b[i]
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    if (b.back() != a.back()) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if ((a[i] ^ a[i + 1]) != b[i] && (a[i] ^ b[i + 1]) != b[i] && a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

//赛时写法
// void HuanF() {
//     int n;
//     cin >> n;
//     vector<int> a(n), b(n);
//     auto c = a;
//     for (auto &x: a) cin >> x;
//     for (auto &x: b) cin >> x;
//     if (a.back() != b.back()) {
//         cout << "NO\n";
//         return;
//     }
//     for (int i = n - 2; i >= 0; --i) {
//         if (a[i] != b[i]) {
//             c[i] = a[i] ^ a[i + 1];
//             if (c[i] != b[i]) {
//                 c[i] = a[i] ^ c[i + 1];
//                 if (c[i] != b[i]) {
//                     cout << "NO\n";
//                     return;
//                 }
//             }
//         }
//     }
//     cout << "YES\n";
// }

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

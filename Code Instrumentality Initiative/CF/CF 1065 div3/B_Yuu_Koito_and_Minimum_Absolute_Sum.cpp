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
// B. Yuu Koito and Minimum Absolute Sum
// https://codeforces.com/contest/2171/problem/B
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int ans;
    if (a.back() == -1 && a.front() == -1) {
        ans = 0;
        a.front() = a.back() = 0;
    } else if (a.back() == -1) {
        ans = 0;
        a.back() = a.front();
    } else if (a.front() == -1) {
        ans = 0;
        a.front() = a.back();
    } else {
        ans = abs(a.back() - a.front());
    }
    cout << ans << "\n";
    for (auto x: a) {
        if (x == -1) cout << 0 << " ";
        else cout << x << " ";
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

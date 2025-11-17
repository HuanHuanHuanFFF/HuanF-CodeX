//
// Created by 幻 on 2025/8/21.
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
constexpr ll N = 1e3 + 7;

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

vector<ll> p3(20), m3(20, 1);

void init() {
    IOS();
    p3[0] = 3;
    for (ll i = 1; i < 20; ++i) {
        m3[i] = 3 * m3[i - 1];
        p3[i] = 3 * m3[i] + i * m3[i - 1];
    }
}

constexpr bool more = true;

// Codeforces Round 1043 (Div. 3) 
// C1. The Cunning Seller (easy version)
// https://codeforces.com/contest/2132/problem/C1
// 二分 贪心
// 因为考虑最小的购买次数,所以要每次尽可能多买,但是不能多买
// 所以每次买最多的,三进制肯定能表示所有的数
void HuanF() {
    int n;
    cin >> n;
    ll ans = 0;
    while (n) {
        auto it = std::ranges::upper_bound(m3, n);
        --it;
        n -= *it;
        int idx = it - m3.begin();
        ans += p3[idx];
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

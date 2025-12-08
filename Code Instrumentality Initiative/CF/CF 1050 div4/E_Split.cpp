//
// Created by 幻 on 2025/12/8.
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

// Codeforces Round 1050 (Div. 4) 
// E. Split
// https://codeforces.com/contest/2148/problem/E
// 只要所有值都能平分到每个多重集里,那么一定存在
// 内部的会被分到集合1里,外部的随便分
// 那么只要保证内部的都小于平分数量,就一定有可能变为cool数组
// 用双指针可以统计数量
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    std::map<int, int> cnt, rcnt;
    for (auto &x: a) {
        cin >> x;
        ++cnt[x];
    }
    for (auto &[x,y]: cnt) {
        if (y % k) {
            cout << "0\n";
            return;
        }
        y /= k;
    }
    ll ans = 0;
    for (int l = 0, r = 0; l <= r && r < n; ++r) {
        ++rcnt[a[r]];
        while (rcnt[a[r]] > cnt[a[r]])
            --rcnt[a[l++]];
        ans += r - l + 1;
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

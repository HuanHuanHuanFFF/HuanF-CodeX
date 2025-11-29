//
// Created by 幻 on 2025/11/23.
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
constexpr ll INF = 1e17 + 17;
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

// Codeforces Round 1066 (Div. 1 + Div. 2) 
// D. Billion Players Game
// https://codeforces.com/contest/2157/problem/D
// 三分,数学
void HuanF() {
    int n;
    double l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    // for (int x = l; x <= r; ++x) {
    //     int fx = 0;
    //     for (int i = 0; i < n; ++i) {
    //         fx += abs(a[i] - x);
    //     }
    //     cout << "x:" << x << " fx:" << fx << "\n";
    // }
    auto f = [&](double x) {
        double fx = 0;
        for (int i = 0; i < n; ++i) {
            fx += abs(x - a[i]);
        }
        return fx;
    };
    while (l + 1e-7 < r) {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    double ans = f(r);
    if (ceil(ans) - ans < ans - floor(ans)) ans = ceil(ans);
    else ans = floor(ans);
    cout << (ll) ans << "\n";
}

void HuanF2() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::ranges::sort(a);
    int m = a[n / 2], x;
    ll ans = 0;
    if (m < l) x = l;
    else if (m > r) x = r;
    else x = m;
    for (int i = 0; i < n; ++i) {
        ans += abs(x - a[i]);
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF2();
    return 0;
}

/*
1
7 1 20
1 2 5 7 9 13 17
x:1 fx:47
x:2 fx:42
x:3 fx:39
x:4 fx:36
x:5 fx:33
x:6 fx:32
x:7 fx:31
x:8 fx:32
x:9 fx:33
x:10 fx:36
x:11 fx:39
x:12 fx:42
x:13 fx:45
x:14 fx:50
x:15 fx:55
x:16 fx:60
x:17 fx:65
x:18 fx:72
x:19 fx:79
x:20 fx:86
*/

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
// C. Pacer
// https://codeforces.com/contest/2148/problem/C
// 如果能动我就一直跑,这样得分最多
// 按位置和奇偶分别考虑
void HuanF() {
    int n, m, ans = 0, a = 0, b, now = 0;
    cin >> n >> m;
    for (int i = 0, x; i < n; ++i) {
        cin >> x >> b;
        int d = x - a;
        if (b == now)
            if (d & 1) ans += d - 1;
            else ans += d;
        else {
            if (d & 1) ans += d;
            else ans += d - 1;
        }
        a = x;
        now = b;
    }
    ans += m - a;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

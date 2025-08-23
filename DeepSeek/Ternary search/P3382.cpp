//
// Created by 幻 on 2025/8/23.
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

constexpr bool more = false;

// P3382 三分
void HuanF() {
    int n;
    ld l, r;
    cin >> n >> l >> r;
    vector<ld> a(n + 1);
    for (int i = n; i >= 0; --i) {
        cin >> a[i];
    }
    auto f = [&](ld x) {
        ld ans = 0, m = 1;
        for (int i = 0; i <= n; ++i) {
            ans += m * a[i];
            m *= x;
        }
        return ans;
    };
    while (l + 1e-7 < r) {
        ld m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) l = m1;
        else r = m2;
    }
    cout << std::format("{:.5f}", (l + r) / 2);
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/8/16.
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

// AtCoder Beginner Contest 419 
// C - King's Summit
void HuanF() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    std::ranges::sort(x);
    std::ranges::sort(y);

    auto check = [&](int m) {
        int l = 0, r = INF;
        for (int i = 0; i < n; ++i) {
            int xl = x[i] - m, xr = x[i] + m;
            l = std::max(l, xl);
            r = std::min(r, xr);
            if (l > r) return false;
        }
        l = 0, r = INF;
        for (int i = 0; i < n; ++i) {
            int yl = y[i] - m, yr = y[i] + m;
            l = std::max(l, yl);
            r = std::min(r, yr);
            if (l > r) return false;
        }
        return true;
    };

    int l = -1, r = INF;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2026/4/25.
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

// Ｓｋｙ Inc, Programming Contest 2026 (AtCoder Beginner Contest 455) 
// C - Vanish
void HuanF() {
    int n, k;
    cin >> n >> k;
    std::map<ll, ll> sum;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        sum[x] += x;
    }
    vector<ll> a;
    for (auto &[x,y]: sum)
        a.emplace_back(y);
    std::ranges::sort(a);
    ll ans = 0;
    for (int i = 0; i < (int) a.size() - k; ++i) {
        ans += a[i];
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

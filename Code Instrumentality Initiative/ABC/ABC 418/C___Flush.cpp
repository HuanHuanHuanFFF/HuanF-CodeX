//
// Created by 幻 on 2025/8/9.
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

// AtCoder Beginner Contest 418 
// C - Flush
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    std::map<ll, ll> cnt, pre_cnt, pre_sum;
    for (auto &x: a) {
        cin >> x;
        ++cnt[x];
    }
    ll now = 0, pc = 0, max = std::ranges::max(a);
    pre_cnt[0] = pre_sum[0] = 0;
    for (auto [x,y]: cnt) {
        now += x * y;
        pc += y;
        pre_cnt[x] = pc;
        pre_sum[x] = now;
    }
    while (q--) {
        ll b;
        cin >> b;
        if (b > max) {
            cout << -1 << "\n";
            continue;
        }
        auto it = pre_sum.lower_bound(b);
        --it;
        ll ans = 0;
        ans += it->second;
        ans += (n - pre_cnt[it->first]) * (b - 1) + 1;
        cout << ans << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

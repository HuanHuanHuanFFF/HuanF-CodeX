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
// C2. The Cunning Seller (hard version)
// https://codeforces.com/contest/2132/problem/C2
// 贪心 二分
// 先和1一样的策略去买,这样是满足的最少交易次数
// 然后可以注意到买x个西瓜的性价比 f(x)=3^(x+1)+x*3^(x-1)/3^x
// 是一个单调递增函数
// 所以分多次买便宜的一定更少
void HuanF() {
    int n, k;
    cin >> n >> k;
    std::map<ll, int> cnt;
    ll ans = 0;
    while (n) {
        auto it = std::ranges::upper_bound(m3, n);
        --it;
        n -= *it;
        int idx = it - m3.begin();
        ++cnt[idx];
        --k;
    }
    if (k < 0) {
        cout << "-1\n";
        return;
    }
    while (k) {
        auto it = cnt.rbegin();
        auto [x,y] = *it;
        if (x == 0) break;
        if (k >= y * 2) {
            k -= y * 2;
            cnt.erase(x);
            cnt[x - 1] += 3 * y;
        } else {
            cnt[x] -= k / 2;
            cnt[x - 1] += 3 * (k / 2);
            break;
        }
    }
    for (auto &[x,y]: cnt) ans += p3[x] * y;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

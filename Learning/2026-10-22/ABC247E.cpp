//
// Created by 幻 on 2026/10/22.
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

/* ABC247-E - Max Min
 * link: https://atcoder.jp/contests/abc247/tasks/abc247_e
 * 标签: 区间计数, 枚举右端点, 最近出现位置
 * 思路: 记录 X、Y 最近出现的位置 x、y, 以及最近越界位置 ex。
 * 固定右端点时, 合法左端点满足 ex < l <= min(x,y), 两端值均出现后累加贡献。
 * 时间复杂度: O(n), 空间复杂度: O(n)
 */
void HuanF() {
    ll n, mi, mx, ans = 0;
    cin >> n >> mx >> mi;
    vector<ll> a(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    ll x = INF, y = INF, ex = 0;
    for (ll r = 1; r <= n; ++r) {
        if (a[r] < mi || a[r] > mx) {
            ex = r;
        }
        if (a[r] == mi) {
            x = r;
        }
        if (a[r] == mx) {
            y = r;
        }
        if (r >= x && r >= y && x >= ex && y >= ex) {
            ll l = std::min(x, y);
            ans += l - ex;
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

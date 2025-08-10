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

// AtCoder Beginner Contest 412
/* 素数幂计数 分段筛
 * link:
 * 标签: 分段筛, 素数幂, 数论, 枚举倍数
 * 思路:
 * 本质: 统计区间 [l,r] 内 x 是否为素数幂 p^k
 * 1 预处理: 筛出所有质数 p ≤ ⌊sqrt(r)⌋
 * 2 枚举倍数: 对每个 p, 从 s=(l/p+1)*p 起, 依次枚举 i∈(l,r] 且 i≡0(mod p)
 *    用 vis[i-l] 标记该 i 已由某个小素因子触达; 仅在首次触达时, 将 i 连续除以 p
 *    若能除到 1, 说明 i=p^k, 计入答案
 * 3 扫尾: 遍历 vis, 仍为 0 的位置对应 [l,r] 中没有任何 ≤sqrt(r) 因子的数
 *    只能是大质数 p>sqrt(r) 的 p^1, 计入答案
 * 证明要点: 若合数没有 ≤sqrt(r) 的因子, 则两因子皆 >sqrt(r), 乘积 > r 矛盾
 * 时间复杂度: O(sqrt(r)·log log r + (r-l+1)·log log r)
 * 空间复杂度: O(r-l+1)
 */
void HuanF() {
    ll l, r;
    cin >> l >> r;
    int cap = (int) std::sqrt(r) + 1;
    vector<ll> p;
    p.reserve(cap / std::log(cap));
    std::bitset<N> isp;
    isp.set();
    for (ll i = 2; i * i <= r; ++i) {
        if (isp[i]) {
            p.emplace_back(i);
            for (ll j = i << 1; j <= cap; j += i)
                isp[j] = false;
        }
    }
    ll ans = 0;
    vector<bool> vis(r - l + 1);
    for (auto &x: p) {
        for (ll i = (l / x + 1) * x; i <= r; i += x) {
            if (vis[i - l]) continue;
            vis[i - l] = true;
            ll y = i;
            while (y % x == 0)y /= x;
            if (y == 1) ++ans;
        }
    }
    for (auto v: vis)
        if (!v) ++ans;
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

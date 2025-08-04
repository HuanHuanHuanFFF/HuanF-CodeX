//
// Created by 幻 on 2025/8/4.
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
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

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

// Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415) 
/* D - 获得大量徽章
 * link: https://atcoder.jp/contests/abc415/tasks/abc415_d
 * 标签: 贪心, 排序, 模拟
 * 思路:
 * 1. 对每种兑换操作，计算“净消耗”空瓶数 c = a – b，收益恒为 1 枚徽章
 * 2. 为了在有限的 n 个空瓶内获得最多徽章，应优先使用 c 最小的操作
 * 3. 将所有 (b, a) 对按 c 升序（若 c 相同，则按 a 升序）排序
 * 4. 依次遍历每种操作：
 *    - 若 a > n，则无法执行，跳过
 *    - 否则最多执行 x = ⌊(n – a) / c⌋ + 1 次
 *      • 徽章数 += x  
 *      • 空瓶数 n -= c * x
 *
 * 时间复杂度: O(M log M)
 * 空间复杂度: O(M)
 */
void HuanF() {
    ll n, m;
    cin >> n >> m;
    vector<PII> ab;
    ab.reserve(m);
    std::map<ll, ll> st;
    for (ll i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        if (st.contains(b))
            st[b] = std::min(st[b], a);
        else st[b] = a;
    }
    for (auto &[x,y]: st)
        ab.emplace_back(x, y);
    std::ranges::sort(ab, [](auto a, auto b) {
        if (a.second - a.first == b.second - b.first) return a.second < b.second;
        return a.second - a.first < b.second - b.first;
    });
    ll ans = 0;
    for (auto [b, a]: ab) {
        if (a > n) continue;
        ll x = (n - a) / (a - b) + 1;
        ans += x;
        n -= (a - b) * x;
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

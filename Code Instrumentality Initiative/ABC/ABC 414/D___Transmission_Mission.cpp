//
// Created by 幻 on 2025/8/5.
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

// Mirrativ Programming Contest 2025 (AtCoder Beginner Contest 414) 
/* D - 传输任务
 * link: https://atcoder.jp/contests/abc414/tasks/abc414_d
 * 标签: 区间覆盖、排序、贪心
 * 思路:
 *   1 对坐标升序排序
 *   2 计算所有相邻点差值并按降序排列
 *   3 用总跨度减去最大的 M−1 个差值之和
 * 时间复杂度: O(N log N)
 * 空间复杂度: O(N)
 */
void HuanF() {
    int m, n;
    cin >> n >> m;
    if (m >= n) {
        cout << 0;
        return;
    }
    vector<ll> a(n), d;
    d.reserve(n - 1);
    for (auto &x: a) cin >> x;
    std::ranges::sort(a);
    for (int i = 0; i < n - 1; ++i) {
        d.emplace_back(a[i + 1] - a[i]);
    }
    std::ranges::sort(d, std::ranges::greater());
    ll ans = a.back() - a.front();
    for (int i = 0; i < m - 1; ++i) {
        ans -= d[i];
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

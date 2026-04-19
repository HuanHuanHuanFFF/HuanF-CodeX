//
// Created by 幻 on 2026/4/19.
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

struct BIT {
    vector<int> t;
    int n;

    BIT(int n): t(n + 1), n(n) {
    }

    int lowbit(int x) { return x & -x; }

    void set(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            t[i] = std::max(t[i], x);
        }
    }

    int get(int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            ans = std::max(ans, t[i]);
        }
        return ans;
    }
};

constexpr bool more = false;


/* P1439-最长公共子序列
 * link: https://www.luogu.com.cn/problem/P1439
 * 标签: LCS转LIS, 树状数组, DP
 * 思路:
 * 两个序列都是排列, 每个值在 b 中的位置唯一. 先记录 p[x] 表示 x 在 b 中的下标, 再把 a 中每个值替换为它在 b 中的下标.
 * 这样原问题就转成了求新数组的 LIS. 因为公共子序列要求两边相对顺序一致, 等价于这些值在 b 中的下标严格递增.
 * 设 dp[v] 表示"以值 v 结尾的 LIS 长度", 则转移为:
 * dp[v] = max(dp[u]) + 1, u < v
 * 也就是查询值域前缀最大值, 所以可以用树状数组维护前缀 max, 把复杂度优化到 O(n log n).
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    BIT dp(n);
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    std::map<int, int> p;
    for (int i = 0; i < n; ++i) p[b[i]] = i + 1;
    for (auto &x: a) x = p[x];
    for (int i = 1; i <= n; ++i)
        dp.set(a[i - 1], dp.get(a[i - 1]) + 1);
    cout << dp.get(n) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

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
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e17 + 17;
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

// AtCoder Beginner Contest 416 
/* ABC416-F
 * link: https://atcoder.jp/contests/abc416/tasks/abc416_f
 * 标签: 树形DP, 背包DP, 三状态DP
 *
 * 状态定义:
 *   d0[i]: 当前子树选了 i 条路径，且无任何开放端点经过当前节点
 *   d1[i]: 当前子树选了 i 条路径，且有一个开放端点在当前节点等待延伸
 *   d2[i]: 当前子树选了 i 条路径，且有一条路径的两端已在子树内闭合，不会再经过当前节点
 *
 * 状态转移（合并子树 y）:
 *   令子树返回 (ld0, ld1)，分别为子树的 d0, d1
 *   对所有 0 ≤ i, j ≤ k:
 *     1. 无端点 + 无端点 → 无端点:
 *        nd0[i+j] = max(nd0[i+j], d0[i] + ld0[j])
 *     2. 无端点 + 一端点 → 延伸为一端点:
 *        nd1[i+j] = max(nd1[i+j], d0[i] + ld1[j] + a[x])
 *     3. 有端点 + 无端点 → 保持一端点:
 *        nd1[i+j] = max(nd1[i+j], d1[i] + ld0[j])
 *     4. 有端点 + 有端点 →
 *        4.1 不闭合（仍为一端点）:
 *            nd1[i+j] = max(nd1[i+j], d1[i] + ld1[j])
 *        4.2 闭合（两端在此相遇，路径数减 1）:
 *            nd2[i+j-1] = max(nd2[i+j-1], d1[i] + ld1[j])
 *     5. 已闭合 + (无/有端点) → 保持闭合:
 *        nd2[i+j] = max(nd2[i+j], d2[i] + ld0[j], d2[i] + ld1[j])
 *
 * 子树合并完成后:
 *   - 新开一条端点: 对 1 ≤ i ≤ k:
 *       d1[i] = max(d1[i], d0[i-1] + a[x])
 *   - 取全局最优: 对 0 ≤ i ≤ k:
 *       d0[i] = max({d0[i], d1[i], d2[i]})
 *
 * 时间复杂度: O(n * k^2)
 * 空间复杂度: O(n * k)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<vector<int> > g(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    auto dfs = [&](auto self, int x, int p) -> pair<vector<ll>, vector<ll> > {
        vector<ll> d0(k + 1, -INF), d1(k + 1, -INF), d2(k + 1, -INF);
        d0[0] = 0;
        for (auto &y: g[x]) {
            if (y == p) continue;
            auto [ld0,ld1] = self(self, y, x);
            vector<ll> nd0(k + 1, -INF), nd1(k + 1, -INF), nd2(k + 1, -INF);
            for (int i = 0; i <= k; ++i) {
                for (int j = 0; j <= k; ++j) {
                    if (i + j <= k) {
                        nd0[i + j] = std::max(nd0[i + j], d0[i] + ld0[j]);
                        nd1[i + j] = std::max({
                            nd1[i + j], d0[i] + ld1[j] + a[x],
                            d1[i] + ld0[j], d1[i] + ld1[j]
                        });
                        nd2[i + j] = std::max({nd2[i + j], d2[i] + ld0[j], d2[i] + ld1[j]});
                    }
                    if (i + j - 1 >= 0 && i + j - 1 <= k) {
                        nd2[i + j - 1] = std::max(nd2[i + j - 1], d1[i] + ld1[j]);
                    }
                }
            }
            d0.swap(nd0);
            d1.swap(nd1);
            d2.swap(nd2);
        }
        for (int i = 1; i <= k; ++i) {
            d1[i] = std::max(d1[i], d0[i - 1] + a[x]);
        }
        for (int i = 0; i <= k; ++i) {
            d0[i] = std::max({d0[i], d1[i], d2[i]});
        }
        return {d0, d1};
    };
    auto [d0,d1] = dfs(dfs, 1, 0);
    cout << std::ranges::max(d0) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

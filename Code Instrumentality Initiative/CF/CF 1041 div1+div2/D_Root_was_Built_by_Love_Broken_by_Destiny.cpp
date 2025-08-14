//
// Created by 幻 on 2025/8/7.
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
constexpr ll N = 2e5 + 7;

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

vector<ll> fac(N, 1);

void init() {
    IOS();
    for (ll i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

constexpr bool more = true;

// Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2) 
/* 2127D - Root was Built by Love, Broken by Destiny
 * link: https://codeforces.com/contest/2127/problem/D
 * 标签: 结构识别(毛毛虫树), 计数, 阶乘, 度数分类
 * 思路:
 * 1) 必要条件: 能在两岸直线不交叉摆放 ⇔ 图为毛毛虫树:
 *    - 必为树(有环则不可) → 本实现用 m>=n 先剪枝(更严谨可判 m!=n-1)。
 *    - 任一非叶顶点的“非叶邻居数”≤2。否则出现禁图(必交叉)。
 * 2) 计数: 删叶后脊柱为路径。设对每个非叶 x, 有 leaf(x) 个叶子与其相邻,
 *    则这些叶在对岸相对顺序任意 → 贡献 (leaf(x))!。
 *    全局对称因子:
 *      - 若脊柱长度≥2: 4 (上下互换×左右翻转)；
 *      - 若脊柱长度≤1(星或单边): 2。
 * 3) 实现:
 *    - 遍历每个点 x:
 *        * 若 deg(x)>1(非叶): 统计 leaf=相邻叶子个数。
 *          若 leaf < deg(x)-2 → 非叶邻居≥3 → 不可，ans=0。
 *          否则 ans*=fac[leaf]。
 *        * 否则计叶子数 l++。
 *    - 依据叶子数判断脊柱长度(= n-l):
 *        * 若 n-l ≥ 2 → 乘 2，使常数因子变为 4；否则乘 1，使常数因子为 2。
 * 4) 复杂度: O(n)。
 * 证明要点:
 * - “非叶邻居≤2 ⇔ 删叶后为路径”；
 * - 各节点叶子块独立排列 → 乘阶乘；
 * - 全局仅剩两种对称(上下、左右) → 2 或 4。
 */
void HuanF() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    ll ans = 2, l = 0;
    if (m >= n) ans = 0;
    for (int x = 1; x <= n; ++x) {
        if (g[x].size() > 1) {
            int leaf = 0;
            for (auto &y: g[x])
                if (g[y].size() == 1) ++leaf;
            if (leaf < g[x].size() - 2) ans = 0;
            else ans = ans * fac[leaf] % MOD;
        } else ++l;
    }
    if (l < n - 1) l = 2;
    else l = 1;
    ans = ans * l % MOD;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

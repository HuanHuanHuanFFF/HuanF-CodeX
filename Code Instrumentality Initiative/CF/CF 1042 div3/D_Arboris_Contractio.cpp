//
// Created by 幻 on 2025/8/10.
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

constexpr bool more = true;

// Codeforces Round 1042 (Div. 3) 
/* 2131D - Arboris Contractio
 * link: https://codeforces.com/contest/2131/problem/D
 * 标签: 树直径, 贪心, 计数, 构造
 * 思路:
 * 1. 目标是把直径最小化, n>2 的最小直径为 2
 * 2. 固定最终根 r 后, 一次操作选 r 到某点的简单路径并把整条路径收拢到 r
 *    每次至多使一个距离>1 的叶子成为 r 的直接孩子
 * 3. 若全树叶子数为 all, 与 r 相邻的叶子数为 d1(r), 且若 r 自身是叶也算已就位
 *    则至少需要 all - d1(r) - [r 是叶] 次; 对每个远叶各做一次 r→leaf 的操作可达上界
 * 4. 因此对所有 r 取最小等价于最大化 d1(r)+[r 是叶]
 * 5. 统计:
 *    all = 叶子总数
 *    cnt[x] = 与 x 相邻的叶子数
 *    leaf[x] = x 是否叶
 *    根度为 1 的特判: leaf[root]=1 且把它唯一相邻点的 cnt++
 * 6. 答案 = min_i(all - cnt[i] - leaf[i]) = all - max_i(cnt[i] + leaf[i])
 * 证明要点:
 * 下界: 一次操作的路径中只有一个叶, 故每次最多新增一个 r 的孩子叶
 * 上界: 依次对每个远叶进行 r→leaf 的路径操作, 最终星形, 直径=2
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int> cnt(n + 1), leaf(n + 1);
    int all = 0;
    auto dfs = [&](auto &&self, int x, int p)-> int {
        int c = 0;
        for (auto &y: g[x]) {
            if (y == p) continue;
            cnt[x] += self(self, y, x);
            ++c;
        }
        if (c == 0) {
            ++all;
            leaf[x] = 1;
            return 1;
        }
        if (x == 1 && c == 1) {
            leaf[x] = 1;
            ++cnt[g[x].front()];
            ++all;
        }
        return 0;
    };
    dfs(dfs, 1, 0);
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == all) ans = 0;
        ans = std::min(all - cnt[i] - leaf[i], ans);
    }
    cout << ans << "\n";
}

/* 2131D - Arboris Contractio
 * link: https://codeforces.com/contest/2131/problem/D
 * 标签: 树, 直径最小化, 计数
 * 思路:
 * 目标: n>2 时最小直径为2。固定最终根 r, 一次操作最多把一个距离>1的叶变成 r 的孩子
 * ⇒ 固定 r 的最少操作数 = 叶子总数 all - (与 r 相邻的叶数 d1(r) + [r 是叶])
 * 本实现做法: 统计度数 deg; all=度为1的点数; 对每个点 x 统计其相邻叶个数 now, 取最大值 max
 * 输出 leaves - max
 * 说明: 该实现未计入 [deg[x]==1] 的自叶项, 因此公式与最优解差一个「r是否为叶」; 在链等情形会少1
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF2() {
    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        ++deg[x], ++deg[y];
    }
    if (n <= 3) {
        cout << "0\n";
        return;
    }
    ll leaves = 0, max = 0;
    for (int i = 1; i <= n; ++i) if (deg[i] == 1) ++leaves;
    for (int x = 1; x <= n; ++x) {
        ll now = 0;
        for (auto &y: g[x]) {
            if (deg[y] == 1) ++now;
        }
        max = std::max(now, max);
    }
    cout << leaves - max << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF2();
    return 0;
}

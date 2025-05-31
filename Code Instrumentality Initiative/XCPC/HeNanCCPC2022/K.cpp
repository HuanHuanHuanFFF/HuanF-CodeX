//
// Created by 幻 on 2025/5/14.
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
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* Problem K. 复合函数
 * link: https://codeforces.com/gym/103941
 * 标签: 功能图 基环树 整除性质 预处理 分桶
 * 思路:
 *   将 f 当作每点出度为 1 的有向图 整图可拆为若干基环树 每个节点记录
 *     - c_x 所在环的长度
 *     - d_x 到环的距离
 *   性质:
 *     若 a = b 则 f^a(x) 恒等于 f^b(x) 对所有 x 成立 答案为 n
 *     若 a ≠ b 设 ℓ = min(a,b) Δ = |a-b|
 *       必须有 ℓ ≥ d_x 使两次迭代都已进入环
 *       且 Δ mod c_x = 0 使二者在环上同位置
 *   统计方法:
 *     预处理完 (c_x,d_x) 后 将节点按环长 c 分桶 并对桶内 d_x 排序
 *     环长不同最多 O(√n) 种 每次询问遍历所有环长 c 判断 Δ mod c = 0 时用 upper_bound 统计深度 ≤ ℓ 的节点数 累加即得答案
 *   时间复杂度: 预处理 O(n log n) 查询 O(√n log n)
 *   空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i) cin >> f[i];
    vector<int> state(n + 1), cycle(n + 1), dep(n + 1);

    auto mark_cyc = [&](vector<int> &path, int cyc_idx) {
        int len = path.size() - cyc_idx;
        for (int i = cyc_idx; i < path.size(); ++i) {
            int x = path[i];
            cycle[x] = len;
            state[x] = 2;
        }
        for (int i = cyc_idx - 1; i >= 0; --i) {
            int x = path[i];
            int y = f[x];
            cycle[x] = cycle[y];
            dep[x] = dep[y] + 1;
            state[x] = 2;
        }
    };

    for (int s = 1; s <= n; ++s) {
        if (state[s]) continue;
        vector<int> path;
        path.reserve(n + 1);
        int x = s;
        while (state[x] == 0) {
            state[x] = 1;
            path.emplace_back(x);
            x = f[x];
        }
        if (state[x] == 1) {
            int id = 0;
            while (path[id] != x) ++id;
            mark_cyc(path, id);
        } else {
            for (int i = path.size() - 1; i >= 0; --i) {
                x = path[i];
                int y = f[x];
                cycle[x] = cycle[y];
                dep[x] = dep[y] + 1;
                state[x] = 2;
            }
        }
    }

    std::unordered_map<int, vector<int> > bkt;
    bkt.reserve(n << 1);
    for (int x = 1; x <= n; ++x) bkt[cycle[x]].push_back(dep[x]);
    vector<int> cycLens;
    cycLens.reserve(bkt.size());
    for (auto &&kv: bkt) {
        auto &&vec = kv.second;
        std::sort(vec.begin(), vec.end());
        cycLens.push_back(kv.first);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            cout << n << "\n";
            continue;
        }
        ll l = std::min(a, b), d = abs(a - b);
        ll ans = 0;
        int max = l >= n ? n : (int) l;
        for (auto c: cycLens) {
            if (d % c == 0) {
                auto &&vec = bkt[c];
                ans += std::ranges::upper_bound(vec, max) - vec.begin();
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/24.
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

template<typename T>
struct BIT {
    int n;
    vector<T> t;

    explicit BIT(int n): n(n), t(vector<T>(n + 1)) {
    }

    int lowbit(int x) { return x & -x; }

    //单点修改
    void add(int x, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            t[i] += val;
        }
    }

    //查询前缀和
    ll pre_sum(int x) {
        ll ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += t[i];
        }
        return ans;
    }

    //查询闭区间和
    ll query(int l, int r) {
        return pre_sum(r) - pre_sum(l - 1);
    }
};

// Panasonic Programming Contest 2025（AtCoder Beginner Contest 406）
/* F - Compare Tree Weights
 * link: https://atcoder.jp/contests/abc406/tasks/abc406_f
 * 思路:
 *   1. 树上子树区间扁平化：DFS 记录 tin/tout，将子树映射到 [tin, tout] 的连续区间
 *   2. 树状数组维护点权，初始全 1；更新时在 tin[x] 加 w；子树权重即区间和
 *   3. 删除边时取更深端点作为子树根，计算子树权 sum，再用总权 all - sum 得另一部分；答案为两者差的绝对值
 *   时间复杂度: O((N+Q) log N)
 *   空间复杂度: O(N)
 */
void HuanF() {
    int n;
    cin >> n;
    vector g(n + 1, vector<int>());
    vector<PII> edge(n - 1);
    vector<int> tin(n + 1), tout(n + 1), dep(n + 1);
    for (auto &[x,y]: edge) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BIT<ll> sum(n);
    int time = 0;
    // DFS 扁平化：记录 tin/tout 和深度
    auto build = [&](auto &&self, int x, int p, int d)-> void {
        tin[x] = ++time;
        dep[x] = d;
        for (auto &y: g[x]) {
            if (y == p) continue;
            self(self, y, x, d + 1);
        }
        tout[x] = time;
    };
    build(build, 1, 0, 1);
    // 初始化所有节点权重为 1
    for (int i = 1; i <= n; ++i) sum.add(i, 1);
    int q;
    ll all = n;
    cin >> q;
    for (ll i = 0, opt, a, w; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            cin >> a >> w;
            // 点权更新：在 tin[x] 加 w
            sum.add(tin[a], w);
            all += w;
        } else {
            cin >> a;
            --a; // 边编号从 0 开始
            auto [x,y] = edge[a];
            // 让 x 为更深端点
            if (dep[x] < dep[y]) x = y;
            cout << std::abs(all - 2 * sum.query(tin[x], tout[x])) << "\n";
        }
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

//
// Created by 幻 on 2025/6/8.
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

constexpr bool more = true;

// Codeforces Round 1029 (Div. 3)
/* 2117F - Wildflower
 * link: https://codeforces.com/contest/2117/problem/F
 * 标签: 树、DFS、数学计数
 * 思路:
 * 1. 先用 DFS 统计叶子数量和各叶子深度，以及记录有两个子节点的分支节点。
 * 2. 如果叶子超过2个，根据鸽巢原理必有两叶同分值，无解，输出0。
 * 3. 只有1个叶子（链状树）时，每个节点都能自由取1或2，共有2^n种方案，n为深度上限。
 * 4. 有2个叶子时，记深度较小叶子为x，较大为y，分支点为branch：
 *    - 叶子节点填1,2,链上的只能都填2
 *    - dx=dy时,总数为2^(dep[branch]+1)
 *    - dx!=dy时,除了保证长度相同的链上的2,还要在主链上使用一个节点规避相同
 *      算上交换一共3种
 */
void HuanF() {
    int n;
    cin >> n;
    vector g(n + 1, vector<int>());
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    int leaf = 0, branch = 0;
    vector<int> dep(n + 1), leaf_d;
    dep[1] = 1;
    auto dfs = [&](auto &&self, int x, int p)-> void {
        int child = 0;
        for (auto &y: g[x]) {
            if (y == p) continue;
            dep[y] = dep[x] + 1;
            ++child;
            self(self, y, x);
        }
        if (!child) {
            ++leaf;
            leaf_d.emplace_back(dep[x]);
        }
        if (child == 2) branch = x;
    };
    dfs(dfs, 1, 0);
    if (leaf > 2) {
        cout << "0\n";
        return;
    }

    auto bpow = [](ll x, ll y) {
        ll res = 1, base = x;
        while (y) {
            if (y & 1) res = res * base % MOD;
            base = base * base % MOD;
            y >>= 1;
        }
        return res;
    };

    ll maxd = std::ranges::max(dep);
    if (leaf == 1) {
        cout << bpow(2, maxd) << "\n";
    } else {
        int depx = std::ranges::min(leaf_d);
        if (depx != maxd)
            cout << bpow(2, maxd - (depx - dep[branch]) - 1) * 3 % MOD << "\n";
        if (depx == maxd)
            cout << bpow(2, dep[branch] + 1) << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

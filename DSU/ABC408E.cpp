//
// Created by 幻 on 2025/5/31.
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

struct DSU {
    std::vector<int> parent, rank, sz;

    DSU(int n)
        : parent(n + 1), rank(n + 1, 0), sz(n + 1, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) std::swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

/* E - Minimum OR Path
 * link: https://atcoder.jp/contests/abc408/tasks/abc408_e
 * 标签: 图论, 联通块, 贪心, 位运算
 * 思路:
 *   1 ans 初始为 30 位全 1 掩码 (1<<30)-1
 *   2 从高位 29 到 0 依次尝试清零:
 *     - 将第 i 位置 0
 *     - 重置并查集父数组
 *     - 遍历所有边 (x,y,w) 若 (ans|w)==ans 则 merge(x,y)
 *     - 若 1 与 n 不连通 则恢复该位
 *   3 最终 ans 即所求最小 OR 值
 * 时间复杂度 O(30*(N+M)α(N))
 * 空间复杂度 O(N+M)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1);
    vector<std::array<int, 3> > edges(m);
    for (auto &[x,y,w]: edges) cin >> x >> y >> w;
    int ans = (1 << 30) - 1;
    DSU dsu(n);
    for (int i = 29; i >= 0; --i) {
        ans ^= 1 << i;
        std::iota(dsu.parent.begin(), dsu.parent.end(), 0);
        for (auto &[x,y,w]: edges) {
            if ((ans | w) == ans) dsu.merge(x, y);
        }
        if (!dsu.connected(1, n))
            ans ^= 1 << i;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

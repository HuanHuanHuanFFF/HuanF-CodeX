//
// Created by 幻 on 2025/5/27.
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

// Codeforces Round 998 (Div. 3) 
/* E.Graph Composition
 * link: https://codeforces.com/contest/2060/problem/E
 * 标签: 并查集、图
 * 思路:
 * 1 先对图 G 构建并查集 gUF 标记各点的连通分量
 * 2 遍历 F 的所有边(u,v) 若 gUF.find(u)!=gUF.find(v) 此边必删 操作次数++
 *    否则保留此边并在 fUF 并查集合并(u,v)
 * 3 遍历 G 的所有边(u,v) 若 fUF.find(u)!=fUF.find(v) 此边必加 操作次数++ 并在 fUF 合并(u,v)
 * 时间复杂度: O((n + m1 + m2) α(n))
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, a, b;
    cin >> n >> a >> b;
    DSU f(n), g(n);
    vector<PII> fg(a), gg(b);
    for (auto &[x,y]: fg) {
        cin >> x >> y;
    }
    for (auto &[x,y]: gg) {
        cin >> x >> y;
        g.merge(x, y);
    }
    ll ans = 0;
    for (auto &[x,y]: fg) {
        if (g.connected(x, y)) {
            f.merge(x, y);
        } else ++ans;
    }
    for (auto &[x,y]: gg) {
        if (!f.connected(x, y)) {
            ++ans;
            f.merge(x, y);
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

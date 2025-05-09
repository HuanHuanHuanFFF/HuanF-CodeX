#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;
using namespace std;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;
constexpr int K = 18;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

struct BL_LCA {
    int n;
    vector<int> dep;
    vector<array<int, K + 1> > up; // up[x][k] = x 的 2^k 祖先
    const vector<vector<PII> > &g;

    BL_LCA(int _n, const vector<vector<PII> > &_g): n(_n), dep(n + 1), up(n + 1), g(_g) {
    }

    void build(int root) { dfs(root, 0); }

    void dfs(int u, int p) {
        up[u][0] = p;
        for (int k = 1; k <= K; k++) up[u][k] = up[up[u][k - 1]][k - 1];
        for (auto [v,_]: g[u])
            if (v != p) {
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
    }

    int lift(int u, int h) {
        for (int k = K; k >= 0; k--) if (h >> k & 1) u = up[u][k];
        return u;
    }

    int lca(int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);
        a = lift(a, dep[a] - dep[b]);
        if (a == b) return a;
        for (int k = K; k >= 0; k--)
            if (up[a][k] != up[b][k])
                a = up[a][k], b = up[b][k];
        return up[a][0];
    }
};

/* P3304-SDOI2013 直径
 * link: https://www.luogu.com.cn/problem/P3304
 * 思路:
 *   1 双遍 DFS 求一条直径端点 a,b 及直径长度 L
 *   2 回溯 parent 链得到主链 path 并编号 idx[path[i]]=i
 *   3 收集所有满足 disA[x]==L 的端点集合 E1，disB[x]==L 的 E2
 *   4 分别以 a、b 为根预处理 LCA，求 E1 的公共前缀节点 p1，E2 的 p2
 *   5 在 path 上 p1,p2 的下标差即为所有直径共用的边数
 * 时间复杂度 O(n log n)  空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<PII> > g(n + 1);
    for (int i = 0, x, y, w; i < n - 1; ++i) {
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    int node = 0;
    ll maxD = 0;
    vector<ll> disA(n + 1, -1), disB(n + 1, -1);
    vector<int> p(n + 1, -1);
    auto dfs = [&](auto &&self, int x, vector<ll> &dis, vector<int> &p)-> int {
        int ans = x;
        for (auto [y,d]: g[x]) {
            if (dis[y] == -1) {
                dis[y] = dis[x] + d;
                p[y] = x;
                int o = self(self, y, dis, p);
                if (dis[o] > dis[ans])
                    ans = o;
            }
        }
        return ans;
    };

    disA[1] = 0;
    int a = dfs(dfs, 1, disA, p);
    std::fill(p.begin(), p.end(), -1);
    std::fill(disA.begin(), disA.end(), -1);
    disA[a] = 0;
    int b = dfs(dfs, a, disA, p);
    ll L = disA[b];

    vector<int> path, idx(n + 1, -1);
    for (int x = b; x != -1; x = p[x]) path.push_back(x);
    std::reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i) idx[path[i]] = i;

    vector<int> E1, E2;
    for (int i = 1; i <= n; ++i)
        if (disA[i] == L) E1.push_back(i);
    std::fill(p.begin(), p.end(), -1);
    disB[b] = 0;
    dfs(dfs, b, disB, p);
    for (int i = 1; i <= n; ++i)
        if (disB[i] == L) E2.push_back(i);

    BL_LCA lcaA(n, g), lcaB(n, g);
    lcaA.build(a);
    int p1 = E1[0], p2 = E2[0];
    for (auto x: E1)
        p1 = lcaA.lca(p1, x);
    lcaB.build(b);
    for (auto x: E2)
        p2 = lcaB.lca(p2, x);

    int l = idx[p1], r = idx[p2];
    if (l > r) swap(l, r);
    int ans = max(0, r - l);
    cout << L << "\n" << ans;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

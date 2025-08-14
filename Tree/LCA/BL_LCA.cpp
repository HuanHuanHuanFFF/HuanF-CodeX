#include <bits/stdc++.h>

using namespace std;

struct BL_LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int> > up; // up[k][u] = u 的 2^k 级祖先
    const vector<vector<int> > &g;

    BL_LCA(int n, const vector<vector<int> > &g): n(n), g(g) {
        LOG = __lg(n) + 1;
        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1, 0));
    }

    // 从 root 开始，调用一次即可完成所有预处理
    void build(int root) {
        dfs(root, 0);
    }

    void dfs(int u, int p) {
        up[0][u] = p;
        for (int k = 1; k < LOG; ++k) {
            up[k][u] = up[k - 1][up[k - 1][u]];
        }
        for (int v: g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    // 返回 u 和 v 的最近公共祖先
    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        // 把 u 向上提到和 v 同层
        for (int k = 0; k < LOG; ++k) {
            if (diff >> k & 1) {
                u = up[k][u];
            }
        }
        if (u == v) return u;
        // 同时往上跳，直到它们的直接父亲相同
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        // 此时 u、v 是不同的兄弟节点，返回它们的父亲
        return up[0][u];
    }
};

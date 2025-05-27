#include <bits/stdc++.h>
using namespace std;

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

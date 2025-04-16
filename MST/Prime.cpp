#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
constexpr ll INF = 1e17 + 17;

/**
 * @param g 无向图
 * @param n 节点个数
 * @param root 最先入队的根节点
 * @return 最小生成树的代价,如果不满足题目条件则返回LONG_MAX
*/
ll Prim(vector<vector<PII> > &g, int n, int root) {
    ll ans = 0, cnt = 0;
    vector<bool> vis(n + 1);
    priority_queue<PII, vector<PII>, greater<> > heap;
    heap.emplace(0, root);
    while (!heap.empty()) {
        if (cnt >= n) return ans;
        auto [d,x] = heap.top();
        heap.pop();
        if (vis[x]) continue;
        vis[x] = true;
        ++cnt;
        ans += d;
        for (auto &[cost,y]: g[x]) {
            heap.emplace(cost, y);
        }
    }
    return LONG_MAX;
}

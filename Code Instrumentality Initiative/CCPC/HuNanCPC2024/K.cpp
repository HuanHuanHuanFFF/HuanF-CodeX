#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* K. 渡劫
 * link: https://codeforces.com/gym/105423
 * 思路:
 * 1 构建分层图,节点数量 = 2*n+1, 0 号为超级源, 1~n 是层0, n+1~2n 是层1
 * 2 对每条隧道 u-v, 在层0 和 层1 分别添加双向权重 w 的边
 * 3 跨层免费通道: 在层0 的 u->层1 的 v 和 v->层1 的 u 添加权0 边, 表示用宝免费穿越该隧道
 * 4 自跨层跳转: 在每个 i 的层0->层1 添加权0 边, 允许不走隧道即可使用法宝
 * 5 超级源 node0->i(层0) 添加权 a_i 的边, 表示直接在岛 i 完成渡劫的能量消耗
 * 6 运行 Dijkstra 从超级源出发, 得到所有状态最短路 dis[], 最终答案 = max_{i=1..n}(dis[i(层1)])
 * 时间复杂度: O((n+m)log(n+m))
 * 空间复杂度: O(n+m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    int size = n << 1;
    vector<ll> dis(size + 1, INF);
    vector g(size + 1, vector<PII>());
    for (ll i = 0, x, y, w; i < m; ++i) {
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
        g[x + n].emplace_back(y + n, w);
        g[y + n].emplace_back(x + n, w);
        g[x].emplace_back(y + n, 0);
        g[y].emplace_back(x + n, 0);

        // 假设某岛 i 的最优策略是：起点即终点，不走任何隧道，只用 a_i 完成渡劫
        // 此时不会消耗任何隧道能量，也不会经过任何跨层隧道边 (u^(0) → v^(1))
        // 因此需要允许从 i^(0) 到 i^(1) 的零权自跨层跳转
        g[x].emplace_back(x + n, 0);
        g[y].emplace_back(y + n, 0);
    }
    for (ll i = 1, a; i <= n; ++i) {
        cin >> a;
        g[0].emplace_back(i, a);
    }
    std::priority_queue<PII, vector<PII>, std::greater<> > heap;
    dis[0] = 0;
    heap.emplace(0, 0);
    while (heap.size()) {
        auto [d,x] = heap.top();
        heap.pop();
        if (d != dis[x]) continue;
        for (auto &[y,w]: g[x]) {
            if (d + w < dis[y]) {
                dis[y] = d + w;
                heap.emplace(dis[y], y);
            }
        }
    }
    ll ans = 0;
    for (int i = n + 1; i <= size; ++i) {
        ans = std::max(ans, dis[i]);
        // cout << dis[i] << "\n";
    }
    cout << ans << "\n";
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

/*
4 5
 3 2 7
 4 1 6
 3 4 2
 2 1 2
 3 1 8
 27 27 9 8
*/

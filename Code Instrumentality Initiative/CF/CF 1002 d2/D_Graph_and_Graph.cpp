//
// Created by 幻 on 2025/6/13.
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
constexpr ll INF = 1e17 + 17;
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

// Codeforces Round 1002 (Div. 2) 
/* 2059D - Graph and Graph
 * link: https://codeforces.com/contest/2059/problem/D
 * 标签: 状态图、Dijkstra、最短路、笛卡尔积
 * 思路:
 *   - 定义状态 (x1,x2) 表示两枚标记分别在图1顶点 x1 与图2顶点 x2。
 *   - 一步操作 = 同时沿各自邻边移动到 (y1,y2)，费用 |y1-y2|。
 *     ⇒ 状态图边: (x1,x2)→(y1,y2)，权 |y1-y2|，共 ≤ m1·m2 条。
 *   - 若存在公共边 (v,u) 于两图，则顶点 v 为 “good”；
 *     到达状态 (v,v) 后可在该公共边来回，后续代价 0。
 *   - 任务转化为: 起点 (s1,s2) 到任何 (v,v) 且 v 为 good 的最短路。
 *     用懒式 Dijkstra（priority_queue 丢弃过期条目）求 dist。
 *   - 若所有 good 状态不可达则答案 −1；否则输出最小 dist(v,v)。
 * 时间复杂度: O((n² + m1·m2) log n²)
 *            (n≤1000，m1,m2≤1000，数据范围内可通过)
 * 空间复杂度: O(n²) — 保存 dist 数组
 */
void HuanF() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    int m1, m2;
    cin >> m1;
    std::set<PII> edges;
    vector<vector<int> > g1(n + 1), g2(n + 1);
    vector<bool> best(n + 1);
    for (int i = 0, x, y; i < m1; ++i) {
        cin >> x >> y;
        if (x > y) std::swap(x, y);
        edges.emplace(x, y);
        g1[x].emplace_back(y);
        g1[y].emplace_back(x);
    }
    cin >> m2;
    for (int i = 0, x, y; i < m2; ++i) {
        cin >> x >> y;
        if (x > y) std::swap(x, y);
        if (edges.contains({x, y}))
            best[x] = true, best[y] = true;
        g2[x].emplace_back(y);
        g2[y].emplace_back(x);
    }
    vector dis(n + 1, vector<ll>(n + 1, INF));
    std::priority_queue<std::tuple<ll, int, int>, vector<std::tuple<ll, int, int> >, std::greater<> > heap;
    heap.emplace(0, s1, s2);
    dis[s1][s2] = 0;
    while (heap.size()) {
        auto [d,x1,x2] = heap.top();
        heap.pop();
        if (dis[x1][x2] < d) continue;
        for (auto &y1: g1[x1])
            for (auto &y2: g2[x2]) {
                int w = abs(y2 - y1);
                if (dis[y1][y2] > d + w) {
                    dis[y1][y2] = d + w;
                    heap.emplace(d + w, y1, y2);
                }
            }
    }
    ll ans = INF;
    for (int i = 1; i <= n; ++i) {
        if (best[i]) {
            ans = std::min(ans, dis[i][i]);
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

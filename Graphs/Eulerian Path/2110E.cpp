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

// Codeforces Round 1026 (Div. 2)
/* E. 旋律
 * link: https://codeforces.com/contest/2110/problem/E
 * 标签: 二分图, 欧拉路径, Hierholzer 算法, 哈希映射
 * 思路:
 *  1. 离散化：用 map 将所有音量和音高映射为图中唯一顶点 id, node 记录每个 id 对应的 (vol,0) 或 (0,pit)
 *  2. 建图：g 为无向邻接表, 每个声音 (vol,pit) 在其对应的音量顶点和音高顶点间插入一条边
 *  3. 奇度检查：统计所有顶点的度数, 奇度顶点数必须为 0 或 2, 否则输出 No；若为 2, 选任一奇点为 start, 否则选任一非空顶点
 *  4. Hierholzer 算法删边 DFS：从 start 出发, 每次取 g[x].begin() 得到最小邻居 y, 在 g[x] 和 g[y] 中删除该边, 递归 dfs(y), 回溯时将 x push 到 ans
 *  5. 验证路径：若 ans.size() != n+1, 表示无法遍历所有边, 输出 No; 否则 reverse(ans) 得到正序顶点路径
 *  6. 映射回声音：遍历相邻顶点对 (ans[i],ans[i+1]), 将 node[id] 相加恢复原 (vol,pit), 再从 idx 中查出对应声音编号装入 out
 * 时间复杂度: O(n log n)  // 主要在 map 操作和 set 操作
 * 空间复杂度: O(n)
 */
void HuanF() {
    // p：音高值 -> 顶点编号；v：音量值 -> 顶点编号
    std::map<int, int> p, v;
    // node[k] = (vol, pit)，vol>0 表示这是一个音量顶点，pit>0 表示音高顶点
    vector<PII> node;
    // idx[(vol,pit)] = 原始声音编号 i
    std::map<PII, int> idx;
    // g：无向图的邻接表，g[k] 存放顶点 k 的所有邻居顶点编号
    vector<std::set<int> > g;

    int n;
    cin >> n;

    // 1. 读取所有声音并构造二分图
    for (int i = 1, vol, pit; i <= n; ++i) {
        cin >> vol >> pit;
        // 记录声音 (vol,pit) 对应的下标
        idx[{vol, pit}] = i;

        // 如果该音量第一次出现，则分配一个新的顶点
        if (!v.count(vol)) {
            int id = g.size();
            v[vol] = id;
            g.emplace_back(); // 新增邻接集合
            node.emplace_back(vol, 0); // 标记为音量顶点
        }
        // 如果该音高第一次出现，则分配一个新的顶点
        if (!p.count(pit)) {
            int id = g.size();
            p[pit] = id;
            g.emplace_back(); // 新增邻接集合
            node.emplace_back(0, pit); // 标记为音高顶点
        }

        // 在对应的音量顶点 x 和音高顶点 y 之间加无向边
        int x = v[vol], y = p[pit];
        g[x].insert(y);
        g[y].insert(x);
    }

    // 2. 统计奇数度顶点，选定欧拉路径起点
    int odd = 0, start = 1;
    for (int i = 0; i < (int) g.size(); ++i) {
        if (g[i].size() & 1) {
            ++odd;
            start = i; // 记录最后一个奇度顶点作为起点
        }
    }
    // 必须恰有 0 或 2 个奇度顶点，否则不可有欧拉路径
    if (odd != 0 && odd != 2) {
        cout << "No\n";
        return;
    }

    // 3. Hierholzer 算法 — 删边 DFS，回溯记录顶点顺序
    vector<int> ans;
    ans.reserve(n + 1);
    auto dfs = [&](auto &&self, int u) -> void {
        // 只要 u 还有邻边，就“删边 + 深入”
        while (!g[u].empty()) {
            int v = *g[u].begin(); // 取最小邻居，保证字典序最小
            // 在两端都删除这条无向边
            g[u].erase(v);
            g[v].erase(u);
            self(self, v);
        }
        // 回溯时记录顶点
        ans.emplace_back(u);
    };
    dfs(dfs, start);

    // 4. 校验是否正好遍历了所有 n 条边 → 顶点数应为 n+1
    if ((int) ans.size() != n + 1) {
        cout << "No\n";
        return;
    }
    // 逆序得到从起点到终点的顶点路径
    std::reverse(ans.begin(), ans.end());

    // 5. 将顶点路径映射回原始声音编号
    vector<int> out;
    out.reserve(n);
    for (int i = 0; i < n; ++i) {
        // ans[i], ans[i+1] 对应一个边，分别存 (vol,0) 或 (0,pit)
        auto p1 = node[ans[i]];
        auto p2 = node[ans[i + 1]];
        // 恢复出这条边的 (vol,pit)
        PII edgeKey = {p1.first + p2.first, p1.second + p2.second};
        int id = idx[edgeKey];
        // 若 idx 中无此键，则映射失败
        if (!id) {
            cout << "No\n";
            return;
        }
        out.emplace_back(id);
    }

    // 6. 输出结果
    cout << "Yes\n";
    for (auto x: out) {
        cout << x << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

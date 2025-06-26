//
// Created by 幻 on 2025/6/26.
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

// Codeforces Round 903 (Div. 3) 
/* 1881F
 * link: https://codeforces.com/problemset/problem/1881/F
 * 标签: 树, 直径, 多次 DFS, 标记点
 * 思路:
 * 1 任选一个标记节点 u，DFS 得到所有节点到 u 的距离 d1，找距离最远的标记点 p；
 * 2 以 p 为起点，DFS 得到距离 d2，找距离最远的标记点 q；
 * 3 以 q 为起点，DFS 得到距离 d3；
 * 4 对每个节点 i 计算 f[i]=max(d2[i],d3[i])，答案为 min_i f[i]；
 * 这样利用标记点子树的“直径”端点距离，实现多源最远距离的最小化
 * 时间复杂度 O(n)，空间复杂度 O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    std::set<int> mark;
    for (int i = 0, x; i < k; ++i) {
        cin >> x;
        mark.insert(x);
    }
    vector<vector<int> > g(n + 1);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    if (k == 1) {
        cout << "0\n";
        return;
    }
    auto dfs = [&](auto &&self, int x, int p, vector<int> &d)-> void {
        for (auto &y: g[x]) {
            if (y == p) continue;
            d[y] = d[x] + 1;
            self(self, y, x, d);
        }
    };
    vector<int> d1(n + 1);
    int p = 0, max = 0;
    p = *mark.begin();
    dfs(dfs, p, 0, d1);

    for (int i = 1; i <= n; ++i) {
        if (mark.contains(i) && d1[i] > max)
            p = i, max = d1[i];
    }
    vector<int> d2(n + 1);
    dfs(dfs, p, 0, d2);
    max = 0;
    for (int i = 1; i <= n; ++i) {
        if (mark.contains(i) && d2[i] > max)
            p = i, max = d2[i];
    }
    vector<int> d3(n + 1);
    dfs(dfs, p, 0, d3);
    vector<int> d(n + 1);
    int min = INF;
    for (int i = 1; i <= n; ++i) {
        d[i] = std::max(d3[i], d2[i]);
        min = std::min(min, d[i]);
    }
    cout << min << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

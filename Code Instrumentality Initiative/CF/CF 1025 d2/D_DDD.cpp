//
// Created by 幻 on 2025/5/23.
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
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e12 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Codeforces Round 1025 (Div. 2) 
/* D. D/D/D
 * link: https://codeforces.com/contest/1025/problem/D
 * 标签：图论、BFS、状态分层、子集和、奇偶性
 * 思路：
 *   1. 读取多重集 A，计算总步数和 S = ∑A 及最小奇数 minOdd（用于翻转奇偶）
 *   2. 构建无向图后，从顶点 1 做一次 BFS，将每个顶点 i 的最短偶数步距离 dist[i][0]
 *      和最短奇数步距离 dist[i][1] 记录下来
 *   3. 对每个顶点 i：
 *        • 若 dist[i][S%2] ≤ S，则存在总步数为 S（同奇偶）的 walk 到达 i
 *        • 否则若存在奇数元素且 dist[i][1−(S%2)] ≤ S−minOdd，则可用总步数 S−minOdd（翻转奇偶）到达
 *      若任一条件成立，则 i 可达
 * 时间复杂度：O(n + m + ℓ)  
 * 空间复杂度：O(n + m + ℓ)
 */
void HuanF() {
    ll n, m, l, sum = 0, odd = INF;
    cin >> n >> m >> l;
    vector<ll> a(l);
    for (auto &x: a) {
        cin >> x;
        sum += x;
        if (x & 1) odd = std::min(odd, x);
    }
    vector g(n + 1, vector<int>());
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector dis(n + 1, std::array<ll, 2>({INF, INF}));
    dis[1][0] = 0;
    std::queue<PII> q;
    q.emplace(1, 0);
    while (q.size()) {
        auto [x,d] = q.front();
        q.pop();
        for (auto &y: g[x]) {
            if (dis[y][(d + 1) % 2] == INF) {
                q.emplace(y, d + 1);
                dis[y][(d + 1) % 2] = d + 1;
            }
        }
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (dis[i][sum % 2] <= sum) ans[i] = 1;
        else if (odd < INF && dis[i][1 - sum % 2] <= sum - odd) ans[i] = 1;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i];
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

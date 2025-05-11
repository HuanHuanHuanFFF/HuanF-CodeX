#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* B-建建筑
 * link: https://codeforces.com/gym/104417
 * 思路
 * 1 批量收集各工种的需求条件 condition[t] = [(b,i)...] 和奖励 prise[i] 依赖模块化
 * 2 对每个工种的需求列表按 b 升序排序 以指针扫描代替堆 动态维护“剩余入度” in[i]
 * 3 初始阶段 扫一遍所有工种 若 cnt[t] 已满足最小需求 则减少对应工程入度
 * 4 用队列维护所有 in[i]==0 的可接工程, 每取出一个:
 *   4.1 累加奖励: 对每个 (t,c) 更新 cnt[t]
 *   4.2 对该工种的需求列表继续扫描 满足则 --in[j] 并入队
 * 5 答案即出队次数
 * 时间复杂度 O(M·log M + M·log T + n)，其中 M=∑m_i+∑k_i，T=不同工种数
 * 空间复杂度 O(M + g + n)
 */
void HuanF() {
    int g, n;
    cin >> g;
    std::map<ll, ll> cnt;
    for (int i = 0, x, y; i < g; ++i) {
        cin >> x >> y;
        cnt[x] = y;
    }
    cin >> n;
    std::map<int, vector<PII> > condition; // condition[t] 存该工种的所有(需求,工程id)
    vector<int> in(n); // in[i] = 工程 i 未满足的条件数
    vector<vector<PII> > prise(n); // prise[i] = 承接工程 i 后获得的(工种,人数)
    for (int i = 0, m, k; i < n; ++i) {
        cin >> m;
        for (int j = 0, a, b; j < m; ++j) {
            cin >> a >> b;
            condition[a].emplace_back(b, i);
            ++in[i];
        }
        cin >> k;
        prise[i].reserve(k);
        for (int j = 0, c, d; j < k; ++j) {
            cin >> c >> d;
            prise[i].emplace_back(c, d);
        }
    }
    // 预处理: 对每个工种的需求按 b 升序, 一次性满足时减少入度
    for (auto &[ind,v]: condition) {
        std::sort(v.begin(), v.end(), std::greater<>());
        while (!v.empty() && v.back().first <= cnt[ind]) {
            --in[v.back().second];
            v.pop_back();
        }
    }
    std::queue<ll> q;
    // 所有 in==0 的工程入队
    for (int i = 0; i < n; ++i) {
        if (!in[i]) q.push(i);
    }
    ll ans = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        ++ans;
        // 更新奖励
        for (auto &[ind,c]: prise[x]) {
            cnt[ind] += c;
            auto &con = condition[ind];
            while (!con.empty() && cnt[ind] >= con.back().first) {
                if (--in[con.back().second] == 0) {
                    q.push(con.back().second);
                }
                con.pop_back();
            }
        }
    }
    cout << ans;
}

signed main() {
    init();
    HuanF();
    return 0;
}

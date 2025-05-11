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

/* C-换座位
 * link: https://acm.sjtu.edu.cn/contest/2024-ICPC-ShaanXi-Provincial/Seat
 * 思路:
 * 1 建图 把每位嘉宾i连一条i->to[i]的有向边
 * 2 indeg数组记录每个节点的入度
 * 3 对入度为0的嘉宾做拓扑BFS 维护dist[x]表示从树根到x的链长
 *   如果下一节点y>n（空座位） 更新seatLen[y]=max(seatLen[y],dist[x])
 *   否则 更新dist[y]=max(dist[y],dist[x]+1) 并在in[y]变0时入队
 * 4 BFS结束后 indeg>0的节点都是环上的嘉宾 全部可满足
 * 5 答案 = 环上嘉宾个数 + 所有空座位的seatLen之和
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> to(n + 1), dp(n << 1 | 1), in(n << 1 | 1);
    // 读取目标座位并统计入度
    for (int i = 1; i <= n; ++i) {
        cin >> to[i];
        ++in[to[i]];
    }
    std::queue<int> qu;
    for (int i = 1; i <= n; ++i) {
        // 初始化 所有入度为0的嘉宾入队 链长设为1
        if (!in[i]) {
            qu.push(i);
            dp[i] = 1;
        }
    }
    //拓扑排序
    while (!qu.empty()) {
        auto x = qu.front();
        qu.pop();
        int y = to[x];
        // 指向空座位 更新该空座位的最大可满足链长
        if (y > n) dp[y] = std::max(dp[y], dp[x]);
        else {
            // 指向另一位嘉宾 更新链长 并在入度清零时入队
            dp[y] = std::max(dp[y], dp[x] + 1);
            if (--in[y] == 0) qu.push(y);
        }
    }
    ll ans = 0;
    //环上所有嘉宾都可满足
    for (int i = 1; i <= n; ++i) {
        if (in[i] > 0) ++ans;
    }
    //加上每张空座位的最大链长
    for (int i = n + 1; i <= n << 1; ++i) {
        ans += dp[i];
    }
    cout << ans;
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

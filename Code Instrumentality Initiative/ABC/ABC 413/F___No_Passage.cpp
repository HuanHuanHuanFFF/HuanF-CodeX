//
// Created by 幻 on 2025/8/6.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = false;

// Denso Create Programming Contest 2025（AtCoder Beginner Contest 413）
/* ABC413-F No Passage
 * link: https://atcoder.jp/contests/abc413/tasks/abc413_f
 * 标签: 多源 BFS、最小第二值、图论
 * 思路:
 *   Takahashi 只有当某格至少存在两条通往终点的备选路径时才能躲开 Aoki 的封锁。
 *   因此把所有目标格设距 0，做多源 BFS：
 *     • dis[x][y] 记录该格到最近目标的“最坏情况下”最小步数
 *     • vis[x][y] 统计来自已确定格的邻接次数
 *     • 当 vis==2 时，该格首次可达，其距离 = 出队格距离 + 1，并入队继续扩展
 *   每次弹出队首即累加 dis 得到全图答案。
 *   时间复杂度 O(HW)，空间复杂度 O(HW)。
 * 时间复杂度: O(HW)
 * 空间复杂度: O(HW)
 */
void HuanF() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<PII> start(k);
    vector dis(h + 1, vector<int>(w + 1, -1)),
            vis(h + 1, vector<int>(w + 1));
    for (auto &[x,y]: start) {
        cin >> x >> y;
        dis[x][y] = 0;
    }
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    std::queue<PII> q(start.begin(), start.end());
    ll ans = 0;
    while (q.size()) {
        auto [x,y] = q.front();
        q.pop();
        ans += dis[x][y];
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > h || ny < 1 || ny > w) continue;
            if (dis[nx][ny] == -1) {
                ++vis[nx][ny];
                if (vis[nx][ny] == 2) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

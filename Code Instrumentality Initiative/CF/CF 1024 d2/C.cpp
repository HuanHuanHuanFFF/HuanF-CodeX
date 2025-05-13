//
// Created by 幻 on 2025/5/11.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
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

/* C. 网格Mex
 * link: https://codeforces.com/problemset/problem/2102/C
 * 思路:
 * 1. 将所有数字 0…n^2-1 按照“从中心开始、向外依次扩散”的 BFS 顺序放置
 * 2. 每次从队列中取一个格子，按 8 个方向依次尝试添加相邻格子
 *    方向顺序（偏移 dx,dy）：
 *      → (0,+1)、↓(+1,0)、↘(+1,+1)、↑(−1,0)、↗(−1,+1)、←(0,−1)、↙(+1,−1)、↖(−1,−1)
 * 3. 这样就能最大化各个小数字在同一子矩阵内“成组”出现的次数，从而极大提升 MEX 总和
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n^2)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > ans(n, vector<int>(n));
    vector<vector<bool> > vis(n, vector<bool>(n, false));
    std::queue<pair<int, int> > q;
    // 选取中心点 (c,c)，0-based，下列写法在 n 为奇数／偶数时均可
    int c = (n - 1) / 2;
    q.emplace(c, c);
    vis[c][c] = true;
    // BFS 扩散的 8 个方向
    vector<pair<int, int> > dirs = {
        {0, 1}, {1, 0}, {1, 1}, {-1, 0},
        {-1, 1}, {0, -1}, {1, -1}, {-1, -1}
    };
    int cur = 0;
    // 第一格给 0
    ans[c][c] = cur++;
    // 标准 BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy]: dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                vis[nx][ny] = true;
                ans[nx][ny] = cur++;
                q.emplace(nx, ny);
            }
        }
    }
    // 输出
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

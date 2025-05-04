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

void init() {
}

/* M. Window Decoration
 * link: https://codeforces.com/gym/105257/problem/Md
 * 思路:
 * 将 100×100 的窗口划分为 100×100 个单元格，每个单元格分为 4 个面积为 0.25 的小三角
 * 使用 bool g[105][105][5] 标记单元格 (i,j) 的第 k 个三角（k=1..4）是否被覆盖
 * 对每个装饰中心 (x,y) 标记覆盖的三角：
 *   g[x-1][y-1][2] = g[x-1][y-1][3] = true
 *   g[x][y-1][1]   = g[x][y-1][2]   = true
 *   g[x-1][y][3]   = g[x-1][y][4]   = true
 *   g[x][y][1]     = g[x][y][4]     = true
 * 遍历所有 g[i][j][k] 累加被覆盖的三角数量乘以 0.25 即为总覆盖面积
 * 时间复杂度: O(n + 100*100*4)
 * 空间复杂度: O(100*100*4)
 */
void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void HuanF() {
    int n;
    cin >> n;
    bool g[105][105][5]{false};
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        g[x - 1][y - 1][2] = g[x - 1][y - 1][3] = true;
        g[x][y - 1][1] = g[x][y - 1][2] = true;
        g[x - 1][y][3] = g[x - 1][y][4] = true;
        g[x][y][1] = g[x][y][4] = true;
    }
    long double ans = 0;
    for (int x = 0; x < 103; ++x) {
        for (int y = 0; y < 103; ++y) {
            for (int i = 1; i <= 4; ++i) {
                if (g[x][y][i]) ans += 0.25;
            }
        }
    }
    printf("%.5Lf", ans);
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

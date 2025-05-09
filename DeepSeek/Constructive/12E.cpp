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

/* E. Start of the season
 * link: https://codeforces.com/contest/12/problem/E
 * 思路:
 * 1 圆桌赛程生成完美匹配:
 *   - 固定顶点 n-1, 其余 0..n-2 环形排列
 *   - 共 n-1 轮, 每轮 r:
 *     * 固定顶点与 r 配对
 *     * 对剩余 i=1..n/2-1:
 *         u=(r+i)%(n-1), v=(r-i+n-1)%(n-1)
 *         配对 (u,v)
 *   - 每轮的配对即一个完美匹配
 * 2 用轮次 r+1 作为“颜色”填入对称矩阵 a[u][v]=a[v][u]=r+1
 * 3 对角线默认 0 满足题意
 * 时间复杂度 O(n^2)
 * 空间复杂度 O(n^2)
 */
void HuanF() {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));

    for (int r = 0; r < n - 1; ++r) {
        int color = r + 1;
        a[n - 1][r] = a[r][n - 1] = color;
        for (int i = 1; i < n / 2; ++i) {
            int x = (r + i) % (n - 1);
            int y = (r - i + n - 1) % (n - 1);
            a[x][y] = a[y][x] = color;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
using PIII = pair<int, PII>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e8 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* ABC400-D
 * link: https://atcoder.jp/contests/abc400/tasks/abc400_d
 * 思路:
 * 1 构建图: 每个格子为节点
 * 2 四邻域为权值0边(road)
 * 3 跨1-2格遇墙或目标为墙为权值1边(kick)
 * 4 用0-1 BFS维护deque: 0权头插,1权尾插
 * 5 hit数组记录到各节点最小踢数
 */
void HuanF() {
    int h, w;
    cin >> h >> w;
    vector g(h, vector<int>(w)), hit(h, vector<int>(w, INF));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            g[i][j] = s[j] == '.' ? 0 : 1;
        }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;

    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    std::deque<int> dq;
    hit[a][b] = 0;
    dq.push_front(a * w + b);
    while (!dq.empty()) {
        auto z = dq.front();
        dq.pop_front();
        if (z == c * w + d) {
            cout << hit[c][d];
            return;
        }
        auto x = z / w, y = z % w;
        for (int i = 0; i < 4; i++) {
            bool wall = false;
            // 试两步 step=1,2
            for (int j = 1; j <= 2; j++) {
                int nx = x + dx[i] * j;
                int ny = y + dy[i] * j;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)break;
                if (g[nx][ny] == 1)wall = true;
                if (!wall) {
                    if (j == 1) {
                        if (hit[nx][ny] > hit[x][y]) {
                            hit[nx][ny] = hit[x][y];
                            dq.push_front(nx * w + ny);
                        }
                    }
                } else {
                    if (hit[nx][ny] > hit[x][y] + 1) {
                        hit[nx][ny] = hit[x][y] + 1;
                        dq.push_back(nx * w + ny);
                    }
                }
            }
        }
    }
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

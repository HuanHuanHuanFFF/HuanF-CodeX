//
// Created by 幻 on 2025/5/21.
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
constexpr int INF = 7e7 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* P2585-三色二叉树
 * link: https://www.luogu.com.cn/problem/P2585
 * 思路:
 * 1 递归解析前序序列建树，每次读字符生成节点并根据 '1' 或 '2' 构建子节点
 * 2 定义状态 dp_max[u][c], dp_min[u][c]：节点 u 染色 c 时子树内最多/最少绿色数
 * 3 后序遍历递归:  
 *   (1) 若叶节点: dp_max[u][c]=dp_min[u][c]=(c==1)
 *   (2) 若只有一个子节点 v:
 *       dp_max[u][c]=(c==1)+max_{d≠c}dp_max[v][d]
 *       dp_min[u][c]=(c==1)+min_{d≠c}dp_min[v][d]
 *   (3) 若有两个子节点 v1,v2: 枚举 d1,d2≠c 且 d1≠d2 执行:
 *       dp_max[u][c]=(c==1)+max(dp_max[v1][d1]+dp_max[v2][d2])
 *       dp_min[u][c]=(c==1)+min(dp_min[v1][d1]+dp_min[v2][d2])
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    string s;
    cin >> s;
    s = "0" + s;
    int n = s.size();
    vector child(n + 1, vector<int>());
    int end = 1;
    auto build = [&](auto &&self, int i, int fa)-> void {
        child[fa].push_back(i);
        ++end;
        if (s[i] == '1') {
            self(self, i + 1, i);
        } else if (s[i] == '2') {
            self(self, i + 1, i);
            self(self, end, i);
        }
    };
    build(build, 1, 0);
    vector dp_min(n + 1, std::array<int, 3>()),
            dp_max(n + 1, std::array<int, 3>());

    auto dfs = [&](auto &&self, int x) -> void {
        if (child[x].empty()) {
            for (int c = 0; c < 3; ++c) {
                dp_max[x][c] = dp_min[x][c] = c == 1;
            }
            return;
        }

        if (child[x].size() == 1) {
            int y = child[x][0];
            self(self, y);
            for (int c = 0; c < 3; ++c) {
                int max = -INF, min = INF;
                for (int d = 0; d < 3; ++d) {
                    if (c == d) continue;
                    max = std::max(dp_max[y][d], max);
                    min = std::min(dp_min[y][d], min);
                }
                dp_max[x][c] = (c == 1) + max;
                dp_min[x][c] = (c == 1) + min;
            }
            return;
        }

        int y1 = child[x][0], y2 = child[x][1];
        self(self, y1);
        self(self, y2);
        for (int c = 0; c < 3; ++c) {
            int max = -INF, min = INF;
            for (int d1 = 0; d1 < 3; ++d1) {
                if (d1 == c) continue;
                for (int d2 = 0; d2 < 3; ++d2) {
                    if (d2 == c || d2 == d1) continue;
                    max = std::max(dp_max[y1][d1] + dp_max[y2][d2], max);
                    min = std::min(dp_min[y1][d1] + dp_min[y2][d2], min);
                }
            }
            dp_max[x][c] = (c == 1) + max;
            dp_min[x][c] = (c == 1) + min;
        }
    };

    dfs(dfs, 1);
    int max = 0, min = INF;
    for (int c = 0; c < 3; ++c) {
        max = std::max(max, dp_max[1][c]);
        min = std::min(min, dp_min[1][c]);
    }
    cout << max << " " << min;
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

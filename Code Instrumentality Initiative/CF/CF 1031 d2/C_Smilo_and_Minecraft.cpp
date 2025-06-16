//
// Created by 幻 on 2025/6/15.
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

// Codeforces Round 1031 (Div. 2) 
/* 2113C - Smilo and Minecraft
 * link: https://codeforces.com/contest/2113/problem/C
 * 标签: 二维前缀和, 枚举, 损失最小化
 * 思路: 只和第一次爆炸损失有关,最小化第一次爆炸内部金矿损失
 * 1. 统计总金矿 sum
 * 2. 构造二维前缀和 pre[i][j]
 * 3. 枚举每个空格 (i,j) 作为首爆位置，计算内部丢失 loss
 * 4. 答案 = 最大(sum - loss)
 * 时间复杂度 O(n*m)，空间复杂度 O(n*m)
 */
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n + 1, vector<char>(m + 1));
    vector pre(n + 1, vector<int>(m + 1));
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (g[i][j] == 'g');
            sum += g[i][j] == 'g';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == '.') {
                int x1 = std::max(i - k + 1, 1), y1 = std::max(j - k + 1, 1);
                int x2 = std::min(i + k - 1, n), y2 = std::min(j + k - 1, m);
                int now = sum - (pre[x2][y2] + pre[x1 - 1][y1 - 1] - pre[x1 - 1][y2] - pre[x2][y1 - 1]);
                ans = std::max(ans, now);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

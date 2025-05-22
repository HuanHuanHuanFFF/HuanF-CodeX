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

using namespace std;

/* 275B-凸形形状
 * link: https://codeforces.com/problemset/problem/275B
 * 思路:
 *   1 收集所有黑格坐标放入列表
 *   2 构建行前缀和 rowSum 和列前缀和 colSum 用于 O(1) 区间全黑判断
 *   3 枚举任意两黑格 (r1,c1) (r2,c2)
 *     a 先水平再垂直路径 L1
 *     b 先垂直再水平路径 L2
 *     若 L1 或 L2 有效 则两点连通 否则输出 NO
 * 时间复杂度 O((nm)^2) 空间复杂度 O(nm)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    // 收集黑格，同时建行/列前缀和
    vector<pair<int, int> > blacks;
    vector rowSum(n, vector<int>(m + 1, 0));
    vector colSum(m, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int b = (s[i][j] == 'B');
            rowSum[i][j + 1] = rowSum[i][j] + b;
            colSum[j][i + 1] = colSum[j][i] + b;
            if (b) blacks.emplace_back(i, j);
        }
    }

    // 判断行 i 从列 l 到 r 是否全黑
    auto rowFull = [&](int i, int l, int r) {
        return rowSum[i][r + 1] - rowSum[i][l] == r - l + 1;
    };
    // 判断列 j 从行 u 到 d 是否全黑
    auto colFull = [&](int j, int u, int d) {
        return colSum[j][d + 1] - colSum[j][u] == d - u + 1;
    };

    int K = blacks.size();
    // 枚举每对黑格
    for (int a = 0; a < K; a++) {
        auto [r1, c1] = blacks[a];
        for (int b = a + 1; b < K; b++) {
            auto [r2, c2] = blacks[b];
            bool ok = false;
            // 路径 1：先水平到 (r1,c2)，再垂直到 (r2,c2)
            if (rowFull(r1, min(c1, c2), max(c1, c2))
                && colFull(c2, min(r1, r2), max(r1, r2)))
                ok = true;
            // 路径 2：先垂直到 (r2,c1)，再水平到 (r2,c2)
            if (!ok && colFull(c1, min(r1, r2), max(r1, r2))
                && rowFull(r2, min(c1, c2), max(c1, c2)))
                ok = true;
            if (!ok) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}


signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

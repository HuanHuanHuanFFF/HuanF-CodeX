//
// Created by 幻 on 2025/7/2.
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

constexpr bool more = false;

// 2022 - 2023 ICPC,NERC
/* K. 环面路径
 * link: https://codeforces.com/contest/1765/problem/K
 * 标签: 贪心, 矩阵, 遍历, 数学证明
 * 思路:
 * 1 反对角瓶颈: 任路径最多访问 n-1 个反对角点->跳过最小值
 * 2 遍历矩阵计算 sum 及反对角最小值 min
 * 3 输出 sum-min
 * 时间复杂度 O(n^2) 空间复杂度 O(n^2)
 */
void HuanF() {
    int n;
    cin >> n;
    vector g(n, vector<int>(n));
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            sum += g[i][j];
        }
    }
    int min = INF;
    for (int i = 0; i < n; ++i) {
        min = std::min(min, g[i][n - 1 - i]);
    }
    cout << sum - min;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/30.
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

// Codeforces Round 1010 (Div. 2, Unrated) 
/* 2082A - Binary Matrix
 * link: https://codeforces.com/contest/2082/problem/A
 * 标签: 贪心, 矩阵, XOR
 * 思路:
 *   1. 统计每行的 XOR 值, 若为 1 则 hor++
 *   2. 统计每列的 XOR 值, 若为 1 则 ver++
 *   3. 修改一个元素会同时改变其所在行和列的 XOR => hor 和 ver 各自 +/-1
 *      因此最少操作次数为 max(hor, ver)
 * 时间复杂度: O(n*m)
 * 空间复杂度: O(n*m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector mat(n, vector<int>(m));
    int ver = 0, hor = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int k = 0;
        for (int j = 0; j < m; ++j) {
            mat[i][j] = s[j] - '0';
            k ^= mat[i][j];
        }
        if (k) ++hor;
    }
    for (int i = 0; i < m; ++i) {
        int k = 0;
        for (int j = 0; j < n; ++j) {
            k ^= mat[j][i];
        }
        if (k) ++ver;
    }
    cout << std::max(ver, hor) << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

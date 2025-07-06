//
// Created by 幻 on 2025/7/3.
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

// Codeforces Round 997 (Div. 2) 
/* 2056B-FindPermutation
 * link: https://codeforces.com/contest/2056/problem/B
 * 标签: 排序 自定义比较器 图建模
 * 思路: 若 g[a][b]=='1' 表示 a 在最终排列中排在 b 前面。该关系为严格全序，可直接作为
 *       比较器 cmp(x,y): g[x][y]=='1' ? x<y : x>y。对 0..n-1 排序后 +1 即得唯一排列。
 *       时间复杂度 O(n log n)，空间复杂度 O(n^2)（存邻接矩阵）。
 */
void HuanF() {
    int n;
    cin >> n;
    vector g(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    vector<int> p(n);
    std::ranges::iota(p, 0);
    std::ranges::sort(p, [&](int x, int y) {
        return g[x][y] == '1' ? x < y : x > y;
    });
    for (auto &x: p) cout << x + 1 << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/19.
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

// Order Capital Round 1 (Codeforces Round 1038, Div. 1 + Div. 2) 
/* 2122C-Manhattan Pairs
 * link: https://codeforces.com/contest/2122/problem/C
 * 标签: 排序 · 集合划分 · 贪心 · 曼哈顿距离
 * 思路:
 *   1. 全局按 x 升序排序，将前 n/2 点归为 X0，后 n/2 点归为 X1
 *   2. 在 X0 内按 y 升序排序，分出 A（Y0 小半区）与 B（Y1 大半区）
 *   3. 在 X1 内按 y 升序排序，分出 C 与 D
 *   4. 跨半区配对：A↔D、B↔C，保证同时跨越 X0↔X1（x 维最优）与 Y0↔Y1（y 维最优）
 *   推论证明: 只要配对跨半区，x 维距离和恒为最大；同理 y 维；二者叠加即全局最优
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<std::array<int, 3> > ps(n);
    int i = 0;
    for (auto &[x,y,pos]: ps) cin >> x >> y, pos = ++i;
    std::ranges::sort(ps, [](auto a, auto b) { return a[0] < b[0]; });
    int p = n / 2;
    std::sort(ps.begin(), ps.begin() + p, [](auto a, auto b) { return a[1] < b[1]; });
    std::sort(ps.begin() + p, ps.end(), [](auto a, auto b) { return a[1] < b[1]; });
    for (i = 0; i < n / 2; ++i) {
        cout << ps[i][2] << " " << ps[n - i - 1][2] << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

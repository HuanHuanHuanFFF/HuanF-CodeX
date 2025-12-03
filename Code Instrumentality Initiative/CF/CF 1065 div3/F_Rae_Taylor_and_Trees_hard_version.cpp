//
// Created by 幻 on 2025/12/2.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = true;

/* Rae Taylor and Trees (hard version)
 * link: https://codeforces.com/contest/2171/problem/F
 * 标签: 构造, 贪心, 前缀最小, 后缀最大, 树
 * 思路:
 * 1) 设 p 为排列, 对下标 i 预处理
 *    pre[i] = min(p[1..i]), suf[i] = max(p[i..n])
 *    若存在 i 使 pre[i-1] > suf[i], 说明在位置 i 左右两段中
 *    左段所有点的编号都大于右段所有点, 根据题目给定的合法连边规则
 *    左右之间不可能存在任意一条边, 图必不连通, 因此无解.
 *    反之若对所有 i 都有 pre[i-1] <= suf[i], 可以证明总能构造出一棵生成树:
 *    任意经过该切分线的生成树边, 至少可以从右段最大值 suf[i] 连向左段中
 *    的某个最小值 pre[i-1], 因为它们的相对位置与大小满足题目中允许连边的条件.
 * 2) 设所有满足 p[i] = suf[i] 的下标为 r1 < r2 < ... < rk,
 *    它们把排列划分成 k 个连续块, 每块的最大值是该块末尾 p[rt].
 *    在每一块内, 把块末尾元素 p[rt] 作为根, 与本块中前面的每个元素 p[j]
 *    (上一块结尾之后到 rt-1) 连边, 这一部分显然只在块内连边, 不会破坏合法性,
 *    且能把每一块内部连成一棵星形树.
 * 3) 再在不同块之间连边: 对相邻两块 [.., r_{t-1}] 和 [r_{t-1}+1, .., r_t],
 *    把前一块前缀最小值 pre[r_{t-1}] 与后一块根 p[r_t] 连边.
 *    因为根据 1) 中的条件, 在切分点 r_{t-1}+1 处仍满足
 *    pre[r_{t-1}] <= suf[r_{t-1}+1] = p[r_t],
 *    二者满足题意的连边条件, 从而可以作为跨块的一条合法树边.
 *    如此对所有相邻块连边后, k 个块被串成一棵整体生成树, 共得到 n-1 条边.
 * 4) 综上, 判定条件就是检查是否存在 pre[i-1] > suf[i],
 *    若不存在则按上述方式按块构造即可.
 * 时间复杂度: 每组 O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> p(n + 1), pre(n + 1, INF), suf(n + 2), idx;
    idx.reserve(n);
    for (auto &x: p | std::views::drop(1)) cin >> x;
    for (int i = 1; i <= n; ++i) pre[i] = std::min(pre[i - 1], p[i]);
    for (int i = n; i >= 1; --i) suf[i] = std::max(suf[i + 1], p[i]);
    for (int i = 2; i <= n; ++i) {
        if (pre[i - 1] > suf[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        if (p[i] == suf[i]) idx.emplace_back(i);
    }
    vector<PII> edges;
    edges.reserve(n - 1);
    for (int y = 0; auto &x: idx) {
        while (y < x - 1) edges.emplace_back(p[x], p[++y]);
        y = x;
    }
    for (int i = 1; i < idx.size(); ++i) {
        edges.emplace_back(pre[idx[i - 1]], p[idx[i]]);
    }
    for (auto &[x,y]: edges) cout << x << " " << y << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

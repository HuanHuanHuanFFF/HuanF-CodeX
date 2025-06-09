//
// Created by 幻 on 2025/6/8.
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

// Codeforces Round 988 (Div. 3) 
/* 2037D
 * link: https://codeforces.com/contest/2037/problem/D
 * 标签: 贪心、优先队列、模拟
 * 思路:
 *  1. 按题意给定的障碍区间和增益点已分别按左端点和位置升序，无需额外排序
 *  2. 使用大顶堆(heap)存储已遇到的所有 power-up 增益值
 *  3. jump 初始为 1；遍历每个障碍区间 [l,r]：
 *     - 将所有位置 < l 的 power-up 增益入堆
 *     - 若 jump <= (r - l + 1)，说明当前跳跃力不足，以最少次数从堆中取出最大增益，不断累加至 jump > (r - l + 1)，同时 ans++
 *     - 若堆空且仍无法越过，直接输出 -1 结束
 *  4. 所有障碍处理完毕后，输出 ans
 * 时间复杂度 O((n + m) log m)
 * 空间复杂度 O(m)
 */
void HuanF() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<PII> box(n), power(m);
    for (auto &[x,y]: box) cin >> x >> y;
    for (auto &[x,y]: power) cin >> x >> y;
    std::priority_queue<int> heap;
    int idx = 0, jump = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
        while (idx < m && power[idx].first < box[i].first) {
            heap.emplace(power[idx].second);
            ++idx;
        }
        while (box[i].second - box[i].first + 1 >= jump && heap.size()) {
            jump += heap.top();
            heap.pop();
            ++ans;
        }
        if (box[i].second - box[i].first + 1 >= jump) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

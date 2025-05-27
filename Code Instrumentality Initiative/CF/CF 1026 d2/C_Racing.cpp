//
// Created by 幻 on 2025/5/24.
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

// Codeforces Round 1026 (Div. 2) 
/* C. Racing
 * link: https://codeforces.com/contest/2110/problem/C
 * 思路:
 *  1 前向区间DP
 *    维护 low[i],high[i] 表示走到第 i 步后高度 h_i 的最小/最大可行值
 *    若 d[i]==-1 则 h_i 可以与 h_{i-1} 保持不变或 +1 否则固定 +d[i]
 *    然后与障碍区间 [l[i],r[i]] 做交集 若交集空则无解
 *  2 逆向回溯重建
 *    从后往前选定终点高度 h_n=low[n]
 *    对 i=n…1：
 *      若 d[i]==-1
 *        尝试不升(设为0)看能否让 h_{i-1}=h_i 落入 [low[i-1],high[i-1]]
 *        否则就升(设为1) 并 h_{i-1}=h_i-1
 *      若 d[i]==1 则 h_{i-1}=h_i-1
 *      d[i]==0 时 h_{i-1}=h_i
 *    保证每一步 h_{i-1} ∈ [low[i-1],high[i-1]]
 *  模块化 + Occam's razor 保证简单易懂
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> d(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }
    vector<int> low(n + 1), high(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (d[i] == -1) {
            low[i] = low[i - 1];
            high[i] = high[i - 1] + 1;
        } else {
            low[i] = low[i - 1] + d[i];
            high[i] = high[i - 1] + d[i];
        }
        low[i] = std::max(low[i], l[i]);
        high[i] = std::min(high[i], r[i]);
        if (low[i] > high[i]) {
            cout << "-1\n";
            return;
        }
    }
    int h = low[n];
    for (int i = n; i >= 0; --i) {
        if (d[i] == -1) {
            if (low[i - 1] <= h && h <= high[i - 1]) {
                d[i] = 0;
            } else {
                d[i] = 1;
                --h;
            }
        } else if (d[i] == 1) {
            --h;
        }
    }
    for (int i = 1; i <= n; ++i) cout << d[i] << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

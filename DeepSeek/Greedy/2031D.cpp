//
// Created by 幻 on 2025/5/28.
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

// Codeforces Round 987 (Div. 2) 
/* 2031D-彭奇克与沙漠兔
 * link: https://codeforces.com/contest/2031/problem/D
 * 标签: 前缀最大, 后缀最小, 联通块, 贪心
 * 思路:
 * 1. 计算 pre_high[i]=max(a[1..i])，记录从左到 i 的最大高度
 * 2. 计算 suf_low[i]=min(a[i..n])，记录从 i 到右端的最小高度
 * 3. 初始化 ans 从原数组 a 复制
 * 4. 从右向左遍历 i 从 n 到 1：
 *    - ans[i] = max(pre_high[i], ans[i])  // 保证自身及右侧可达的最大高度
 *    - 若 pre_high[i-1] > suf_low[i]，说明前缀和后缀可通过高于低的两棵树互相连通，
 *      则从 i-1 出发能到达的最大高度与 i 相同：ans[i-1] = ans[i]
 * 5. 输出 ans[1..n]
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), suf_low(n + 2), pre_high(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> ans(a);
    suf_low[n + 1] = INF;
    for (int i = n; i > 0; --i) {
        suf_low[i] = std::min(a[i], suf_low[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        pre_high[i] = std::max(a[i], pre_high[i - 1]);
    }
    for (int i = n; i > 0; --i) {
        ans[i] = std::max(pre_high[i], ans[i]);
        if (pre_high[i - 1] > suf_low[i]) ans[i - 1] = ans[i];
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
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

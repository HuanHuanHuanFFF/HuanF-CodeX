//
// Created by 幻 on 2025/6/11.
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

// Codeforces Round 1004 (Div. 2) 

/* E. White Magic - 2067E
 * link: https://codeforces.com/contest/2067/problem/E
 * 标签: 贪心 数组 前缀最小 后缀 MEX 模拟
 * 思路:
 *   1. 统计数组中零的个数 cnt0，并记录第一个零的位置 p
 *   2. 若 cnt0==0 或 n==1，则整个序列均可为魔法序列，直接输出 n
 *   3. 计算从末尾到位置 p 的后缀 MEX(mex[i])：
 *      - 用布尔数组 has[0..n] 记录已出现的数值
 *      - x 初始为 0，向前遍历 i 从 n 到 p，先标记 a[i] 再更新 x 直到 has[x]==false
 *   4. 计算从开头到 p 的前缀最小 minv[i]：
 *      - minv[0]=INF，minv[i]=min(minv[i-1], a[i])
 *   5. 对每个 i≤p 检查：若 minv[i] < mex[i]，则无法包含恰一个零，答案为 n-cnt0
 *   6. 否则可以取左most零及所有非零元素，答案为 n-cnt0+1
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), mex(n + 1), min(n + 1, INF);
    int p = -1, cnt0 = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0 && p == -1) p = i;
        if (!a[i]) ++cnt0;
    }
    if (cnt0 == 0 || n == 1) {
        cout << n << "\n";
        return;
    }
    vector<bool> has(n + 1);
    for (int i = n; i >= p; --i) {
        if (a[i] <= n) has[a[i]] = true;
    }
    int x = 0;
    for (int i = p - 1; i > 0; --i) {
        while (has[x]) ++x;
        mex[i] = x;
        if (a[i] <= n) has[a[i]] = true;
    }
    for (int i = 1; i <= p; ++i) {
        min[i] = std::min(min[i - 1], a[i]);
    }
    for (int i = 1; i <= p; ++i) {
        if (min[i] < mex[i]) {
            cout << n - cnt0 << "\n";
            return;
        }
    }
    cout << n - cnt0 + 1 << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

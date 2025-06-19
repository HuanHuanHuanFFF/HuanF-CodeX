//
// Created by 幻 on 2025/6/17.
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

// Codeforces Round 1006 (Div. 3)
/* 2072C-Creating Keys for StORages Has Become My Main Skill
 * link: https://codeforces.com/problemset/problem/2072/C
 * 标签: 位运算OR、构造、贪心、MEX
 * 思路:
 *   目标: 构造长度 n 的数组 a, 满足
 *         1) a1|a2|…|an == x
 *         2) MEX(a) 最大
 *
 *   核心策略 (遵循奥卡姆剃刀):
 *   ① 连续放入 0,1,2,…,i, 但仅当 (i | x) == x          // i 只含 x 已有的二进制位
 *      - 这样 OR 不超出 x, 同时保证出现值尽量连续, 提高 MEX
 *   ② 若 still < n, 余下全填 x                         // 确保最终 OR 达到 x
 *   ③ 若累积 OR p != x, 将最后一个合法 i 改成 x         // 修正缺失二进制位
 *
 *   正确性证明:
 *     · 步骤① 中所有元素按位 OR ≤ x
 *     · 步骤②/③ 至少出现一次 x, 因此整体 OR == x
 *     · 前缀 0…cnt-1 均出现, MEX ≥ cnt, 极大化
 *
 *   复杂度:
 *     时间 O(n)      // 最多遍历到 n 或 x ≤ 2e5
 *     空间 O(n)      // 存答案数组
 */
void HuanF() {
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << x << "\n";
        return;
    }
    int cnt = 1, p = 0;
    vector<int> ans(n);
    ans[0] = 0;
    for (int i = 1; i <= x; ++i) {
        if ((i | x) == x && cnt < n) {
            ans[cnt++] = i;
            p |= i;
        } else break;
    }
    for (int i = cnt; i < n; ++i) {
        ans[i] = x;
        p |= x;
    }
    if (p != x) ans[cnt - 1] = x;
    for (auto &i: ans) cout << i << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

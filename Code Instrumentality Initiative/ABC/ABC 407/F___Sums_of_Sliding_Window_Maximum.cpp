//
// Created by 幻 on 2025/5/24.
//
#include <bits/stdc++.h>

using namespace std;

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


// AtCoder Beginner Contest 407 
/* F - Sums of Sliding Window Maximum
 * link: https://atcoder.jp/contests/abc407/tasks/abc407_f
 * 标签: 单调栈, 差分, 前缀和, 线性函数
 * 思路:
 *  1. 用单调栈或 std::set 求出每个 i 的 L_i, R_i：
 *     L_i: 向左连续比 A[i] 小的个数；R_i: 向右连续比 A[i] 小的个数。
 *  2. 对每个 i，令 x_min = min(L_i, R_i), x_max = max(L_i, R_i)，
 *     划分出三段 k 对应的一次函数贡献：
 *       1 ≤ k ≤ 1 + x_min         贡献 = A[i] * k
 *       1 + x_min < k ≤ 1 + x_max  贡献 = A[i] * (1 + x_min)
 *       1 + x_max < k ≤ 1 + x_min + x_max 贡献 = A[i] * (2 + x_min + x_max - k)
 *       其他 k 贡献 = 0
 *  3. 使用“二次差分”合并所有 i 的贡献：维护 D2[0..N+2]，
 *     对每个 i（令 v = A[i]）执行四次点更新：
 *       D2[ 1 ]                       += +v;
 *       D2[ 1 + x_min + 1 ]           += -v;
 *       D2[ 1 + x_max + 1 ]           += -v;
 *       D2[ 1 + x_min + x_max + 2 ]   += +v;
 *     这样一次性把三段一次函数加到 D2 中。
 *  4. 做两次前缀和还原答案：
 *     // 第一次前缀和：D1[j] = D1[j-1] + D2[j]
 *     // 第二次前缀和：ans[j] = ans[j-1] + D1[j]
 *     输出 ans[1..N].
 * 时间复杂度: O(N)  （单调栈/集合 O(N) + 二次差分更新 O(N) + 前缀和 O(N)）
 * 空间复杂度: O(N)
 */
void HuanF() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // --- 1. 计算 L[i], R[i] （左右连续小于 A[i] 的长度） ---
    vector<int> L(N), R(N);
    // 先从左往右，用递减单调栈找“左第一个 ≥ A[i]”的位置
    {
        stack<int> stk; // 存下标，A[stk.top()] > A[next]
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && A[stk.top()] < A[i]) {
                int idx = stk.top();
                stk.pop();
                // 右边第一个 ≥ A[idx] 就是 i
                R[idx] = i - idx - 1;
            }
            stk.push(i);
        }
        // 栈里剩下的，右边没有更大或等于的位置
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            R[idx] = N - idx - 1;
        }
    }
    // 再从右往左，用递减单调栈找“右第一个 ≥ A[i]”的位置
    {
        stack<int> stk;
        for (int i = N - 1; i >= 0; i--) {
            while (!stk.empty() && A[stk.top()] <= A[i]) {
                int idx = stk.top();
                stk.pop();
                // 左边第一个 > A[idx] 就是 i
                L[idx] = idx - i - 1;
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            L[idx] = idx;
            // idx - (-1) - 1 = idx
        }
    }

    // --- 2. 准备二次差分数组 D2[0..N+2] ---
    vector<ll> D2(N + 3, 0);

    // --- 3. 对每个 i，将它对所有 k 的三段一次函数贡献叠加到 D2 ---
    for (int i = 0; i < N; i++) {
        ll v = A[i];
        // 计算 x_min, x_max
        int x_min = min(L[i], R[i]);
        int x_max = max(L[i], R[i]);
        // 按照二次差分更新四个点
        // ① D2[1] += +v    （1-based 长度索引）
        D2[1] += v;
        // ② D2[1 + x_min + 1] += -v
        D2[1 + x_min + 1] -= v;
        // ③ D2[1 + x_max + 1] += -v
        D2[1 + x_max + 1] -= v;
        // ④ D2[1 + x_min + x_max + 2] += +v
        D2[1 + x_min + x_max + 2] += v;
    }

    // --- 4. 两次前缀和还原答案 ---
    // 第一次前缀和：D1[j] = D1[j-1] + D2[j]
    vector<ll> D1(N + 3, 0);
    D1[0] = D2[0];
    for (int j = 1; j <= N + 2; j++) {
        D1[j] = D1[j - 1] + D2[j];
    }
    // 第二次前缀和：ans[j] = ans[j-1] + D1[j]
    vector<ll> ans(N + 1, 0);
    ans[0] = D1[0];
    for (int j = 1; j <= N; j++) {
        ans[j] = ans[j - 1] + D1[j];
    }

    // --- 输出 ans[1..N] ---
    for (int k = 1; k <= N; k++) {
        cout << ans[k] << "\n";
    }
}


signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

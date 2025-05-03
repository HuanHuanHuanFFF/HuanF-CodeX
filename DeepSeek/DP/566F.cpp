#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e6 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* 566F-Clique in the Divisibility Graph
 * link: https://codeforces.com/problemset/problem/566/F
 * 思路:
 *   1 标记数组 has[N] 表示输入中出现的数
 *   2 初始化 dp[i]=1 表示单个数自成链
 *   3 遍历数组 a 中每个 x 枚举其倍数 i=x*2; i<N; i+=x
 *     若 has[i] 则 dp[i]=max(dp[i], dp[x]+1)
 *   4 最终答案 ans=max(dp[i])
 * 时间复杂度 O(N log N)
 * 空间复杂度 O(N)
* 示例图:
 *       3
 *     / | \
 *    v  v  v
 *    6  9  12
 *     \ |    \
 *      vv     v
 *      18     24
 *       \     /  \
 *        v   v    v
 *         72      48
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> dp(N, 1), a(n);
    vector<bool> has(N);
    for (auto &x: a) {
        cin >> x;
        has[x] = true;
    }
    for (auto &x: a) {
        for (int i = x << 1; i < N; i += x) {
            if (has[i])
                dp[i] = std::max(dp[x] + 1, dp[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = std::max(dp[i], ans);
    }
    cout << ans;
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

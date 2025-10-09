//
// Created by 幻 on 2025/8/16.
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
constexpr ll MOD = 998244353;
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

constexpr bool more = false;

// AtCoder Beginner Contest 419 
/* ABC419-E 子数组和的可除性
 * link: https://atcoder.jp/contests/abc419/tasks/abc419_e
 * 标签: 模同余, 分组, 环形距离, 背包DP, (min,+)卷积, 滚动数组
 * 思路:
 * 1. 等价变形
 *    设长度为 L 的滑窗和 S_x = A_x + ... + A_{x+L-1}
 *    若所有 S_x ≡ 0(mod M), 则 S_{x+1}-S_x = -A_x + A_{x+L} ≡ 0 ⇒ A_{x+L} ≡ A_x
 *    反之若 A_i ≡ A_{i+L} ≡ A_{i+2L}... 且 S_1 ≡ 0, 则递推得所有 S_x ≡ 0
 *    因此问题化为: 对每条链 C_i = {i, i+L, i+2L, ...} 统一到某余数且总目标余数和 ≡ 0(mod M)
 * 2. 组内代价
 *    只能 +1, 对链内每个 a[p] 变到目标余数 k 的费用为 (k - a[p]) mod M
 *    代码中对每条链固定 k 累加 val 即得到该链的最小费用 f_i(k)
 * 3. 组间 DP
 *    dp[j] = 已处理若干链, 其目标余数和 ≡ j 的最小费用
 *    对当前链的每个目标 k, 做 ndp[(j+k)%M] = min(ndp[(j+k)%M], dp[j] + f_i(k))
 *    初值 dp[0]=0, 其余为 INF, 答案为 dp[0]
 * 证明要点: 组间转移是环上 (min,+) 卷积, 具备交换律与结合律, 与处理顺序无关
 * 时间复杂度: O(M*N + L*M^2) 其中求各链 f_i(k) 的总代价 O(M*N), DP 为 O(L*M^2)
 * 空间复杂度: O(M)
 */
void HuanF() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (auto &x: a) cin >> x, x %= m;
    vector<int> dp(m, INF);
    dp[0] = 0;
    for (int i = 0; i < l; ++i) {
        vector<int> ndp(m, INF);
        for (int k = 0; k < m; ++k) {
            int val = 0;
            for (int p = i; p < n; p += l) {
                if (a[p] > k) val += k + m - a[p];
                else val += k - a[p];
            }
            for (int j = 0; j < m; ++j)
                ndp[(j + k) % m] = std::min(ndp[(j + k) % m], dp[j] + val);
        }
        std::swap(ndp, dp);
    }
    cout << dp[0];
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

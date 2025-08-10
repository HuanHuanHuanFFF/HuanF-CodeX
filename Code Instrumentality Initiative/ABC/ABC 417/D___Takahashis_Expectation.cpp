//
// Created by 幻 on 2025/8/2.
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

// AtCoder Beginner Contest 417 
/* ABC417-D
 * link: https://atcoder.jp/contests/abc417/tasks/abc417_d
 * 标签: 逆序DP, 前缀和, 状态压缩, 查询离线
 * 思路:
 * 1. 设 dp[i][v] 为处理完第 i 件礼物后且当前心情为 v 时最终心情
 *    - 逆序遍历 i, 因转移仅依赖 i+1
 *    - 只需枚举 v∈[0,1000] 因为 P_i,A_i,B_i≤500 → v 最大 1000
 * 2. 对于查询 X>1000, 心情必先持续下降
 *    - 预存 B 的前缀和 pre, 用 lower_bound 找最早使 X−pre[k]≤1000 的 k
 *    - 从第 k+1 件礼物、心情 X−pre[k] 开始查 dp
 * 3. 预处理 O(N·1000), 每次查询 O(log N) 二分 + O(1) 查表
 * 时间复杂度: 预处理 O(N·1000) + 查询 O(Q log N)
 * 空间复杂度: O(N·1000)
 */
void HuanF() {
    int n;
    cin >> n;
    vector dp(n, vector<int>(1001));
    vector<std::array<int, 3> > pab(n);
    for (auto &[p,a,b]: pab) cin >> p >> a >> b;
    for (int i = n - 1; i >= 0; --i) {
        auto &[p,a,b] = pab[i];
        if (i == n - 1)
            for (int v = 0; v <= 1000; ++v) {
                if (p >= v) dp[i][v] = v + a;
                else dp[i][v] = std::max(0, v - b);
            }
        else
            for (int v = 0; v <= 1000; ++v) {
                if (p >= v) dp[i][v] = dp[i + 1][v + a];
                else dp[i][v] = dp[i + 1][std::max(0, v - b)];
            }
    }
    vector<int> pre(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) pre[i] = pab[i][2];
        else pre[i] = pre[i - 1] + pab[i][2];
    }
    int q;
    std::map<int, int> ans;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        if (ans.contains(x)) {
            cout << ans[x] << "\n";
            continue;
        }
        int idx = 0, cpx = x;
        if (x > 1000) {
            int dis = x - 1000;
            auto it = std::ranges::lower_bound(pre, dis);
            if (it == pre.end()) --it;
            x -= *it;
            idx = it - pre.begin();
            ++idx;
        }
        if (idx <= n - 1 && x <= 1000) {
            cout << dp[idx][x] << "\n";
            ans[cpx] = dp[idx][x];
        } else {
            cout << x << "\n";
            ans[cpx] = x;
        }
    }
}

// 水数据 假做法
// void HuanF() {
//     int n;
//     cin >> n;
//     std::map<int, int> ans;
//     vector<std::array<int, 3> > pab(n + 1);
//     vector<int> pre(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> pab[i][0] >> pab[i][1] >> pab[i][2];
//         pre[i] = pre[i - 1] + pab[i][2];
//     }
//     int q;
//     cin >> q;
//     while (q--) {
//         int x;
//         cin >> x;
//         if (ans.contains(x)) {
//             cout << ans[x] << "\n";
//             continue;
//         }
//         int idx = 1, xp = x;
//         if (x > 500) {
//             int dis = x - 500;
//             auto it = std::ranges::upper_bound(pre, dis);
//             --it;
//             x -= *it;
//             idx = it - pre.begin() + 1;
//         }
//         for (int i = idx; i <= n; ++i) {
//             if (pab[i][0] >= x) x += pab[i][1];
//             else x = std::max(x - pab[i][2], 0);
//         }
//         ans[xp] = x;
//         cout << x << "\n";
//     }
// }

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T--) HuanF();
    return 0;
}

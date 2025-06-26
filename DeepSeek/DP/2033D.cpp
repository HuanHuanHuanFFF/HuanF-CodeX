//
// Created by 幻 on 2025/6/26.
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

// Codeforces Round 981 (Div. 3) 
/* 2033D - Kousuke's Assignment
 * link: https://codeforces.com/contest/2033/problem/D
 * 标签: 前缀和, 哈希表, 动态规划
 * 思路:
 * 1 计算前缀和 pre[i]=pre[i-1]+a[i] 用 ll 避免溢出
 * 2 map<ll,int> mp 记录前缀和最后出现位置 mp[0]=0
 *   遍历 i 若 mp.contains(pre[i]) 则 last[i]=mp[pre[i]]
 *   更新 mp[pre[i]]=i
 * 3 dp 递推 dp[i]=dp[i-1] 若 last[i]!=INF 则 dp[i]=max(dp[i],dp[last[i]]+1)
 * 4 输出 dp[n]
 * 时间复杂度 O(n log n) 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    std::map<ll, int> mp;
    vector<int> last(n + 1, INF);
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (mp.contains(pre[i])) {
            last[i] = mp[pre[i]];
        }
        mp[pre[i]] = i;
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (last[i] != INF)
            dp[i] = std::max(dp[i], dp[last[i]] + 1);
    }
    int ans = std::ranges::max(dp);
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

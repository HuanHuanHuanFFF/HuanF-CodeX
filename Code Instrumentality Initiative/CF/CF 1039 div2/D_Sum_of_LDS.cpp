//
// Created by 幻 on 2025/7/27.
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

// Codeforces Round 1039 (Div. 2) 
/* 2128D
 * link: https://codeforces.com/contest/2128/problem/D
 * 标签: 一维DP, 前缀和, 序列性质
 * 思路:
 * 1 利用“禁止连续三项严格递增”性质，最长下降子序列只依赖相邻两项关系
 * 2 定义 f 为以当前下标 i 结尾的所有子数组的 LDS 长度之和
 * 3 遍历 i：
 *   - i==0 时 f=1
 *   - 若 a[i-1]>a[i]，则此前以 i-1 结尾的 i 个子数组均可 +1 且新增子数组 [i..i] 长度 1，故 f+=i+1
 *   - 否则只有新增子数组的 LDS=1，故 f+=1
 * 4 累加 ans += f，最终输出 ans
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    ll f = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) f = 1;
        else {
            if (a[i - 1] > a[i]) f += i + 1;
            else ++f;
        }
        ans += f;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

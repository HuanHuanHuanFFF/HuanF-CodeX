#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 998244353;
constexpr ll INF = 4e17 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Problem: Toxel 与 PCPC II
// 思路（遵循奥卡姆剃刀与模块化原则）：
//   将所有有 bug 的行编号存于数组 a[1..m]。
//   定义 dp[i] 为修复前 i 个 bug 的最小耗时。
//   转移：最后一次调试覆盖第 j+1..i 个 bug，
//     耗时 = dp[j] + 运行到 a[i] 的时间 a[j] + （i−j）^4 的 debug 时间。
//   由于 debug 时间随 (i−j)^4 急速增长，超过某个常数阈值后必然不优，
//   因此只需枚举最近的固定数量（如 88）个前驱 j。
//   阈值 88 由 88^4 ≈6e7 远大于行号最大值 2e5 得出：更大的调试批次必定更慢。
//   故总体复杂度 O(m · 88)
//  （无需额外证明，基于四次方增长速度足以屏蔽所有更长区间）
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m + 1);
    vector<ll> dp(m + 1, INF);
    for (int i = 1; i <= m; ++i) cin >> a[i];
    dp[0] = 0;
    for (int i = 0; i <= m; ++i) {
        for (int j = i + 1; j <= std::min(m, i + 88); ++j) {
            dp[j] = std::min(dp[j], dp[i] + a[j] + (j - i) * (j - i) * (j - i) * (j - i));
        }
    }
    cout << dp[m] << "\n";
}

signed main() {
    IOS();
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

/*
20 20
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/

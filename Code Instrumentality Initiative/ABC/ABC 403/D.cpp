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

/* ABC403 D - Forbidden Difference
 * link: https://atcoder.jp/contests/abc403/tasks/abc403_d
 * 思路:
 * 1) 统计 cnt[x] 为每个值 x 在序列中出现的次数
 * 2) 如果 d==0 则只能保留每个值一个，需删除 sum(cnt[x]-1)
 * 3) 否则按 x mod d 分成 d 组，每组内按下标 i=r, r+d, r+2d... 做线性 DP：
 *    dp0 = 前一个位置被删的最小删数
 *    dp1 = 前一个位置被保留的最小删数
 *    对当前计数 c = cnt[i]：
 *      ndp0 = min(dp0, dp1) + c   // 删除当前，需删 c 个
 *      ndp1 = dp0                // 保留当前，则前一个必须删
 *    更新 dp0 = ndp0, dp1 = ndp1
 *    该组最少删除 = min(dp0, dp1)
 * 4) 累加所有组的删除数即为答案
 * 时间复杂度 O(N + maxA)
 * 空间复杂度 O(maxA)
 */
void HuanF() {
    int n, d;
    cin >> n >> d;
    vector<int> cnt(N), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    ll ans = 0;
    if (d == 0) {
        for (int i = 0; i < N; ++i) {
            if (cnt[i]) ans += cnt[i] - 1;
        }
        cout << ans;
        return;
    }

    for (int r = 0; r < d; ++r) {
        ll dp0 = 0, dp1 = 0; //删还是不删
        for (int i = r; i < N; i += d) {
            ll c = cnt[i];
            ll ndp0 = std::min(dp0, dp1) + c; //删的话从上一次的结果中选代价最小的
            ll ndp1 = dp0; //不删现在的,上一个必须删
            dp0 = ndp0;
            dp1 = ndp1;
        }
        ans += std::min(dp0, dp1);
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

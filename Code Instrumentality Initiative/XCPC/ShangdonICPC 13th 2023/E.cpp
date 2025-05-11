#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* E-数学问题
 * link: https://codeforces.com/gym/104417/problem/E
 * 思路:
 * 因为加的是k-1,乘后再除一定是亏的
 * 所以对 n 进行若干次“除法操作”(花费 b)和“加法操作”(花费 a)的组合,使最终值是 m 的倍数
 * 利用两重循环: 外层枚举进行了 i 次除法后 n_i = n / k^i, 累计花费 nowA = i*b
 * 内层枚举在当前 n_i 上进行 j 次加法,使 n_i*k^j 跨到或达到 m 的倍数边界:
 *   通过比较 ⌊n_i/m⌋ 与 ⌊(n_i*k^j -1)/m⌋ 或余数是否为0 来判断是否可达
 * 一旦满足条件,更新最小花费并跳出内层
 * 特殊情况: 当 n_i==0 时,剩余操作只能是除法,直接更新答案
 * 时间复杂度 O((log n)^2)
 * 空间复杂度 O(1)
 */
void HuanF() {
    ll n, k, m, a, b;
    cin >> n >> k >> m >> a >> b;
    if (k == 1) {
        if (n % m != 0) cout << -1 << "\n";
        else cout << 0 << "\n";
        return;
    }
    ll ans = INF;
    ll nowA = 0;
    while (n) {
        ll now = nowA;
        for (__int128 i = n, add = 1, j = 0; j <= 60; i *= k, ++j, add *= k) {
            if (i / m < (i + add - 1) / m || i % m == 0 || (i + add - 1) % m == 0) {
                ans = std::min(ans, now);
                break;
            }
            now += a;
        }
        n /= k;
        nowA += b;
        if (n == 0) {
            ans = std::min(nowA, ans);
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

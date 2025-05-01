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
constexpr int INF = 1e8 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

//void HuanF() {
//    // cout << (1ll << 60) << "\n";
//    ll n, ans = 0;
//    vector<ll> a(59);
//    // std::set<ll> st;
//    cin >> n;
//    for (int i = 1; i <= 59; ++i) {
//        a[i - 1] = 1ll << i;
//    }
//    for (int i = 0; i < 59; ++i) {
//        ll j = 3;
//        if (n >= a[i]) ++ans;
//        // if (n >= a[i] * 2 * 2) ++ans;
//        while (n >= a[i] * j * j) {
//            ++ans;
//            j += 2;
//        }
//    }
//    cout << ans;
//}
//枚举居然过了,看到答案是公式和二分没绷住

/* C-2^a-b^2
 * link: https://atcoder.jp/contests/abc400/tasks/abc400_c
 * 核心思路（Why）：
 *  唯一表示：每个正整数对 2 的幂次分解唯一，
 *    X = 2^k * B，且 B 为奇数
 *  分两类：
 *    1. a 为奇数 a=2u+1 时：
 *       X = 2^{2u+1} * b^2
 *         = 2 * (2^u * b)^2
 *       这类好数形如 2 * y^2
 *    2. a 为偶数 a=2v (v ≥ 1) 时：
 *       X = 2^{2v} * b^2
 *         = (2^v * b)^2
 *         = 4 * (2^{v-1} * b)^2
 *       这类好数形如 4 * z^2
 *  上述两类互不重叠：
 *    若 s^2 = 2 * t^2，则 (s/t)^2 = 2 ⇒ √2 有理 ⇒ 矛盾
 *
 * 如何计数（How）：
 *  - 奇数次幂类：2*y^2 ≤ N ⇒ y ≤ √(N/2)
 *      个数 = ⌊√(N/2)⌋
 *  - 偶数次幂类：4*z^2 ≤ N ⇒ z ≤ √(N/4)
 *      个数 = ⌊√(N/4)⌋
 *  总答案 = ⌊√(N/2)⌋ + ⌊√(N/4)⌋
 */
void HuanF() {
    long double n;
    cin >> n;
    ll ans = std::floor(std::sqrt(n / 2))
             + std::floor(std::sqrt(n / 4));
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

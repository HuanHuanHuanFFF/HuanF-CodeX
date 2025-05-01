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
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* A-Once In My Life
 * 思路:
 * 1 构造一个基础幸运数 base = 1234567890 + d;
 *   - 该数包含数字 1~9 各一次,并且 d 出现两次(末位与原有一处)
 *   - 虽包含一个 0, 但题目只要求 1~9 且至少两个 d, 0 不影响
 * 2 为了使 n*k = 幸运数, 需令 n*k ≡ base (mod n)
 *   - 将 base 左移 t 位(乘 10^t)不会破坏其 "幸运" 属性, 因为只在末尾补 0
 *   - 选择 t 足够大(如 使 10^t > n), 可确保后续调余操作只影响最低 t 位
 * 3 令 nk = base * 10^t;
 *   - 计算 rem = nk % n, 若 rem != 0, 则加上 (n - rem) 使其可被 n 整除
 *   - 此操作只改变 nk 的最低 t 位, 不会新增或删除 1~9 中的任一位, 也不影响 d 的出现次数
 * 4 最终 k = nk / n, 直接输出即可
 * 时间复杂度 O(log n) (基于乘 10 直到超过 n 的次数)
 * 空间复杂度 O(1)
 */
void HuanF() {
    ll n, d;
    cin >> n >> d;
    ll nk = 1234567890ll + d;
    for (ll i = 1; i <= n; i *= 10) {
        nk *= 10;
    }
    nk += n - nk % n;
    // cout << nk << "\n";
    cout << nk / n << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

/*
3
 1 6
 12345678 9
 233 2
*/

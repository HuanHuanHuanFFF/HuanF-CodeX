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
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// 非官解
/* 2108B-SUMdamental Decomposition
 * link: https://codeforces.com/contest/2108/problem/B
 * 思路 :
 * 1. 初始化 ans = x，xp = x，cnt = n，总剩余需要配合异或的元素数 cnt。
 * 2. 扫描 x 的二进制位，遇到 1 则 cnt--，表示这一位由 x 自身贡献，不再额外添加。
 * 3. 对位索引 len 从 0 开始：
 *    - 计算当前位最小需要使用的奇数个数 use = cnt + (cnt % 2)。
 *    - add 默认为 INF 表示待选，若此位 x_bit=1 且 n-1<2 则 add=0（无须额外数）。
 *    - 若 n 为奇数：add = min(max(use, 2), n-1)。
 *      否则 n 为偶数：若 x_bit=1 则 add = min(max(use,2), n-2)；否则 add = min(max(use,2), n)。
 *    - 在第 len 位上添加 add 个 '1'，更新 ans += add << len，cnt -= add。
 *    - len++，xp >>= 1，继续向高位处理，直至 cnt==0。
 *    - 若 len 达到 33 仍未凑完 cnt，返回 -1。
 * 4. 输出最终 ans 即为最小元素和。
 * 时间复杂度 O(log x)，空间复杂度 O(1)。
 */
void HuanF() {
    ll n, x;
    cin >> n >> x;
    ll ans = x, xp = x, cnt = n, len = 0;
    while (xp) {
        if (xp & 1) {
            --cnt;
        }
        xp >>= 1;
    }
    xp = x;
    while (cnt > 0) {
        ll use = cnt + cnt % 2, add = INF;
        if (xp & 1 && n - 1 < 2) add = 0;
        if (n & 1) {
            if (add != 0)
                add = std::min(std::max(use, 2ll), n - 1);
        } else {
            if (add != 0)
                if (xp & 1)
                    add = std::min(std::max(use, 2ll), n - 2);
                else
                    add = std::min(std::max(use, 2ll), n);
        }
        ans += add << len;
        cnt -= add;
        ++len;
        if (len == 33) {
            cout << "-1\n";
            return;
        }
        xp >>= 1;
        // cout << ans << "\n";
    }
    cout << ans << "\n";
}

/* 2108B-SUMdamental Decomposition
 * link: https://codeforces.com/contest/2108/problem/B
 * 思路注释 (官方解法):
 * 1. 统计 x 的二进制 1 的个数 c = __builtin_popcountll(x)
 * 2. 若 n ≤ c：
 *    - 只需要将 x 的每个 1 分配到不同元素上，最小和即为 x，本身就是答案。
 * 3. 若 n > c：
 *    - 先用 n−c 个 1 来补足元素个数，基础和为 x + (n−c)。
 *    - 额外补 1 的异或结果是 (n−c)%2，需要与 x 的奇偶保持一致。
 *    - 若 (n−c)%2 == 0：无需再加，直接输出 x + (n−c)。
 *    - 若 (n−c)%2 == 1：
 *        a) 若 x > 1：再加一个 1 修正奇偶，输出 x + (n−c) + 1。
 *        b) 若 x == 1：无法单独加 1，此时用 [2,3] 或 [1,2,3] 组合修正，最小额外成本为 3，输出 n + 3。
 *        c) 若 x == 0：
 *           - n == 1：无解，输出 -1。
 *           - 否则同样需要三元组 [1,2,3]，输出 n + 3。
 * 4. 整体时间复杂度 O(1)，空间复杂度 O(1)
*/
void solution() {
    int n, x;
    cin >> n >> x;
    int bits = __builtin_popcountll(x);
    if (n <= bits) {
        // 元素数不足以分配额外 1
        cout << x << "\n";
        return;
    }
    int rem = n - bits;
    if (rem % 2 == 0) {
        // 补充 rem 个 1，异或不变
        cout << x + rem << "\n";
    } else {
        // 需要修正异或奇偶
        if (x > 1) {
            cout << x + rem + 1 << "\n";
        } else if (x == 1) {
            cout << n + 3 << "\n";
        } else {
            // x == 0
            if (n == 1) cout << -1 << "\n";
            else cout << n + 3 << "\n";
        }
    }
}


signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    // solution();
    return 0;
}

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
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* ABC404-E
 * link: https://atcoder.jp/contests/abc404/tasks/abc404_e
 * 思路:
 * 1. 对每个碗 i (1 ≤ i < N) 若 A[i] > 0 且 i > pre，则需要处理新豆子源头。
 * 2. 维护已覆盖最左边界 pre = 0，操作计数 res = 0。
 * 3. 对于新源头 i，令 [l, r] = [i, i]，循环：
 *    - 每次操作 res++，将区间 [l, r] 更新为 [min_{j∈[l,r]}(j - C[j]), r]。
 *    - 直到 l ≤ pre 为止，表示已与之前的路径合并或到达0。
 * 4. 更新 pre = i，继续处理下一个源头。
 * 这样不同源头间的路径若在 pre 左侧合并，则不重复计数。
 * 时间复杂度 O(N^2)，空间复杂度 O(N)。
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 1; i < n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i) cin >> a[i];
    int pre = 0, res = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == 0 || i <= pre) continue;
        int l = i, r = i;
        while (l > pre) {
            ++res;
            int nl = l;
            for (int j = l; j <= r; ++j) {
                nl = std::min(nl, j - c[j]);
            }
            l = nl;
        }
        pre = i;
    }
    cout << res;
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

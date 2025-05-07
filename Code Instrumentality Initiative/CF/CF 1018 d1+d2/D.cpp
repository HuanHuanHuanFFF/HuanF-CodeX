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

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* D. 精彩的灯泡 2096D
 * link: https://codeforces.com/contest/2096/problem/D
 * 思路:
 *   1 模2不变性: 每次翻转4盏灯, 开灯总数保持奇数
 *   2 统计每条竖线 x=c 上开灯数, 唯一奇数行即为 s
 *   3 统计每条对角线 x+y=c 上开灯数, 唯一奇数对角和即为 s+t
 *   4 得到 t = (s+t) - s
 * 时间复杂度: O(n log n) 使用 map 统计
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    int ansX = 0, ansY = 0;
    std::map<int, int> x_cnt, plus_cnt;
    // x_cnt 记录每个 x 坐标的灯泡数量
    // plus_cnt 记录每条对角线 x+y 的灯泡数量
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        ++x_cnt[x];
        ++plus_cnt[x + y];
    }
    for (auto &[x,c]: x_cnt) {
        if (c & 1) {
            ansX = x;
            break;
        }
    }
    for (auto &[sum,c]: plus_cnt) {
        if (c & 1) {
            ansY = sum - ansX;
            break;
        }
    }
    cout << ansX << " " << ansY << "\n";
}

// 偷看hmm代码发现的,太巧妙了,我必须偷来
void solve() {
    int n;
    cin >> n;
    int ansX = 0, ansS = 0;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        ansX ^= x;
        ansS ^= x + y;
    }
    cout << ansX << " " << ansS - ansX << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        solve();
    // HuanF();
    return 0;
}

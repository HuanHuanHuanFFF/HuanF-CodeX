//
// Created by 幻 on 2025/7/9.
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

// Codeforces Round 899 (Div. 2) 
/* B-1882B
 * link: https://codeforces.com/problemset/problem/1882/B
 * 标签: 暴力枚举 贪心 集合 并集
 * 思路:
 * 1 统计每个元素 x 出现总次数 cnt[x] 及它所在集合列表 in[x]
 * 2 枚举需排除的元素 x:
 *   2.1 遍历所有包含 x 的集合索引 idx in[x], 将集合 sets[idx] 中的元素计数累加到 c[e]
 *   2.2 令 now=cnt.size(), 对每个元素 e 若 c[e]==cnt[e] 则说明 e 仅存在于包含 x 的集合中, 从 now 中减去 1
 *   2.3 now 即为排除 x 后所有不含 x 的集合并集大小
 * 3 答案 ans 为所有 x 枚举所得 now 的最大值
 * 时间复杂度 O(n·m) 其中 n 为集合数, m 为平均集合大小
 */
void HuanF() {
    int n;
    cin >> n;
    vector<vector<int> > sets(n);
    std::map<int, int> cnt;
    std::map<int, vector<int> > in;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        sets[i].reserve(k);
        for (int j = 0, x; j < k; ++j) {
            cin >> x;
            sets[i].emplace_back(x);
            ++cnt[x];
            in[x].emplace_back(i);
        }
    }
    int ans = 0;
    for (auto [x,y]: cnt) {
        std::map<int, int> c;
        for (auto &idx: in[x]) {
            for (auto &e: sets[idx])
                ++c[e];
        }
        int now = cnt.size();
        for (auto &[cx,cy]: c) {
            if (cy == cnt[cx]) --now;
        }
        ans = std::max(now, ans);
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

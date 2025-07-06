//
// Created by 幻 on 2025/7/6.
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

// Codeforces Round 997 (Div. 2)
/* 题目: D. Unique Median
 * link: https://codeforces.com/problemset/problem/2056/D
 * 标签: 枚举,前缀和,哈希
 * 思路:
 * 1 设全部子数组数 all = n(n+1)/2
 * 2 针对每个候选中位数 x∈[1,10]:
 *   a 构造 b[i]=(a[i]>x?+1:-1) 并得前缀和 pre
 *   b 用 map<int,int> cnt 仅在扫到 a[i]==x 时把 pre[0..i] 加入
 *     保证随后统计的区间必含 x
 *   c bad += cnt[pre[i+1]] 统计和为 0 的偶长区间
 * 3 good = all - bad
 * 推论: 偶长区间若「>x 与 ≤x 数量相等」且区间含 x, 排序后第 k 与 k+1 位同为 x, 中位数不唯一
 * 证明: 长度 2k, ≤x 恰 k 个, >x 恰 k 个, 中央相邻两位皆为 x
 * 时间复杂度 O(10n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    ll all = n * (n + 1) / 2, bad = 0;
    for (int x = 1; x <= 10; ++x) {
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (a[i] > x ? 1 : -1);
        }
        std::map<int, int> cnt;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                while (j <= i) {
                    ++cnt[pre[j++]];
                }
            }
            bad += cnt[pre[i + 1]];
        }
    }
    cout << all - bad << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/1.
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

// Codeforces Round 1034 (Div. 3)
/* E. MEX Count
 * link: https://codeforces.com/problemset/problem/2123/E
 * 标签: 二分, 数据结构, 贪心, 排序, 双指针
 * 思路:
 *   1 统计频率 cnt[i] 及原始 mex
 *   2 对每个 i 从 mex 到 0 枚举
 *     - 若要 mex=i 则删光所有 i ⇒ k>=cnt[i]
 *     - 同时保留 0..i-1 各至少一个 ⇒ k<=n-i
 *     ⇒ k∈[cnt[i],n-i] 都可达
 *     - 用差分 d[cnt[i]]++ d[n-i+1]-- 标记
 *   3 前缀和恢复 ans[k]
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> vis(n + 1);
    for (auto &x: a) {
        cin >> x;
        vis[x] = true;
    }
    int max = -1;
    for (int i = 0; i <= n; ++i) {
        if (vis[i]) max = i;
        else break;
    }
    ++max;
    vector<int> cnt(n + 1), d(n + 2);
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }
    for (int i = max; i >= 0; --i) {
        ++d[cnt[i]];
        --d[n - i + 1];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += d[i];
        cout << ans << " ";
    }
    cout << "\n";
}

/* E. MEX Count
 * link: https://codeforces.com/problemset/problem/2123/E
 * 标签: 哈希计数, 动态集合, 贪心
 * 思路:
 *   1 统计每个值出现次数 cnt[x]，并用 vis[] 找到原始 mex
 *   2 构造 c[k] 存放出现次数恰为 k 的所有值
 *   3 用集合 vals 维护当前可达的 MEX 值
 *     - 初始 k=0 时，只有原始 mex
 *     - 每次增 1 删除数 k：
 *       • 删除 vals 中 > n-k 的值 ⇒ vals.erase(n-k+1)
 *       • 对于 c[k] 中每个 v，若 v ≤ min(mex, n-k)，加入 vals
 *   4 输出每个 k 的 vals.size()
 * 时间复杂度 O(n log n)（map+set 操作），空间复杂度 O(n)
 */
void HuanF2() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> vis(n + 1);
    std::map<int, int> cnt;
    for (auto &x: a) {
        cin >> x;
        vis[x] = true;
        ++cnt[x];
    }
    int mex = -1;
    while (vis[mex + 1]) ++mex;
    ++mex;
    std::set<int> vals;
    std::map<int, vector<int> > c;
    for (auto &[x,y]: cnt) {
        c[y].emplace_back(x);
    }
    vals.insert(mex);
    for (int k = 0; k <= n; ++k) {
        vals.erase(n - k + 1);
        for (auto v: c[k])
            if (v <= std::min(mex, n - k))
                vals.insert(v);
        cout << vals.size() << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

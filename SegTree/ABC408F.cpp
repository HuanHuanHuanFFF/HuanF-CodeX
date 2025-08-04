//
// Created by 幻 on 2025/6/10.
//
#include <bits/stdc++.h>

using namespace std;

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

constexpr bool more = false;

// 自定义功能1-idx线段树
template<typename T>
struct SegmentTree {
    int n;
    vector<T> t;
    function<T(T &, T &)> merge;
    T init_v;

    SegmentTree(int n, function<T(T &, T &)> merge, T init_v)
        : n(n), merge(merge), init_v(init_v) {
        t.assign(4 * (n + 1), init_v);
    }

    // 构建：输入数组 a[1..n]
    void build(const vector<T> &a) {
        build(1, 1, n, a);
    }

    // 单点更新：将位置 pos 的值设为 v
    void update(int pos, const T &v) {
        update(1, 1, n, pos, v);
    }

    // 区间查询：[L, R]
    T query(int L, int R) {
        return query(1, 1, n, L, R);
    }

private:
    void build(int p, int l, int r, const vector<T> &a) {
        if (l == r) {
            t[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        t[p] = merge(t[p << 1], t[p << 1 | 1]);
    }

    void update(int p, int l, int r, int pos, const T &v) {
        if (l == r) {
            t[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) update(p << 1, l, m, pos, v);
        else update(p << 1 | 1, m + 1, r, pos, v);
        t[p] = merge(t[p << 1], t[p << 1 | 1]);
    }

    T query(int p, int l, int r, int L, int R) {
        if (r < L || R < l) return init_v;
        if (L <= l && r <= R) return t[p];
        int m = (l + r) >> 1;
        T left = query(p << 1, l, m, L, R);
        T right = query(p << 1 | 1, m + 1, r, L, R);
        return merge(left, right);
    }
};

// AtCoder Beginner Contest 408 
/* F - Athletic
 * link: https://atcoder.jp/contests/abc408/tasks/abc408_f
 * 标签: 排列, 动态规划, 线段树
 * 思路:
 *  1. 输入 heights 是 1…n 的排列，用 p[h[i]] = i+1 记录高度到位置的映射
 *  2. 定义 dp[i] = 从高度为 i 的脚手架开始的最大移动次数，按 i 从 1 到 n 递增计算
 *  3. 用线段树维护已更新的 dp 值，索引为脚手架位置（1…n）：
 *     - 若 i-D ≥ 1，则将 dp[i-D] 更新到线段树中位置 p[i-D]
 *     - 查询区间 [ max(1, p[i]-r), min(n, p[i]+r) ] 的最大值 mx
 *  4. 令 dp[i] = mx + 1
 *  5. 答案为 dp 数组的最大值
 *
 * 时间复杂度 O(N log N)，空间复杂度 O(N)
 */
void HuanF() {
    int n, d, r;
    cin >> n >> d >> r;
    vector<int> h(n), p(n + 1), dp(n + 1);
    for (auto &x: h) cin >> x;
    for (int i = 0; i < n; ++i) p[h[i]] = i + 1;
    auto merge = [](int a, int b) { return std::max(a, b); };
    SegmentTree<int> seg(n, merge, -INF);
    for (int i = 1; i <= n; ++i) {
        if (i - d >= 1) seg.update(p[i - d], dp[i - d]);
        int mx = seg.query(std::max(1, p[i] - r), std::min(n, p[i] + r));
        dp[i] = std::max(dp[i], mx + 1);
    }
    cout << *ranges::max_element(dp) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

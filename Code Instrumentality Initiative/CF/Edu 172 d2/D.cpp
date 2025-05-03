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

// 离线处理和有序集合是这题的灵魂
/* 2042D - Recommendations
 * link: https://codeforces.com/contest/2042/problem/D
 * 标签:
 *   扫描线 (Sweep Line)、区间覆盖 (Interval Cover)、离线处理 (Offline Processing)、
 *   平衡树 (Balanced BST)、对称化 (Symmetry Transformation)
 * 本质:
 *     需要在线性时间内求解各集合的交集,可以先通过离线处理,
 *     将所有可能的预测者先放到set中,然后直接二分查找计算一侧的答案,重复两次
 *     - 一维用于排序以做离线扫描 (按 l 升序，l 相同时 r 降序)
 *     - 另一维通过有序集合快速查询边界 (set.lower_bound 查询最小 r_j)
 *   通过对称镜像处理左右端点，实现左右推荐的统一求解。
 *
 * 处理流程：
 *   1. 读入 n 个区间到 seg[]；
 *   2. 初始化 ans[i]=0，用于累加左/右两侧推荐长度；
 *   3. 重复两轮：
 *      - 排序所有区间索引为 order[], 按 (l ↑, r ↓)；
 *      - 用 set<int> rights 存放已扫过区间的 r 值；
 *      - 遍历 order: 对 idx:
 *          * 用 rights.lower_bound(seg[idx].r) 找到最小 ≥ r_i 的 border；
 *          * 累加 |border - r_i| 到 ans[idx]；
 *          * rights.insert(r_i)；
 *      - 镜像所有 seg: [l,r] → [-r,-l] 用于计算另一侧。
 *   4. 去重：对原始区间若出现多次，ans 置 0；
 *   5. 输出 ans[]。
 *
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    struct node {
        int l, r;

        bool operator<(const node &o) const {
            if (l != o.l) return l < o.l;
            return r < o.r;
        }
    };
    cin >> n;
    vector<node> nodes(n);
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].l >> nodes[i].r;
    }

    // 两次相同流程：一次求右侧推荐长度，一次求左侧推荐长度（镜像后）
    for (int t = 0; t < 2; ++t) {
        // 构建扫描顺序：l 升序，l 相同时 r 降序
        vector<int> order(n);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](int i, int j) {
            if (nodes[i].l != nodes[j].l) return nodes[i].l < nodes[j].l;
            return nodes[i].r > nodes[j].r;
        });
        std::set<int> rights; // 已处理区间的右端点集合
        for (auto &idx: order) {
            int r = nodes[idx].r;
            auto it = rights.lower_bound(r);
            //!已加入集合的都是可能的预测者!
            if (it != rights.end())
                ans[idx] += abs((ll) *it - r);
            // 当前区间可作为后续更大 l 的 predictors
            rights.insert(r);
        }
        // 镜像转换：[-r,-l]，下一轮处理另一侧
        for (auto &node: nodes) {
            auto l = -node.r, r = -node.l;
            node.l = l, node.r = r;
        }
    }

    // 去重：相同原区间多次出现，强烈推荐数置 0
    std::map<node, int> cnt;
    for (auto &node: nodes) ++cnt[node];
    for (int i = 0; i < n; ++i) {
        if (cnt[nodes[i]] > 1) ans[i] = 0;
    }
    for (auto &x: ans) cout << x << "\n";
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

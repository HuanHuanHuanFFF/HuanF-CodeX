//
// Created by 幻 on 2025/5/12.
//
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

template<typename T>
struct BIT {
    int n;
    vector<T> t;

    explicit BIT(int n): n(n), t(vector<T>(n + 1)) {
    }

    int lowbit(int x) { return x & -x; }

    //单点修改
    void add(int x, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            t[i] += val;
        }
    }

    //查询前缀和
    ll pre_sum(int x) {
        ll ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += t[i];
        }
        return ans;
    }

    //查询闭区间和
    ll query(int l, int r) {
        return pre_sum(r) - pre_sum(l - 1);
    }
};

/* F - 和弦交叉
 * link: https://atcoder.jp/contests/abc405/tasks/abc405_f
 * 思路:
 * 1. 将 2N 个点中所有弦的端点计数到 pre 数组, 然后前缀和求出区间 (u,v) 内端点总数 E
 * 2. 将 chords 按左端 a 降序排序, 将查询 ask 按左端 x 降序排序, 离线处理保证 a>u 时先激活
 * 3. 用 BIT 在右端点 b 处做 add, 激活后的弦记为 1, 通过 pre_sum 快速查询在 b<v 的激活数 P
 * 4. 每个查询答案 ans = E - 2*P, 因为完全在区间内的弦贡献 2, 刚好一端在区间内的弦贡献 1
 * 时间复杂度 O((M+Q) log (2N)), 空间复杂度 O(N)
 */
void HuanF() {
    int n, m;
    cin >> n >> m; // 读入 N 和 M
    vector<PII> chords(m);
    vector<int> pre(n << 1 | 1); // pre 用于记录每个点是否为端点

    // 读入所有弦, 同时在 pre 数组标记端点
    for (auto &[x, y]: chords) {
        cin >> x >> y;
        ++pre[x]; // 标记点 x
        ++pre[y]; // 标记点 y
    }
    // 构造前缀和, pre[i] = 点 1..i 中端点的总数
    for (int i = 1; i <= (n << 1); ++i) {
        pre[i] += pre[i - 1];
    }

    int q;
    cin >> q; // 读入查询数 Q
    vector<std::array<int, 3> > ask(q);
    vector<int> ans(q);
    // 读入所有查询, ask[i] = {x, y, id}
    for (int i = 0; i < q; ++i) {
        cin >> ask[i][0] >> ask[i][1];
        ask[i][2] = i; // 保存原始索引
    }
    // 将 chords 按左端降序, 保证后续扫描时 a>u 的先处理
    sort(chords.begin(), chords.end(), std::greater<>());
    // 将查询也按左端 x 降序
    sort(ask.begin(), ask.end(), std::greater<>());

    BIT<int> bit(n << 1 | 1); // Fenwick 树, 大小为 2N
    int idx = 0; // chords 中当前未激活的下标

    // 离线处理每个查询
    for (int i = 0; i < q; ++i) {
        auto &[x, y, id] = ask[i]; // x = u, y = v, id = 原索引
        // 激活所有 a > x 的弦, 在其右端 b 处 +1
        while (idx < m && chords[idx].first > x) {
            bit.add(chords[idx].second, 1);
            ++idx;
        }
        // P = 已激活弦中右端 b < y 的数量
        ll P = bit.pre_sum(y - 1);
        // E = pre[y-1] - pre[x], 区间 (x,y) 内的端点总数
        int E = pre[y - 1] - pre[x];
        ans[id] = E - P * 2; // 交叉弦数 = E - 2*P
    }

    // 输出所有答案, 恢复原始顺序
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

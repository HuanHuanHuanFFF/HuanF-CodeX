#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}


struct BIT {
    vector<int> t;
    int n;

    BIT(int n): t(n + 1), n(n) {
    }

    int lowbit(int x) { return x & -x; }

    void set(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            t[i] = std::max(t[i], x);
        }
    }

    int get(int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            ans = std::max(ans, t[i]);
        }
        return ans;
    }
};

constexpr bool more = false;

/* 美团笔试第三题-两个排列的字典序最大的最长公共子序列
 * link: unknown
 * 标签: LCS转LIS, 树状数组, 贪心, 构造
 * 思路:
 * 两个序列都是排列。
 * 先记录 q 中每个值的位置 pos[x]，
 * 再把 p 中每个值替换为 pos[x]。
 *
 * 这样原问题转成：
 * 在新数组中求 LIS，
 * 且要求对应原值序列字典序最大。
 *
 * 设 suf[i] 表示：
 * 以第 i 个位置作为开头时，
 * 最长能取多少个。
 *
 * 从右往左做 DP。
 * 若当前映射值为 p[i]，
 * 需要接到右边比它大的位置后面。
 *
 * 把值域翻转为 n + 1 - p[i]，
 * 这样"右边比它大"就转成
 * 前缀最大值查询，
 * 可用树状数组维护。
 *
 * 再按 suf 分桶。
 * 当前还要选 rem 个数时，
 * 只需在 suf == rem 的桶里找。
 *
 * 一个位置合法，当且仅当：
 * 原数组下标在上次选择之后，
 * 且在 q 中的位置也在上次之后。
 *
 * 在当前桶内按原值从大到小扫描，
 * 取第一个合法位置。
 * 这样可保证当前位尽量大，
 * 从而得到字典序最大的答案。
 *
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto &x: p) cin >> x;
    for (auto &x: q) cin >> x;
    vector<int> cp(p);
    std::map<int, int> pos;
    for (int i = 0; i < n; ++i) pos[q[i]] = i + 1;
    for (auto &x: p) x = pos[x];
    BIT dp(n);
    vector<int> suf(n + 1);
    for (int i = n; i > 0; --i) {
        suf[i] = dp.get(n + 1 - p[i - 1]) + 1;
        dp.set(n + 1 - p[i - 1], suf[i]);
    }
    std::map<int, vector<PII> > bucket;
    for (int i = 0; i < n; ++i) {
        bucket[suf[i + 1]].emplace_back(cp[i], i);
    }
    vector<int> ans;
    ans.reserve(bucket.rbegin()->first);
    int idx = -1, qpos = -1;
    for (auto &[x,y]: bucket | std::views::reverse) {
        std::ranges::sort(y, std::greater<>());
        for (auto &[f,s]: y) {
            if (s > idx && pos[f] > qpos) {
                idx = s;
                qpos = pos[f];
                ans.emplace_back(f);
                break;
            }
        }
    }
    for (auto &x: ans) cout << x << " ";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

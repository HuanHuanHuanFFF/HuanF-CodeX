//
// Created by 幻 on 2025/6/22.
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
constexpr int MOD = 998244353;
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

/* F. 小苯的序列分段
 * link: https://ac.nowcoder.com/acm/contest/112078/F
 * 标签: 前缀后缀最大, 划分计数, 模拟
 * 思路:
 *   1 记录 b 中每个值在 a 中的位置 pos[], 验证 pos 严格递增 否则输出 0
 *   2 检查 a[0..pos[0]-1] 区间无大于 b[0] 元素 和 a[pos[m-1]+1..n-1] 区间无大于 b[m-1] 元素 否则输出 0
 *   3 对每对相邻 i=0..m-2:
 *     - 在区间 [pos[i],pos[i+1]] 构造 pre[j]=max(a[pos[i]..pos[i]+j]) 和 suf[j]=max(a[pos[i]+j..pos[i+1]])
 *     - 分界点 k 对应 j=k-pos[i] 合法当且仅当 pre[j]<=a[pos[i]] 且 suf[j+1]<=a[pos[i+1]]，统计 cnt_i
 *   4 答案为 所有 cnt_i 的乘积 mod
 * 证明:
 *   若分界点左侧存在大于 b_i 的元素 则该段最大值无法为 b_i 同理右侧
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    int i, j;
    vector<int> p(m);
    for (i = 0, j = 0; i < n && j < m; ++i) {
        if (a[i] == b[j]) {
            p[j] = i;
            ++j;
        }
    }
    if (j != m) {
        cout << 0 << "\n";
        return;
    }
    for (i = 0; i < p[0]; ++i) {
        if (a[i] > b[0]) {
            cout << 0 << "\n";
            return;
        }
    }
    for (i = n - 1; i > p.back(); --i) {
        if (a[i] > b.back()) {
            cout << 0 << "\n";
            return;
        }
    }
    vector<ll> cnt;
    cnt.reserve(m);
    for (i = 0; i < m - 1; ++i) {
        int len = p[i + 1] - p[i] + 1;
        vector<int> pre(len), suf(len);
        pre[0] = a[p[i]];
        for (j = 1; j < len; ++j) {
            pre[j] = std::max(pre[j - 1], a[p[i] + j]);
        }
        suf[j - 1] = a[p[i + 1]];
        for (j = len - 2; j >= 0; --j) {
            suf[j] = std::max(suf[j + 1], a[p[i] + j]);
        }
        ll c = 0;
        for (j = 0; j < len - 1; ++j)
            if (pre[j] <= a[p[i]] && suf[j + 1] <= a[p[i + 1]])
                ++c;
        cnt.emplace_back(c);
    }
    ll ans = 1;
    for (auto &c: cnt) ans = ans * c % MOD;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

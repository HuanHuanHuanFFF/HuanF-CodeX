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
constexpr int N = 1e5 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<vector<int> > factors(N), pos(N + 1);

void init() {
    IOS();
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            factors[j].push_back(i);
        }
    }
}

//function f(k, a, l, r):
//  ans := 0
//  for i from l to r (inclusive):
//      while k is divisible by a[i]:
//          k := k/a[i]
//      ans := ans + k
//  return ans

/* 2094-H 拉瓦卡萨图尔诺萨图尔尼塔
 * link: https://codeforces.com/contest/2094/problem/H
 * 思路:
 * - 预处理 [1..A] 范围内所有整数的因子列表 divisors
 * - 读入数组 a，记录每个值 v 在 pos[v] 的出现下标
 * - 每次查询 (k, l, r):
 *   1. 枚举 k 的所有因子 d
 *   2. 在 pos[d] 中二分找出首次 ≥ l 的位置 idx（且 idx ≤ r），收集 (idx, d) 事件
 *   3. 按 idx 升序处理事件：累加段长度 × 当前 k，然后在事件点除尽因子
 *   4. 最后累加 [prev, r] 段的贡献
 * - 时间：预处理 O(A·logA)，每次查询 O(d(k)·logn + d(k)·logd(k))
 */

void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), used;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (pos[a[i]].empty()) used.push_back(a[i]);
        pos[a[i]].push_back(i);
    }
    for (int i = 0, k, l, r; i < q; ++i) {
        cin >> k >> l >> r;
        vector<PII> events;
        // 收集所有会影响 k 的变化事件 (idx, f)
        for (auto f: factors[k]) {
            auto &v = pos[f];
            if (v.empty()) continue;
            // 二分找出第一个 ≥ l 的下标
            auto it = std::lower_bound(v.begin(), v.end(), l);
            if (it != v.end() && *it <= r) {
                events.emplace_back(*it, f);
            }
        }
        sort(events.begin(), events.end());

        long long ans = 0;
        long long cur = k; // 当前剩余的 k
        int prev = l; // 上一次变化发生的位置

        // 依次处理每个事件
        for (auto &ev: events) {
            int idx = ev.first;
            int d = ev.second;
            // 累加 [prev, idx-1] 上的 cur
            if (idx > prev) {
                ans += (long long) (idx - prev) * cur;
            }
            // 在 idx 处将 cur 中的因子 d 全部除尽
            while (cur % d == 0) {
                cur /= d;
            }
            prev = idx; // 更新上次事件位置
        }

        // 剩余区间 [prev, r] 的贡献
        if (prev <= r) {
            ans += (long long) (r - prev + 1) * cur;
        }

        cout << ans << "\n";
    }

    // 清空本测试中使用过的 pos 列表
    for (int v: used) {
        pos[v].clear();
    }
}


signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

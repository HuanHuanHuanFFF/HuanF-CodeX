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

// 自解
/* 2042B
 * link: https://codeforces.com/contest/2042/problem/B
 * 思路:
 * 1 统计每种颜色的数量 cnt 需要前置知识: 哈希表或 map
 * 2 使用最小堆(剩余数量, 颜色) 保存各颜色当前剩余个数
 * 3 模拟 n 步操作
 *   - 第 i 步 从堆顶弹出 (cn, co)
 *   - 若 i 为偶数(0 起) 表示 Alice 拿取 则 alice[co]++
 *   - cn-- 后若 cn>0 则将 (cn, co) 重新入堆
 * 4 遍历 alice 对于每个颜色 co:
 *   - 若 alice[co]>=1 则 ans++
 *   - 若 alice[co]==cnt[co] 则 ans++
 * 5 输出 ans
 * 时间复杂度 O(n log n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> color(n);
    for (auto &c: color) cin >> c;
    std::priority_queue<PII, vector<PII>, std::greater<> > heap;
    std::map<int, int> cnt, alice;
    for (auto &c: color) ++cnt[c];
    for (auto &[co,cn]: cnt) {
        heap.emplace(cn, co);
    }
    for (int i = 0; i < n; ++i) {
        auto [cn,co] = heap.top();
        heap.pop();
        if ((i & 1) == 0)
            ++alice[co];
        --cn;
        if (cn != 0) heap.emplace(cn, co);
    }
    int ans = 0;
    for (auto &[co,cn]: alice) {
        ++ans;
        if (cn == cnt[co]) ++ans;
    }
    cout << ans << "\n";
}

// 官解
/* 2042B
 * link: https://codeforces.com/contest/2042/problem/B
 * 思路:
 * 1 统计每种颜色的数量 cnt  需要前置知识: 哈希表或数组统计
 * 2 计算 exactly1 = cnt==1 的颜色数, morethan1 = cnt>1 的颜色数
 * 3 对于唯一颜色数 exactly1, Alice 与 Bob 轮流拿走, Alice 可拿 ⌈exactly1/2⌉ 个, 每个得2分 => total1 = 2 * ⌈exactly1/2⌉
 * 4 对于剩余每种颜色都有 ≥2 个的 morethan1 颜色, Alice 始终可得1分 => total2 = morethan1
 * 5 最终答案 ans = total1 + total2
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i], --c[i];
    vector<int> cnt(n);
    for (int x: c) cnt[x]++;
    int exactly1 = 0, morethan1 = 0;
    for (int x: cnt) {
        if (x == 1) exactly1++;
        else if (x > 1) morethan1++;
    }
    int total1 = ((exactly1 + 1) / 2) * 2;
    int ans = total1 + morethan1;
    cout << ans << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        // HuanF();
        solve();
    return 0;
}

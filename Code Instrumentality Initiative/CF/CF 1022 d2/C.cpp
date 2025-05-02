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

/* 2108C-Neo's Escape
 * link: https://codeforces.com/contest/2108/problem/C
 * 思路:
 * 1. 将相邻且具有相同权重的按钮合并，得到一个权重-位置对的序列 p，其中位置 pos 为合并后序列的索引。
 * 2. 合并后序列长度为 cnt，表示独立的区段。我们需要为每个区段分配一个 clone，按权重从大到小处理，优先重用已有 clone 如果邻近区段已被按压。
 * 3. 对 p 按权重降序排序，然后遍历每个 (weight, pos)：
 *    - 如果 pos 的左右相邻区段 has[pos-1] 或 has[pos+1] 中有任一已被按压（即已有 clone 可移动过来），则当前区段无需新建 clone。
 *    - 否则，需要新建一个 clone，ans++。
 *    - 标记 has[pos] = true，表示该区段已按压并可为邻段提供 clone 支持。
 * 4. 最后输出 ans，即最少需要创建的 clone 数。
 * 时间复杂度: O(n log n)（排序），空间复杂度: O(n)
 */
void HuanF() {
    int n, ans = 0;
    cin >> n;
    vector<PII> p;
    int cnt = 0, last = -1;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x != last) {
            p.emplace_back(x, cnt++);
            last = x;
        }
    }
    vector<bool> has(cnt);
    std::sort(p.begin(), p.end());
    std::reverse(p.begin(), p.end());
    for (auto &[x,pos]: p) {
        if ((pos - 1 >= 0 && has[pos - 1]) || (pos + 1 < cnt && has[pos + 1])) {
            has[pos] = true;
        } else {
            ++ans;
            has[pos] = true;
        }
    }
    cout << ans << "\n";
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

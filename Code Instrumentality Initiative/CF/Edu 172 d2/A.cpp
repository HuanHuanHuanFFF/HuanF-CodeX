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

/* 2042A
 * link: https://codeforces.com/contest/2042/problem/A
 * 思路:
 * 1 先对数组按降序排序 需要前置知识: 排序算法和贪心算法基础
 * 2 从头遍历排序后的数组,累加元素到 now 中
 * 3 当再加下一个元素会使 now + a[i] > k 时停止
 * 4 此时 now <= k,剩余任何元素都太大,只能补充 k-now 个硬币,使 Monocarp 恰好取到 k 个硬币
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::sort(a.begin(), a.end(), std::greater<>());
    int now = 0;
    for (int i = 0; i < n; ++i) {
        if (now + a[i] > k) break;
        now += a[i];
    }
    cout << k - now << "\n";
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

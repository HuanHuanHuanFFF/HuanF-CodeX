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

/* P1650-田忌赛马
 * link: https://www.luogu.com.cn/problem/P1650
 * 思路:
 *   1 排序两队马速度 升序排序
 *   2 初始化双指针: 我方最慢 i=0, 最快 j=n-1; 对手最慢 x=0, 最快 y=n-1
 *   3 循环对决 当 i<=j:
 *     3.1 若 a[i]>b[x]: 我方最慢能胜对手最慢 赢一场 win++, i++, x++
 *     3.2 否则若 a[j]>b[y]: 我方最快能胜对手最快 赢一场 win++, j--, y--
 *     3.3 否则: 用我方最慢 vs 对手最快 牺牲一场
 *         若 a[i]<b[y] 则视作失败 win--
 *         i++, y--
 *   4 最终收益 = win * 200
 * 时间复杂度 O(n log n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int i = 0, j = n - 1, x = 0, y = n - 1, win = 0;
    while (i <= j) {
        if (a[i] > b[x]) {
            ++win;
            ++i;
            ++x;
        } else if (a[j] > b[y]) {
            ++win;
            --j;
            --y;
        } else {
            if (a[i] < b[y]) --win;
            --y;
            ++i;
        }
    }
    cout << win * 200;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/24.
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

// Codeforces Round 252 (Div. 2) 
/* C. Valera and Tubes
 * link: https://codeforces.com/problemset/problem/441/C
 * 思路:
 * 1 按行蛇形遍历整个 n×m 表格,保持坐标 (x,y) 从 (1,1) 开始
 *   奇数行向右走,偶数行向左走,遇到边界换行并翻转方向
 * 2 对于前 k-1 根管子,每根取当前指针所在的两个相邻格子,输出 "2 x1 y1 x2 y2"
 *   然后指针前进两步
 * 3 第 k 根管子收集剩余所有格子,输出其余格子的总数和顺序
 * 时间复杂度 O(n·m)
 * 空间复杂度 O(1)
 */
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    int x = 1, y = 1;
    bool r = true;
    for (int i = 1; i <= k - 1; ++i) {
        cout << "2 " << x << " " << y << " ";
        if (r) ++y;
        else --y;
        if (y == 0 || y == m + 1) {
            ++x;
            y = r ? m : 1;
            r = !r;
        }
        cout << x << " " << y << "\n";
        if (r) ++y;
        else --y;
        if (y == 0 || y == m + 1) {
            ++x;
            y = r ? m : 1;
            r = !r;
        }
    }
    cout << (n * m - (k - 1) * 2) << " ";
    while (x != n + 1) {
        cout << x << " " << y << " ";
        if (r) ++y;
        else --y;
        if (y == 0 || y == m + 1) {
            ++x;
            y = r ? m : 1;
            r = !r;
        }
    }
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

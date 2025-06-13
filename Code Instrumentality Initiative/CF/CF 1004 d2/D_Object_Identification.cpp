//
// Created by 幻 on 2025/6/11.
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

constexpr bool more = true;

// Codeforces Round 1004 (Div. 2)
/* 2067D
 * link: https://codeforces.com/problemset/problem/2067/D
 * 标签: graphs greedy implementation interactive
 * 思路:
 *   1. 读入 x 数组，检查是否为 [1..n] 全排列
 *   2. 若缺失值 lost > 0：
 *      - 取 k ≠ lost（可选 n 或 1），查询 (lost, k) 和 (k, lost)
 *      - 若任一返回 0，则是 Object A，否则 Object B
 *   3. 若是全排列：
 *      - 找 x 中最小值所在下标 mi，最大值所在下标 mx
 *      - 查询 (mi, mx) 得 res1，(mx, mi) 得 res2
 *      - 若 res1 == res2 且 res1 ≥ n-1 则 Object B，否则 Object A
 * 时间复杂度: O(n)  (构建 vis 数组 + 常数次查询)
 * 空间复杂度: O(n)  (vis 数组)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> xs(n);
    vector<bool> vis(n + 1);
    for (auto &x: xs) {
        cin >> x;
        vis[x] = true;
    }
    int lost = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            lost = i;
            break;
        }
    }
    int res1, res2;
    if (lost == 0) {
        auto mi = std::ranges::min_element(xs) - xs.begin() + 1;
        auto mx = std::ranges::max_element(xs) - xs.begin() + 1;
        cout << "? " << mi << " " << mx << endl;
        cin >> res1;
        cout << "? " << mx << " " << mi << endl;
        cin >> res2;
        if (res1 == res2 && res1 >= n - 1) cout << "! B" << endl;
        else cout << "! A" << endl;
    } else {
        int k = n;
        if (lost == k) k = 1;
        cout << "? " << lost << " " << k << endl;
        cin >> res1;
        cout << "? " << k << " " << lost << endl;
        cin >> res2;
        if (res1 == 0 || res2 == 0) cout << "! A" << endl;
        else cout << "! B" << endl;
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

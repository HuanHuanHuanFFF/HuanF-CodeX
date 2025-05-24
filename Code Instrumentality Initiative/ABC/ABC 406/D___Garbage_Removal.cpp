//
// Created by 幻 on 2025/5/23.
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

// Panasonic Programming Contest 2025（AtCoder Beginner Contest 406） 
/* D. Garbage Removal
 * link: https://atcoder.jp/contests/abc406/tasks/abc406_d
 * 思路:
 *   - 使用两个集合数组 xy 和 yx 分别记录行/列上的垃圾位置
 *   - 读入 N 个垃圾坐标时, 同时执行 xy[x].insert(y) 和 yx[y].insert(x)
 *   - 对于类型1 查询 (行 a):
 *       1) 输出 xy[a].size()  // 行 a 上垃圾数量
 *       2) 遍历 xy[a] 中的每个 y, 在 yx[y] 中擦除 a
 *       3) 清空 xy[a]
 *   - 对于类型2 查询 (列 a):
 *       1) 输出 yx[a].size()  // 列 a 上垃圾数量
 *       2) 遍历 yx[a] 中的每个 x, 在 xy[x] 中擦除 a
 *       3) 清空 yx[a]
 *   - 每次集合的插入/删除/查询均摊 O(log N), 总体时间 O((N+Q) log N)
 */
void HuanF() {
    int h, w, n;
    cin >> h >> w >> n;
    std::set<int> xy[h + 1], yx[w + 1];
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        xy[x].insert(y);
        yx[y].insert(x);
    }
    int q;
    cin >> q;
    for (int i = 0, opt, a; i < q; ++i) {
        cin >> opt >> a;
        if (opt == 1) {
            cout << xy[a].size() << "\n";
            for (auto &y: xy[a]) {
                yx[y].erase(a);
            }
            xy[a].clear();
        } else {
            cout << yx[a].size() << "\n";
            for (auto &x: yx[a]) {
                xy[x].erase(a);
            }
            yx[a].clear();
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

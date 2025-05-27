//
// Created by 幻 on 2025/5/26.
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
constexpr ll INF = (ll) 1e18 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Codeforces Round  1027 (Div. 3) 
/* D. Come a Little Closer
 * link: https://codeforces.com/contest/2114/problem/D
 * 标签: 多重集合, 枚举, 极值, 贪心, 矩形面积
 * 思路:
 *  1. 读入 n 和所有怪物的位置 (x_i, y_i)，分别插入 multiset xs, ys 中
 *  2. 特判 n == 1 时，只有一个怪物，选 1×1 矩形，输出 1
 *  3. 遍历所有点，若其 x 或 y 在 {min, max} 之中，则视为边界点，收集到 del 列表
 *  4. 枚举 del 中每个边界点 (x, y)：
 *     a. 从 xs, ys 中删除该点的 x, y
 *     b. 计算剩余点的最小外接矩形宽 w = max(xs) - min(xs) + 1
 *                               高 h = max(ys) - min(ys) + 1
 *     c. 面积 s = 1LL * w * h
 *     d. 如果 s < n，则说明 (n-1) 个点刚好填满，需要扩展一行或一列：
 *           s += min(w, h);
 *     e. ans = min(ans, s)
 *     f. 将该点的 x, y 重新插回 xs, ys
 *  5. 输出最小 ans
 *
 * 时间复杂度: 每个点插删 multiset 为 O(log n)，共枚举边界点 ≤ n，整体 O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<PII> pxy(n), del;
    del.reserve(n);
    std::multiset<int> xs, ys;
    for (auto &[x,y]: pxy) {
        cin >> x >> y;
        xs.insert(x);
        ys.insert(y);
    }
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    for (auto &[x,y]: pxy) {
        if (x == *xs.begin() || x == *xs.rbegin() || y == *ys.rbegin() || y == *ys.begin()) {
            del.emplace_back(x, y);
        }
    }
    ll ans = INF;
    for (auto &[x,y]: del) {
        auto xi = xs.find(x);
        auto yi = ys.find(y);
        xs.erase(xi);
        ys.erase(yi);
        ll s = 1ll * (abs(*xs.rbegin() - *xs.begin()) + 1) * (abs(*ys.rbegin() - *ys.begin()) + 1);
        if (s < n) s += std::min(abs(*xs.rbegin() - *xs.begin()) + 1, abs(*ys.rbegin() - *ys.begin()) + 1);
        ans = std::min(ans, s);
        xs.insert(x);
        ys.insert(y);
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

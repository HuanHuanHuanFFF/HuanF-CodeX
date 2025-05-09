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

/* L. Puzzle: Sashigane
 * link: https://codeforces.com/gym/104417/problem/L
 * 思路:
 * 我们以黑格子 (x,y) 为中心，依次向外一层层 "包" 成 (i+1)x(i+1) 的正方形，
 * 每一层用一个 L 形覆盖该层的所有白格：
 *   - 用变量 a,b,c,d 记录向上、向左、向下、向右扩展的边界起点
 *   - 对每个层数 l 从 1 到 n-1：
 *       若 a>1 且 b>1，则在 (a-1,b-1) 位置画向上向左的 L (h= l, w= l)
 *       否则若 c<n 且 b>1，则在 (c+1,b-1) 画向下向左的 L (h=-l, w= l)
 *       否则若 a>1 且 d<n，则在 (a-1,d+1) 画向上向右的 L (h= l, w=-l)
 *       否则，在 (c+1,d+1) 画向下向右的 L (h=-l, w=-l)
 *   更新对应的 a,b,c,d 边界起点
 * 这样恰好输出 n-1 个 L 形，覆盖除中心黑格以外的所有白格
 * 时间复杂度 O(n)，空间 O(1)
 */
void HuanF() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << "Yes\n" << n - 1 << "\n";
    int a = x, b = y, c = x, d = y;
    for (int l = 1; l <= n - 1; ++l) {
        if (a > 1 && b > 1)
            cout << --a << " " << --b << " " << l << " " << l << "\n";
        else if (a < n && b > 1)
            cout << ++c << " " << --b << " " << -l << " " << l << "\n";
        else if (a > 1 && b < n)
            cout << --a << " " << ++d << " " << l << " " << -l << "\n";
        else
            cout << ++c << " " << ++d << " " << -l << " " << -l << "\n";
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

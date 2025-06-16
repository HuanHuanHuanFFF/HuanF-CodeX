//
// Created by 幻 on 2025/6/16.
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
using P = pair<double, double>;
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

constexpr bool more = false;
#define x first
#define y second

// P2742 [USACO5.1] 圈奶牛Fencing the Cows /【模板】二维凸包
/* P2742 - Fencing the Cows
 * link: https://www.luogu.com.cn/problem/P2742
 * 标签: 凸包 Andrew单调链 计算几何 周长
 * 思路: 对所有点按(x↑,y↑)排序 O(n log n)
 *       Andrew单调链线性扫 两趟维护左转 叉积<=0弹栈 得完整凸包
 *       枚举相邻点欧氏距离累加 得围栏最短长度
 *       时间复杂度 O(n log n)
 *       空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<P> pts(n);
    for (auto &[x,y]: pts) cin >> x >> y;
    auto convex_hull = [](vector<P> &pts) {
        std::ranges::sort(pts);
        pts.erase(std::ranges::unique(pts).begin(), pts.end());
        int n = pts.size();
        if (n <= 1) return pts;

        auto cross = [](P a, P b, P c) {
            return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        };

        vector<P> up, low;
        for (auto &p: pts) {
            while (low.size() >= 2 && cross(low[low.size() - 2], low.back(), p) <= 0)
                low.pop_back();
            low.push_back(p);
        }
        for (int i = n - 1; i >= 0; --i) {
            auto &p = pts[i];
            while (up.size() >= 2 && cross(up[up.size() - 2], up.back(), p) <= 0)
                up.pop_back();
            up.push_back(p);
        }
        low.pop_back(), up.pop_back();
        low.insert(low.end(), up.begin(), up.end());
        return low;
    };
    vector<P> hull = convex_hull(pts);
    hull.push_back(hull.front());
    double ans = 0;
    for (int i = 0; i < hull.size() - 1; ++i) {
        ans += sqrt(
            (hull[i + 1].x - hull[i].x) * (hull[i + 1].x - hull[i].x)
            + (hull[i + 1].y - hull[i].y) * (hull[i + 1].y - hull[i].y));
    }
    printf("%.2lf\n", ans);
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

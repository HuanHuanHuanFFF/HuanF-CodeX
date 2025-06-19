//
// Created by 幻 on 2025/6/19.
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
using P = pair<ll, ll>;
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

// P1452 【模板】旋转卡壳 | [USACO03FALL] Beauty Contest G
/* P1452 Beauty Contest
 * link: https://www.luogu.com.cn/problem/P1452
 * 标签: 凸包 单调链 旋转卡壳 直径
 * 思路:
 * 1. Andrew 单调链
 *    sort by (x,y) O(n log n)
 *    扫下链与上链 each O(n) 保证 left turn 用 cross<=0 弹栈
 *    得逆时针凸包 hull
 * 2. 旋转卡壳求直径
 *    双指针 a b 初始 0 1
 *    比较三角形面积 abs((Pi+1-Pi)×(Pj-Pi)) 单峰
 *    while 面积增大 b++ 保证 b 只前移
 *    计算 dis 更新答案
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
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

    int n;
    cin >> n;
    vector<P> ps(n);
    for (auto &[x,y]: ps) cin >> x >> y;
    vector<P> hull = convex_hull(ps);
    ll ans = 0;
    n = hull.size();
    int a = 0, b = 1;
    while (a < n) {
        auto [x1,y1] = hull[a];
        auto gets = [&](int i, int j) {
            // 边向量 e = H[i+1] - H[i]
            long long ex = hull[(i + 1) % n].x - hull[i].x;
            long long ey = hull[(i + 1) % n].y - hull[i].y;
            // 另一向量 v = H[j] - H[i]
            long long vx = hull[j].x - hull[i].x;
            long long vy = hull[j].y - hull[i].y;
            return std::abs(ex * vy - ey * vx); // |e × v|
        };
        while (gets(a, (b + 1) % n) > gets(a, b)) b = (b + 1) % n;
        auto [x2,y2] = hull[b];
        ans = std::max(ans, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        ++a;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

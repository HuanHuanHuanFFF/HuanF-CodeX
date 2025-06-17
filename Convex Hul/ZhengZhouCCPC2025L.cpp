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

/* Astral Decay
 * link: https://vjudge.net/problem/???   // ← 替换为实际题目链接
 * 标签: 凸包 旋转卡壳 双指针 点积最小化
 * 思路:
 *   1. 凸包: 线性目标 (B−A)·(C−A) 在凸集上极值必落在极点, 故只需枚举凸包顶点
 *   2. 枚举 A∈所有点; 枚举 B∈凸包; C 在凸包上对 (B−A) 的投影单峰, 用双指针
 *      (旋转卡壳) 维护最小 (B−A)·(C−A), 指针 cp 仅向前移动, 总步数 O(h)
 *   3. 对每组 (A,B) 更新答案 ans = min(ans, (B−A)·(C−A))
 *   时间复杂度: O(n·h) (n≤6666, h≤n)空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<P> ps(n);
    for (auto &[x,y]: ps) cin >> x >> y;

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

    auto hull = convex_hull(ps);
    auto dot = [](P a, P b) {
        return a.x * b.x + a.y * b.y;
    };
    int h = hull.size();
    ll ans = 0;
    for (auto &a: ps) {
        int cp = 1;
        for (int bp = 0; bp < h; ++bp) {
            auto &b = hull[bp];
            if (b.x == a.x && b.y == a.y) continue;
            P ab = {b.x - a.x, b.y - a.y};
            if (bp == 0) cp = 1;
            if (cp == bp) cp = (cp + 1) % h;
            auto better = [&](int i, int j) {
                return dot(ab, {hull[i].x - a.x, hull[i].y - a.y})
                       < dot(ab, {hull[j].x - a.x, hull[j].y - a.y});
            };
            while (better((cp + 1) % h, cp)) cp = (cp + 1) % h;
            P ac = {hull[cp].x - a.x, hull[cp].y - a.y};
            ll now = dot(ac, ab);
            ans = std::min(ans, now);
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more)
        cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

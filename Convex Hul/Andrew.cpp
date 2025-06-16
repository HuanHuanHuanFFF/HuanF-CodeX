//
// Created by 幻 on 2025/6/16.
//
#include <bits/stdc++.h>

using namespace std;

using P = pair<double, double>;
#define x first
#define y second

/* ===== 凸包：逆时针返回 =====
 * 复杂度 O(n log n)（排序）+ O(n)（扫描）
 */
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

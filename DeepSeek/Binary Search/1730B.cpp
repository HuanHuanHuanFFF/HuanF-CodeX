#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 1730B – Meeting on the Line
// Link: https://codeforces.com/problemset/problem/1730/B
//
// 题意（简化）：有 n 个人，第 i 个人初始位于 x[i]。
// 第 i 个人要在 t[i] 时间后才开始出发，出发后以速度 1 沿直线移动。
// 我们要选择一个点 P 和一个时间 T，使得对所有 i，都有
//    t[i] + |x[i] − P| ≤ T
// 即每个人都能在时间 T 到达 P。求最小的 T，并输出在该最小 T 下的最左可行 P。
//
// 思路（What–Why–How）：
//
// What（我们要找什么？）
//   最小化 T，且在该 T 下找最左（最小坐标）可行的 P。
//
// Why（为什么可以二分 T？）
//   • 对 T 增大：每个人的可达区间 [x[i]−(T−t[i]), x[i]+(T−t[i])] 只会扩大。
//   • 若在某 T0 可行（所有区间交集非空），那么对所有 T ≥ T0 也必可行。
//   这满足二分单调性，可二分搜索最小 T。
//
// How（怎么判定可行？check(T)）
//   1. 初始化交集区间 [L, R] = [−∞, +∞]。
//   2. 对每个 i：
//      - 如果 T < t[i]，这个人还没出发就超时，直接返回 false。
//      - 否则可达区间为
//          nowL = x[i] − (T − t[i])
//          nowR = x[i] + (T − t[i])
//      - 交集更新：
//          L = max(L, nowL)
//          R = min(R, nowR)
//      - 若交集变空 (L > R)，返回 false。
//   3. 遍历结束后交集非空，任取 L…R 都能让所有人同时到达。
//      为了输出最左 P，我们记录 ans = L 并返回 true。
//   printf("%.7f\n", ans);
//
// 复杂度：O(n · log(范围/eps))，n ≤ 10^5，精度 1e-7 可在时限内。
void HuanF() {
    int n;
    double ans = 0;
    cin >> n;
    vector<int> x(n), t(n);
    for (auto &u: x) cin >> u;
    for (auto &u: t) cin >> u;

    auto check = [&](double mid) {
        double l, r;
        double d = mid - t[0];
        if (d < 0) return false; //还没出发就超时
        l = x[0] - (mid - t[0]), r = x[0] + (mid - t[0]);
        for (int i = 1; i < n; ++i) {
            d = mid - t[i];
            if (d < 0) return false; //还没出发就超时
            double nowl = x[i] - d, nowr = x[i] + d;
            if (nowr < l || nowl > r) return false; // 区间交集为空
            l = std::max(l, nowl);
            r = std::min(r, nowr);
        }
        if (l <= r) ans = l;
        return l <= r;
    };

    double l = -1, r = INF;
    while (l + 0.0000001 < r) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.7lf\n", ans);
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/8/7.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = false;

// AtCoder Beginner Contest 412
/* ABC412-D Make 2-Regular Graph
 * link: https://atcoder.jp/contests/abc412/tasks/abc412_d
 * 标签: 枚举排列, 构造, 图论, 2-正则, 对称差
 * 思路:
 * 本质 目标图H需为2-正则 即每点度=2 ⇒ H是若干不相交简单环的并 且每环长度≥3
 *  推论1 2-正则⇔若干环 证: 任一连通分量内度和=2|V|=2|E| ⇒ |E|=|V| 每点度=2的有限简单图其分量为单一简单环
 *  推论2 n≤8 ⇒ 3k≤n ⇒ k≤2 仅需考虑1环或2环
 * 枚举 用排列p表示环上顺序
 *  单环: 连(p[i],p[(i+1)%n])
 *  双环: 在同一p上取切分点d 使两段长度≥3 即2≤d≤n-4 各自成环
 * 计数 用上三角布尔矩阵存边(u<v) 原图g与候选f的对称差Σ(f[i][j]≠g[i][j])即最少操作数 每条边独立增删一次
 * 实现 枚举所有排列 先构造单环取最小值 再枚举d构造双环取更小值
 * 时间复杂度 O(n!·n^2) 空间复杂度 O(n^2)
 */

void HuanF() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<bool>(n));
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        --x, --y;
        if (x > y) std::swap(x, y);
        g[x][y] = true;
    }
    vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);

    auto diff = [&](vector<vector<bool> > &f) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cnt += f[i][j] != g[i][j];
            }
        }
        return cnt;
    };

    int ans = INF;
    do {
        vector f(n, vector<bool>(n));
        auto x = p.front(), y = p.back();
        if (x > y) std::swap(x, y);
        f[x][y] = true;
        for (int i = 0; i < n - 1; ++i) {
            x = p[i], y = p[i + 1];
            if (x > y) std::swap(x, y);
            f[x][y] = true;
        }
        ans = std::min(ans, diff(f));
        for (int d = 2; d < n - 3; ++d) {
            for (auto &v: f) v.assign(n, false);
            x = p.front(), y = p[d];
            if (x > y) std::swap(x, y);
            f[x][y] = true;
            for (int i = 0; i <= d - 1; ++i) {
                x = p[i], y = p[i + 1];
                if (x > y) std::swap(x, y);
                f[x][y] = true;
            }
            x = p[d + 1], y = p.back();
            if (x > y) std::swap(x, y);
            f[x][y] = true;
            for (int i = d + 1; i < n - 1; ++i) {
                x = p[i], y = p[i + 1];
                if (x > y) std::swap(x, y);
                f[x][y] = true;
            }
            ans = std::min(ans, diff(f));
        }
    } while (std::ranges::next_permutation(p).found);
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

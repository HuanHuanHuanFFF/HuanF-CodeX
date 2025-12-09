//
// Created by 幻 on 2025/12/9.
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

constexpr bool more = true;

/* 2153C-Symmetrical Polygons
 * link: https://codeforces.com/contest/2153/problem/C
 * 标签: 贪心, 排序, 构造, 几何判定
 * 思路: 把所有长度相同的木棍按出现次数计数. 由于对称凸多边形关于一条轴对称
 *      除了最多两条边可以单独在对称轴上之外 其他边必成对且长度相等
 *      因此对每种长度 x 先取 floor(cnt[x]/2) 对作为成对边 base, 其总长度和记为 base
 *      其实际周长贡献是 2*base
 *      之后只需要枚举对称轴与边的三种情形
 *      1) 轴不过任何边 仅使用成对边 如果存在至少两对边 则可构成多边形
 *         这时周长固定为 2*base 判定条件为存在某个长度 x 使 base > x
 *         等价于除去该边后还有其他边
 *      2) 轴经过一条边 长度为 v 此时其余边总长必须大于 v 才能闭合
 *         即 2*base > v 对所有奇数出现的长度 v 枚举 若满足条件更新答案 2*base+v
 *      3) 轴经过两条边 长度 a<=b 其余边加较短边的总长必须大于较长边
 *         即 2*base + a > b 只需在已排序的 odd 数组中枚举相邻两条 a=odd[i-1],b=odd[i]
 *         满足条件则更新答案 2*base+a+b
 *      三种情况分别取最大值即可 若 base 为 0 说明不存在任何成对边 无法构成多边形
 *      计数用 map 保证自动按长度排序 odd 与 even 向量天然有序
 * 时间复杂度: O(n log n) 主要为排序和 map 插入
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    std::map<int, int> cnt;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    vector<int> odd, even;
    odd.reserve(n);
    even.reserve(n);
    ll base = 0;
    for (auto &[x,y]: cnt) {
        base += x * 1ll * (y >> 1);
        if (y & 1) odd.emplace_back(x);
        else if (y >= 2) even.emplace_back(x);
    }
    ll ans = 0;
    for (auto &x: odd)
        if (base * 2 > x) ans = std::max(ans, base * 2 + x);

    for (int i = 1; i < odd.size(); ++i) {
        int a = odd[i - 1], b = odd[i];
        if (base * 2 + a > b) ans = std::max(ans, base * 2 + a + b);
    }

    for (auto &x: even)
        if (base > x) ans = std::max(ans, base * 2);

    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

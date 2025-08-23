//
// Created by 幻 on 2025/8/23.
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
constexpr ll INF = 1e17 + 17;
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

/* P1883-【模板】三分 | 函数
 * link: https://www.luogu.com.cn/problem/P1883
 * 标签: 三分, 单谷函数, 凸性, 上包络, 夹逼
 * 思路:
 * 1 定义 F(x)=max_i{a_i x^2 + b_i x + c_i}
 * 2 性质: 每个 f_i(x) 为凸函数(a_i>=0), max 若干凸函数仍为凸函数, 故 F 在区间内为单谷
 *   证明: 任意 λ∈[0,1], 有 f_i(λx+(1-λ)y) ≤ λf_i(x)+(1-λ)f_i(y)
 *        取最大得 F(λx+(1-λ)y)=max_i f_i(·) ≤ max_i[λf_i(x)+(1-λ)f_i(y)]
 *        ≤ λ max_i f_i(x) + (1-λ) max_i f_i(y) = λF(x)+(1-λ)F(y)
 *        故 F 凸, 极小值唯一或为区间, 可用三分
 * 3 算法: 在 [0,1000] 做最小值三分
 *    取 m1=l+(r-l)/3, m2=r-(r-l)/3
 *    若 F(m1)<F(m2) 则最小值在 [l,m2], 令 r=m2; 否则在 [m1,r], 令 l=m1
 *    终止阈值取 1e-9, 输出 F((l+r)/2) 并保留 4 位小数
 * 4 评估: 每次评估 F 需 O(n), 迭代约 100 次, 总复杂度可过 n<=1e4
 * 时间复杂度: O(n * iter) 约 O(1e6) 级
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<std::array<int, 3> > as(n);
    for (auto &[a,b,c]: as) cin >> a >> b >> c;
    auto f = [&](double x) {
        double ans = -INF;
        for (auto &[a,b,c]: as) {
            double y = x * x * a + x * b + c;
            ans = std::max(ans, y);
        }
        return ans;
    };
    double l = 0, r = 1000;
    while (l + 1e-9 < r) {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    cout << std::format("{:.4f}\n", f((l + r) / 2));
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

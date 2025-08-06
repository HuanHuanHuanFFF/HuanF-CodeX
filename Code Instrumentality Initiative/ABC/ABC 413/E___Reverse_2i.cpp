//
// Created by 幻 on 2025/8/6.
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

// Denso Create Programming Contest 2025（AtCoder Beginner Contest 413） 
/* ABC413-E Reverse 2^i
 * link: https://atcoder.jp/contests/abc413/tasks/abc413_e
 * 标签: 分治 递归 贪心
 * 思路: 把区间 [l,r] 视为两半 [l,mid] 与 [mid+1,r] 递归处理.
 *       对返回的子序列 le, ri, 若 le 的首元素 > ri 的首元素, 交换 le, ri,
 *       保证当前区间字典序最小. 之后把 ri 追加到 le 得到合并结果.
 *       递归到叶子返回单元素向量即可.
 * 时间复杂度: O(N log N)  (元素在每层被复制一次, N=2^n)
 * 空间复杂度: O(N log N)  (递归栈 + 多层向量拷贝)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> p(1 << n | 1);
    for (auto &x: p | std::views::drop(1)) cin >> x;
    auto dfs = [](auto &&self, vector<int> &p, int l, int r)-> vector<int> {
        if (l == r) return {p[l]};
        int mid = l + r >> 1;
        vector<int> le = self(self, p, l, mid);
        vector<int> ri = self(self, p, mid + 1, r);
        if (le[0] > ri[0]) std::swap(le, ri);
        le.insert(le.end(), ri.begin(), ri.end());
        return le;
    };
    p = dfs(dfs, p, 1, 1 << n);
    for (auto &x: p) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

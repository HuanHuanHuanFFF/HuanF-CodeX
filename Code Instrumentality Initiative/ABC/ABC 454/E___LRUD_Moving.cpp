//
// Created by 幻 on 2026/4/24.
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

/* ABC454-E - LRUD Moving
 * link: https://atcoder.jp/contests/abc454/tasks/abc454_e
 * 标签: 构造, 网格图, 哈密顿路径, 棋盘染色
 * 思路:
 * 题目要从 (1,1) 走到 (N,N), 且恰好避开 (A,B), 经过其余所有格子一次
 *
 * 先用棋盘染色判断是否有解:
 * 每走一步颜色都会改变
 * 若 N 为奇数, (1,1) 和 (N,N) 同色, 中间需要经过的黑白数量无法匹配, 无解
 * 若 N 为偶数, 只有挖掉白格时黑白数量才匹配, 也就是 A+B 为奇数
 * 所以有解条件是 N 为偶数且 A+B 为奇数
 *
 * 构造时不搜索, 而是不断缩小问题:
 * 1. 如果坏格子不在当前最上方两行, 就用蛇形路径吃掉上方两行
 *    路径为 R...(n-1), D, L...(n-1), D
 * 2. 如果坏格子不在当前最左方两列, 就吃掉左方两列
 *    路径为 D, R, U, R
 * 3. 对下方两行和右方两列做同样处理, 但它们属于答案后缀, 先存在 ans2 中
 * 4. 最后问题会缩成 2x2, 此时坏格子只可能在 (1,2) 或 (2,1)
 *    若坏格子在 (1,2), 走 D,R
 *    否则走 R,D
 *
 * ans1 表示前缀路径, ans2 表示从外层剥出来的后缀路径
 * 输出时先输出 ans1, 再反向输出 ans2, 就能接上最终终点 (N,N)
 * 时间复杂度: O(N^2)
 * 空间复杂度: O(N^2)
 */
void HuanF() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n & 1 || !((a + b) & 1)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<char> ans1, ans2;
    int x = 1, y = 2, i;
    for (i = 1; i < a; i += 2) {
        if (a - i < 2) break;
        for (int j = 0; j < n - 1; ++j) ans1.emplace_back('R');
        ans1.emplace_back('D');
        for (int j = 0; j < n - 1; ++j) ans1.emplace_back('L');
        ans1.emplace_back('D');
    }
    x = a - i;
    for (i = 1; i < b; i += 2) {
        if (b - i < 2) break;
        ans1.emplace_back('D');
        ans1.emplace_back('R');
        ans1.emplace_back('U');
        ans1.emplace_back('R');
    }
    y = b - i;
    for (i = n; i > a; i -= 2) {
        if (i - a < 2) break;
        for (int j = 0; j < n - 1; ++j) ans2.emplace_back('R');
        ans2.emplace_back('D');
        for (int j = 0; j < n - 1; ++j) ans2.emplace_back('L');
        ans2.emplace_back('D');
    }
    for (i = n; i > b; i -= 2) {
        if (i - b < 2) break;
        ans2.emplace_back('D');
        ans2.emplace_back('R');
        ans2.emplace_back('U');
        ans2.emplace_back('R');
    }
    if (x == 0 && y == 1) {
        ans1.emplace_back('D');
        ans1.emplace_back('R');
    } else {
        ans1.emplace_back('R');
        ans1.emplace_back('D');
    }
    for (auto &c: ans1) cout << c;
    for (auto &c: ans2 | std::views::reverse) cout << c;
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

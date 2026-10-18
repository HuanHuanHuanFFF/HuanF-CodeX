//
// Created by 幻 on 2026/10/18.
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

/* ABC229-D - Longest X
 * link: https://atcoder.jp/contests/abc229/tasks/abc229_d
 * 标签: 双指针, 滑动窗口
 * 思路: 将一段全部变为 X 的代价是其中 . 的总数, 求代价不超过 k 的最长区间。
 * 右端点逐个扩展, 点数超限就右移左端点, 恢复合法后更新答案。
 * 两个端点均只向右移动, 各最多走 n 步。
 * 时间复杂度: O(n), 空间复杂度: O(1) (不计输入字符串)
 */
void HuanF() {
    string s;
    int k;
    cin >> s >> k;
    int l = 0, r = -1, ans = 0, x = 0, dots = 0, n = s.length();
    for (r = 0; r < n; ++r) {
        if (s[r] == 'X') ++x;
        else ++dots;
        while (dots > k) {
            if (s[l] == '.') --dots;
            else --x;
            ++l;
        }
        ans = std::max(ans, dots + x);
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

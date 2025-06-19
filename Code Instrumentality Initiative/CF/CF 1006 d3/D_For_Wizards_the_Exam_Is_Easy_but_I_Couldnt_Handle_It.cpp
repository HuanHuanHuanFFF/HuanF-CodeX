//
// Created by 幻 on 2025/6/17.
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
using PII = pair<int, int>;
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

constexpr bool more = true;

// Codeforces Round 1006 (Div. 3)
/* 2072-D
 * link: https://codeforces.com/problemset/problem/2072/D
 * 标签: 逆序对最小化、一次左旋、差分计数、暴力枚举
 * 思路:
 *   1. 旋转 [l,r] 等价于把 a_l 删除后插到 r 位置
 *      ➜ 仅影响 (l,i) 对 (l<i≤r)
 *   2. 若 a_l > a_i 则原先有逆序对，旋转可消除 (first-type)
 *      若 a_l < a_i 则旋转会新增逆序对 (second-type)
 *   3. 设 cnt_big = # {i | l<i≤r, a_l>a_i}
 *           cnt_small = # {i | l<i≤r, a_l<a_i}
 *      逆序对变化 Δ = cnt_small − cnt_big
 *      要最小化总逆序对 ➜ 令 (cnt_big − cnt_small) 最大
 *   4. 枚举 l，线性扫 r 更新 cnt_big / cnt_small
 *      记录最大差值的位置即答案
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int best = 0, l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int cnt_big = 0, cnt_small = 0;
        for (int j = i + 1; j < n; ++j) {
            cnt_big += a[i] > a[j];
            cnt_small += a[i] < a[j];
            if (best < cnt_big - cnt_small) {
                best = cnt_big - cnt_small;
                l = i, r = j;
            }
        }
    }
    cout << l + 1 << " " << r + 1 << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

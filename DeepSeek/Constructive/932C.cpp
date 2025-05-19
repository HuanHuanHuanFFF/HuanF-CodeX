//
// Created by 幻 on 2025/5/19.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* 932C-PermutationCycle
 * link: https://codeforces.com/problemset/problem/932/C
 * 思路:
 * 1. 将原题等价为在 N 个元素中划分若干个长度为 A 和 B 的环，使得总和为 N
 * 2. 枚举 x（环中长度为 A 的个数），令 y = (N - A*x) / B，检查是否整除得到非负解
 * 3. 若无解则输出 -1 并返回
 * 4. 否则依次构造 x 个 A 长环和 y 个 B 长环
 *    对于每个环 [l, …, r]，输出 r, l, l+1, …, r-1，实现元素向后“旋转”一位，形成所需周期
 * 5. 整体遍历和输出操作均为 O(N) 时间，额外使用 O(1) 空间
 */
void HuanF() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll x = -1, y = -1;
    for (int i = 0; i <= n; ++i) {
        if (n - a * i < 0) break;
        if ((n - a * i) % b == 0) {
            x = i;
            y = (n - a * i) / b;
            break;
        }
    }
    if (x == -1 && y == -1) {
        cout << -1;
        return;
    }
    int now = 1;
    while (x-- > 0) {
        int l = now, r = now + a - 1;
        cout << r << " ";
        for (int i = l; i < r; ++i) {
            cout << i << " ";
        }
        now = r + 1;
    }
    while (y-- > 0) {
        int l = now, r = now + b - 1;
        cout << r << " ";
        for (int i = l; i < r; ++i) {
            cout << i << " ";
        }
        now = r + 1;
    }
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

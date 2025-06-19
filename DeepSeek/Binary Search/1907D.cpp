//
// Created by 幻 on 2025/6/18.
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

// Codeforces Round 913 (Div. 3)
/* D. 跳跃通过区间
 * link: https://codeforces.com/contest/1907/problem/D
 * 标签: 二分答案, 区间贪心, 可达性判断
 * 思路:
 *   维护每一步可达区间[l,r]，从上一轮区间扩展±k后与当前给定段[l_i,r_i]取交集
 *   若任意一步无交集则不可完成，利用此单调可行性函数对k二分
 * 时间复杂度: O(n·logC)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<PII> box(n);
    for (auto &[x,y]: box) cin >> x >> y;

    auto check = [&](int k) {
        int l = 0, r = 0;
        for (auto &[x,y]: box) {
            l = std::max(l - k, x);
            r = std::min(r + k, y);
            if (l > r) return false;
        }
        return true;
    };

    int l = -1, r = INF;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

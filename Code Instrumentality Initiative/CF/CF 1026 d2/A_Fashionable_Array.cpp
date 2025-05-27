//
// Created by 幻 on 2025/5/24.
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


/* A. Fashionable Array
 * link: https://codeforces.com/contest/2110/problem/A
 * 题意: 给定数组 a, 可删除任意元素, 需使 min(a)+max(a) 为偶数。
 * 思路:
 *  首先排序, 若 a[0]+a[n-1] 已为偶数, 则不需删除, 答案 0.
 *  否则,删除前面odd1个奇数和后面odd2个奇数,或者删除前面even1个偶数和后面even2个偶数
 *  取二者最小值。
 * 时间复杂度: O(n log n) 排序 + O(n) 统计
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::sort(a.begin(), a.end());
    if ((a[0] + a[n - 1]) % 2 == 0) {
        cout << 0 << "\n";
    } else {
        int odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] & 1) {
                break;
            }
            ++even1;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] & 1) {
                break;
            }
            ++even2;
        }
        for (int i = 0; i < n; ++i) {
            if ((a[i] & 1) == 0) {
                break;
            }
            ++odd1;
        }
        for (int i = n - 1; i >= 0; --i) {
            if ((a[i] & 1) == 0) {
                break;
            }
            ++odd2;
        }
        cout << std::min(odd1 + odd2, even1 + even2) << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

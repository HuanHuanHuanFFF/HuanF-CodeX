//
// Created by 幻 on 2025/6/5.
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

// Codeforces Round 1008 (Div. 2) 
/* C. 背信弃义
 * link: https://codeforces.com/contest/2077/problem/C
 * 标签: 排序, 贪心, 构造
 * 思路:
 *  1. 将输入的 2n 个数 b 排序（降序），把最大的数作为 a1；
 *  2. 接下来再取 n 个最大的数，依次作为 a3, a5, …, a2n+1；
 *  3. 剩余的 n−1 个数作为 a2, a4, …, a2n−2；
 *  4. 根据题目给出的等式：
 *       a2n = a1 + (a3−a2) + (a5−a4) + … + (a2n−1−a2n−2) + a2n+1
 *     计算出缺失的 a2n。由于 a1 是所有数中最大的，计算得到的 a2n 一定比 b 中任何数都大，且是唯一的缺失值；
 *  5. 按顺序输出 a1, a2, a3, a4, …, a2n, a2n+1。
 * 时间复杂度: O(n log n) （主要来自排序）
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n << 1), even, odd;
    even.reserve(n);
    odd.reserve(n);
    for (auto &x: a) cin >> x;
    std::ranges::sort(a, std::greater<>());
    ll a2n = a[0];
    odd.emplace_back(a[0]);
    for (int i = 1; i < a.size(); ++i) {
        if (i <= n) {
            a2n += a[i];
            odd.emplace_back(a[i]);
        } else {
            a2n -= a[i];
            even.emplace_back(a[i]);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << odd[i] << " " << even[i] << " ";
    }
    cout << odd[n] << " " << a2n << " " << odd[n - 1] << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

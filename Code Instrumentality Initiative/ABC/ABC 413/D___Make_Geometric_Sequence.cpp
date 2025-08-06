//
// Created by 幻 on 2025/7/5.
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

// Denso Create Programming Contest 2025（AtCoder Beginner Contest 413） 
/* D - Make Geometric Sequence
 * link: https://atcoder.jp/contests/abc413/tasks/abc413_d
 * 标签: map、排序、等比数列
 * 思路:
 *   1 统计各元素出现次数 cnt，若只有一种值或 n<=2，则任意重排都可构成等比数列
 *   2 若正好两种值 x,y，则只有 r=-1 情况可行，此时需 x = -y 且 两值出现次数差 ≤1
 *   3 对于 ≥3 种值，重排时公比 r 的绝对值固定，故按 abs(a) 降序排序后
 *     检查每个中间位置 i，需满足 a[i-1]*a[i+1] == a[i]*a[i]
 *     若有一处不符，则无法构成等比数列
 * 时间复杂度: O(N log N)
 * 空间复杂度: O(N)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    std::map<ll, int> cnt;
    for (auto &x: a) {
        cin >> x;
        ++cnt[x];
    }
    if (cnt.size() == 1) {
        cout << "Yes\n";
        return;
    }
    if (n == 2) {
        cout << "Yes\n";
        return;
    }
    if (cnt.size() == 2 && n > 2) {
        if (cnt.begin()->first == -cnt.rbegin()->first) {
            if (abs(cnt.begin()->second - cnt.rbegin()->second) <= 1) {
                cout << "Yes\n";
            } else cout << "No\n";
        } else cout << "No\n";
        return;
    }
    std::ranges::sort(a, [](int x, int y) { return abs(x) > abs(y); });
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] * a[i + 1] != a[i] * a[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

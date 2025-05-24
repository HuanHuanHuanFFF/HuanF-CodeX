//
// Created by 幻 on 2025/5/12.
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

/* F-集合之和
 * link: https://codeforces.com/gym/103941
 * 思路:
 * 1. 首先我们知道，当n=2或n=4时，是不存在符合条件的数集A的，因为这些情况下A+A无法等于n。
 * 2. 对于奇数n，我们可以选择数集A为{1, 2, ..., (n+1)/2}，这是因为A+A的结果为{2, 3, ..., n+1}，正好满足A+A=n的条件。
 * 3. 对于偶数n，我们可以选择数集A为{0, 2, 3, ..., n/2}，这样A+A的结果为{0, 2, 3, ..., n}，也符合A+A=n的条件。
 * 4. 综上所述，针对n=2和n=4输出-1，其它情况按上述方法构造数集A。
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    if (n == 2 || n == 4) {
        cout << -1;
        return;
    }
    if (n & 1) {
        cout << (n + 1) / 2 << "\n";
        for (int i = 1; i <= (n + 1) / 2; ++i) {
            cout << i << " ";
        }
    } else {
        cout << n / 2 << "\n" << 0 << " ";
        for (int i = 2; i <= n / 2; ++i) {
            cout << i << " ";
        }
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

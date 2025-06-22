//
// Created by 幻 on 2025/6/21.
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

// Codeforces Round 1033 (Div. 2) and CodeNite 2025 
/* Divine Tree
 * link: https://codeforces.com/contest/2120/problem/C
 * 标签: 贪心, 链式构造, 前缀最小值
 * 思路:
 * 直接考虑链的情况更方便构造
 * 1 初始每点贡献1,相当于把1放在根 m-=n
 * 2 考虑前面放什么,插在1的前面,不会影响到前缀最小值
 * 3 贪心的选,从大到小枚举如果m>=i-1(因为已经默认算过1的贡献了) 就选用这个数,同时m减去i-1
 * 4 按贪心的结果构造答案
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    ll n, m;
    cin >> n >> m;
    ll max = n * (n + 1) / 2;
    ll min = n;
    if (m > max || m < min) {
        cout << "-1\n";
        return;
    }
    vector<int> a;
    a.reserve(n);
    vector<bool> used(n + 1);
    m -= n;
    for (int i = n; i > 0; --i) {
        if (m >= i - 1) {
            m -= i - 1;
            used[i] = true;
            if (m == 0) break;
        }
    }
    for (int i = n; i > 0; --i) {
        if (used[i]) a.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) a.push_back(i);
    }
    cout << a[0] << "\n";
    for (int i = 0; i < n - 1; ++i) {
        cout << a[i] << " " << a[i + 1] << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/17.
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

// Codeforces Round 1037 (Div. 3)
/* 2126E-G-C-D, Unlucky!
 * link: https://codeforces.com/contest/2126/problem/E
 * 标签: 数论·GCD·前缀后缀·必要充分性
 * 思路:
 *   1 验证中点相等：要求 p[n]==s[1]，保证前缀后缀共享公共 g
 *   2 前缀可除性：对 i=2…n 检查 gcd(p[i-1],p[i])==p[i]，确保每步不引入新质因数
 *   3 后缀可除性：对 i=n-1…1 检查 gcd(s[i+1],s[i])==s[i]，同理保证后缀链合法
 *   4 单点可行性：对 i=1…n-1 检查 gcd(p[i],s[i+1])==p[n] 且 p[i]≤p[i-1], s[i]≤s[i+1]
 *     — 这两条件亦隐含链单调，且 gcd(p[i],s[i+1])==g 是 a[i] 存在的必要充分
 * 时间复杂度: O(n·log C)  // n 次 gcd 调用，每次对数级
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> p(n + 1), s(n + 1);
    p[0] = INF;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> s[i];
    if (p[n] != s[1]) {
        cout << "NO\n";
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (std::gcd(p[i - 1], p[i]) != p[i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = n - 1; i > 0; --i) {
        if (std::gcd(s[i + 1], s[i]) != s[i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (std::gcd(p[i], s[i + 1]) != p[n] || p[i] > p[i - 1] || s[i] > s[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

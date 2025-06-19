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

// Codeforces Round 1032 (Div. 3) 
/* G. Gangsta
 * link: https://codeforces.com/contest/2121/problem/G
 * 标签: 二进制 前缀和 排序 数学
 * 思路:
 *   利用 f = (L + |z - o|) / 2 将每个子串的贡献拆成“长度”和“前缀差绝对值”两部分
 *   1) 子串长度和 = ∑_{i=0..n-1}(i+1)*(n-i)
 *   2) 令 pre[i]=#0(1…i)-#1(1…i)，排序后 b[0..n]，相邻差 Δ_k=b[k]-b[k-1] 在所有对(i<j)中出现 k*(n+1-k) 次
 *      故前缀差绝对值和 = ∑_{k=1..n} Δ_k * k * (n+1-k)
 *   最终答案 = (子串长度和 + 前缀差绝对值和) / 2
 * 证明:
 *   对排序后的 pre 数组，任取 Δ_k，它正好对应所有 i<k≤j 的对，计数 = k*(n+1-k)
 */
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (s[i] == '0' ? -1 : 1);
    }
    std::ranges::sort(pre);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ans += (pre[i] - pre[i - 1]) * i * (n - i + 1);
    }
    for (ll i = 0; i < n; ++i) {
        ans += (i + 1) * (n - i);
    }
    ans >>= 1;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

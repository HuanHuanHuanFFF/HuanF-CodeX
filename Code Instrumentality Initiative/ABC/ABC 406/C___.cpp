//
// Created by 幻 on 2025/5/23.
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

// Panasonic Programming Contest 2025（AtCoder Beginner Contest 406） 
/* C - Tilde-Shaped Subarrays
 * link: https://atcoder.jp/contests/abc406/tasks/abc406_c
 * 思路:
 *   1. 将原排列 P 转化为符号串 S 长度为 N-1：
 *      S[i] = '<' if P[i] < P[i+1], 否则 '>'.
 *   2. 对 S 做跑长压缩，得到 vector<pair<char,ll>> v，
 *      每个元素表示连续相同符号及其长度。
 *   3. 枚举 v 中每个位置 i（1 ≤ i < v.size()-1），若 v[i].first == '>'：
 *        左侧必是 '<' 段长度 a = v[i-1].second，
 *        右侧必是 '<' 段长度 c = v[i+1].second，
 *        对应子串形状为 <^x >^b <^y（1 ≤ x ≤ a, 1 ≤ y ≤ c），
 *        共有 a * c 种，累加到答案。
 *   4. 总复杂度 O(N)，空间 O(N)。
 * 时间复杂度: O(N)
 * 空间复杂度: O(N)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 跑长压缩：构造符号串并合并相邻相同符号
    vector<pair<char, ll> > v;
    for (int i = 1; i < n; ++i) {
        char c = a[i] < a[i + 1] ? '<' : '>';
        if (v.empty() || v.back().first != c)
            v.emplace_back(c, 1);
        else ++v.back().second;
    }
    // 枚举中间 '>' 段，累加左右 '<' 段长度乘积
    ll ans = 0;
    for (int i = 1; i < v.size() - 1; ++i) {
        if (v[i].first == '>') ans += v[i - 1].second * v[i + 1].second;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

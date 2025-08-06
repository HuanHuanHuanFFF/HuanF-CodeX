//
// Created by 幻 on 2025/7/16.
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

constexpr bool more = false;

// Mirrativ Programming Contest 2025 (AtCoder Beginner Contest 414) 
/* ABC414-C Palindromic in Both Bases
 * link: https://atcoder.jp/contests/abc414/tasks/abc414_c
 * 标签: 构造、回文、进制转换、数位枚举
 * 思路:
 * 枚举十进制回文数（构造方法是枚举一半数字后拼接镜像），总共 O(√N) 个。
 * 对每个回文数判断其在 base-A 下是否也为回文，满足条件则累加。
 * 因为 base-A 判回文只需 O(logₐx)，整体复杂度为 O(√N logₐN)，可以通过。
 *
 * 时间复杂度: O(√N logₐN)
 * 空间复杂度: O(logₐN)
 */
void HuanF() {
    int a;
    ll n, ans = 0;
    cin >> a >> n;

    auto get = [](ll half, bool odd) {
        string s = std::to_string(half);
        for (int i = (int) s.size() - 1 - odd; i >= 0; --i) s += s[i];
        return std::stoll(s);
    };

    auto check = [](ll x, ll base) {
        vector<int> d;
        while (x) d.emplace_back(x % base), x /= base;
        for (int l = 0, r = (int) d.size() - 1; l < r; --r, ++l)
            if (d[l] != d[r]) return false;
        return true;
    };
    ll P10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
    for (int len = 1; ; ++len) {
        int halfLen = (len + 1) / 2;
        ll start = (len == 1 ? 0 : P10[halfLen - 1]);
        ll lim = P10[halfLen];
        for (ll h = start; h < lim; ++h) {
            ll x = get(h, len & 1);
            if (x > n) {
                cout << ans << '\n';
                return;
            }
            if (check(x, a)) ans += x;
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2026/4/25.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = false;

/* ABC455-E
 * link: https://atcoder.jp/contests/abc455/tasks/abc455_e
 * 标签: 前缀和, 差值计数, 容斥, map
 * 思路:
 * 目标是统计 A, B, C 出现次数两两不同的子串
 * 直接统计好子串不好做, 转而统计坏子串, 即至少有一对字符出现次数相同
 *
 * 对于一个子串, A 的数量等于 B 的数量, 等价于这个子串的 A-B 差值为 0
 * 用前缀表示就是:
 * preA[r]-preB[r] == preA[l]-preB[l]
 * 所以只要两个前缀的 a-b 相同, 中间子串就满足 A == B
 * 因此用 map 统计每种前缀差值出现次数, 当前差值之前出现过多少次, 就能形成多少个坏子串
 *
 * sameab 统计 A == B 的子串数量
 * sameac 统计 A == C 的子串数量
 * samebc 统计 B == C 的子串数量
 *
 * 但是 A == B == C 的子串会同时被 sameab, sameac, samebc 统计三次
 * 最终只应该作为坏子串统计一次, 所以在答案里减三次后需要加回两次
 *
 * 判断 A == B == C 可以用两个差值同时相同表示:
 * a-b 相同且 a-c 相同
 * 所以用 map<pair, ll> 统计前缀状态 {a-b, a-c}
 *
 * 最终答案为:
 * 总子串数 - sameab - sameac - samebc + 2 * sameabc
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */
void HuanF() {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = n * (n + 1) / 2, a = 0, b = 0, c = 0,
            sameab = 0, sameac = 0, samebc = 0, sameabc = 0;
    std::map<ll, ll> mab, mac, mbc;
    std::map<PII, ll> mabc;
    mabc[{0, 0}] = mab[0] = mac[0] = mbc[0] = 1;
    for (auto &ch: s) {
        if (ch == 'A') ++a;
        if (ch == 'B') ++b;
        if (ch == 'C') ++c;
        ll ab = a - b;
        ll ac = a - c;
        ll bc = b - c;
        sameab += mab[ab];
        samebc += mbc[bc];
        sameac += mac[ac];
        sameabc += mabc[{ab, ac}];

        ++mab[ab];
        ++mac[ac];
        ++mbc[bc];
        ++mabc[{ab, ac}];
    }
    ans = ans - sameab - sameac - samebc + 2 * sameabc;
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

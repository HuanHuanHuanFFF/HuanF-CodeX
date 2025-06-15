#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e8 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 371C – Hamburgers
// Link: https://codeforces.com/problemset/problem/371/C
// 思路：
// 1. 统计配方字符串 p 中每个汉堡所需的 B、S、C 数量：need_b、need_s、need_c
// 2. 定义 check(x)：尝试做 x 个汉堡，计算额外购买的原料费用
//    cost = max(need_b*x - has_b, 0)*pb
//         + max(need_s*x - has_s, 0)*ps
//         + max(need_c*x - has_c, 0)*pc
//    如果 cost ≤ has_p 则可行
// 3. 对 x 做二分（l=-1, r=1e13+17），用 check(mid) 缩小范围，最终 l 就是最大可做数量
void HuanF() {
    string p;
    cin >> p;
    ll has_b, has_s, has_c, pb, ps, pc, has_p;
    cin >> has_b >> has_s >> has_c >> pb >> ps >> pc >> has_p;
    ll need_b = 0, need_c = 0, need_s = 0;
    for (char i: p) {
        if (i == 'S') ++need_s;
        else if (i == 'B') ++need_b;
        else ++need_c;
    }

    auto check = [&](ll x) {
        ll need_p = 0;
        need_p += std::max(need_b * x - has_b, 0ll) * pb;
        need_p += std::max(need_s * x - has_s, 0ll) * ps;
        need_p += std::max(need_c * x - has_c, 0ll) * pc;
        return need_p <= has_p;
    };

    ll l = -1, r = 1e13 + 17;
    while (l + 1 < r) {
        ll mid = l + (r - l >> 1);
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

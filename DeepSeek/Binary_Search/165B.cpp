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

// Codeforces 165B – Burning Midnight Oil
// Link: https://codeforces.com/problemset/problem/165/B
// 思路：
// 1. 二分搜索初始速度 v，区间 [1, n]。
// 2. 判定函数 check(v)：
//    累加 sum = v + v/k + v/k^2 + …，直到 cur==0 或 sum>=n。
//    如果 sum >= n 则可行。
// 3. 最终 lo=1, hi=n，通过二分逼近最小可行 v，并输出 hi。
void HuanF() {
    int n, k;
    cin >> n >> k;
    ll l = 0, r = 1e15 + 17;

    auto check = [&](ll x) {
        ll sum = x, kp = k;
        while (x / kp != 0) {
            sum += x / kp;
            kp *= k;
        }
        return sum >= n;
    };

    while (l + 1 < r) {
        ll mid = l + (r - l >> 1);
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
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

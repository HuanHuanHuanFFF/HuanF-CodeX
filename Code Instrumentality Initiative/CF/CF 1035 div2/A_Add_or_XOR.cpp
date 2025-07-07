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

// Codeforces Round 1035 (Div. 2) 
// A. Add or XOR
// https://codeforces.com/contest/2119/problem/A
// 异或1奇数时-1,偶数时+1
// 所以a>b时,如果a^1!=b则无解
// a<b时,贪心选最小的模拟即可
void HuanF() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b) {
        if ((a ^ 1) == b) cout << y << "\n";
        else cout << -1 << "\n";
    } else {
        if (a == b) cout << 0 << "\n";
        else if (a < b) {
            ll ans = 0;
            while (a != b) {
                if (a & 1) ans += x;
                else ans += std::min(x, y);
                ++a;
            }
            cout << ans << "\n";
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

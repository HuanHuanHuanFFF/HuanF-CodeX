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
// C. A Good Problem
// https://codeforces.com/contest/2119/problem/C
// 首先对于奇数,奇数个自x或的结果为x,&也一样,字典序最小全部设为l即可
// 对于偶数,2的时候不可能有解
// 其他情况,考虑n-2个l异或为0,再找2个为比l大的最小的2^x,这样异或的结果都是0,与的结果也是0
void HuanF() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1) {
        cout << l << "\n";
    } else if (n == 2) {
        cout << -1 << "\n";
    } else {
        ll x = 1;
        while (x <= l) {
            x <<= 1;
        }
        if (x > r) cout << -1 << "\n";
        else {
            if (k <= n - 2) cout << l << "\n";
            else cout << x << "\n";
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

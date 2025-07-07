//
// Created by 幻 on 2025/7/6.
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

// EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2) 
// C. Subset Multiplication
// https://codeforces.com/contest/2124/problem/C
// 当无法整除时,变成他们的最大公因数,由于会影响后面,所以从后往前遍历
// 然后记录变小的倍数,最后取最小公因数
void HuanF() {
    ll ans = 1;
    int n;
    cin >> n;
    vector<int> a(n), f;
    for (auto &x: a) cin >> x;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] % a[i - 1] != 0) {
            int g = std::gcd(a[i - 1], a[i]);
            f.emplace_back(a[i - 1] / g);
            a[i - 1] = g;
        }
    }
    for (auto x: f) {
        ans = std::lcm(x, ans);
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

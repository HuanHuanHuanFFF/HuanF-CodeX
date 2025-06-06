//
// Created by 幻 on 2025/6/3.
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

// Educational Codeforces Round 179 (Rated for Div. 2) 
// A. Energy Crystals
// 一秒钟猜出答案
/*void HuanF() {
    int n;
    cin >> n;
    cout << 3 + floor(std::log2(n)) * 2 << "\n";
}*/

// 暴力模拟
void HuanF() {
    int x;
    cin >> x;
    int ans = 0;
    int a1 = 0, a2 = 0, a3 = 0;
    while (std::ranges::min({a1, a2, a3}) < x) {
        int k = std::ranges::min({a1, a2, a3});
        if (a1 == k) {
            a1 = std::min(a2, a3) << 1 | 1;
        } else if (a2 == k) {
            a2 = std::min(a1, a3) << 1 | 1;
        } else a3 = std::min(a2, a1) << 1 | 1;
        ++ans;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

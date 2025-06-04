//
// Created by 幻 on 2025/5/31.
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

// Codeforces Round 1028 (Div. 2)
/* 2116A
 * link: https://codeforces.com/problemset/problem/2116/A
 * 标签: 贪心
 * 要么一直打骑士,要么一直打人
 */
void HuanF() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = std::min(a, c), y = std::min(b, d);
    if (x >= y) {
        cout << "Gellyfish";
    } else {
        cout << "Flower";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

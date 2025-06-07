//
// Created by 幻 on 2025/6/7.
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

// https://www.luogu.com.cn/problem/U569389
// U569389 森林探险
void HuanF() {
    int n, q;
    cin >> n >> q;
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
    }
    for (int i = 0, x, y, z; i < q; ++i) {
        cin >> x >> y >> z;
        cout << x << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

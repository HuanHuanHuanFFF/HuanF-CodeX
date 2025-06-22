//
// Created by 幻 on 2025/6/21.
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

// Codeforces Round 1033 (Div. 2) and CodeNite 2025 
// B. Square Pool
// https://codeforces.com/contest/2120/problem/B
// 1.弹性碰撞后两小球反向,相当于穿过对方继续运动
// 2.只有对角线方向上的才可能进球
void HuanF() {
    int n, s;
    cin >> n >> s;
    vector<int> dx(n), dy(n), x(n), y(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> dx[i] >> dy[i] >> x[i] >> y[i];
        if (x[i] == y[i] && dx[i] == dy[i]) ++ans;
        else if (x[i] == s - y[i] && dx[i] == -dy[i]) ++ans;
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

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
using PII = pair<ll, ll>;
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

// Denso Create Programming Contest 2025（AtCoder Beginner Contest 413） 
// C - Large Queue
// https://atcoder.jp/contests/abc413/tasks/abc413_c
// 模拟
void HuanF() {
    int q;
    cin >> q;
    std::deque<PII> que;
    for (int i = 0, opt, c, x; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            cin >> c >> x;
            que.emplace_back(c, x);
        } else {
            cin >> c;
            ll ans = 0, poped = 0;
            while (poped < c) {
                auto [x,y] = que.front();
                que.pop_front();
                ans += x * y;
                poped += x;
                if (poped > c) {
                    int d = poped - c;
                    que.emplace_front(d, y);
                    ans -= d * y;
                    poped = c;
                }
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

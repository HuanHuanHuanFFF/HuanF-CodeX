//
// Created by 幻 on 2025/6/20.
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

// AtCoder Beginner Contest 410 
// C - Rotatable Array
void HuanF() {
    int dx = 0;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    for (int i = 0, opt, p, x; i < q; ++i) {
        cin >> opt >> p;
        if (opt == 1) {
            --p;
            cin >> x;
            a[(p + dx) % n] = x;
        } else if (opt == 2) {
            --p;
            cout << a[(p + dx) % n] << "\n";
        } else {
            dx = (dx + p) % n;
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

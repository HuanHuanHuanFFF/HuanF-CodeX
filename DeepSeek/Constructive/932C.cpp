//
// Created by 幻 on 2025/5/19.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// C. Permutation Cycle
void HuanF() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll x = -1, y = -1;
    for (int i = 0; i <= n; ++i) {
        if (n - a * i < 0) break;
        if ((n - a * i) % b == 0) {
            x = i;
            y = (n - a * i) / b;
            break;
        }
    }
    if (x == -1 && y == -1) {
        cout << -1;
        return;
    }
    int now = 1;
    while (x-- > 0) {
        int l = now, r = now + a - 1;
        cout << r << " ";
        for (int i = l; i < r; ++i) {
            cout << i << " ";
        }
        now = r + 1;
    }
    while (y-- > 0) {
        int l = now, r = now + b - 1;
        cout << r << " ";
        for (int i = l; i < r; ++i) {
            cout << i << " ";
        }
        now = r + 1;
    }
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

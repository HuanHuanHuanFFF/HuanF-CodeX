//
// Created by 幻 on 2025/5/17.
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

void HuanF() {
    int n, cnt = 3;
    cin >> n;
    if (n <= 2) {
        for (int i = 0; i < n; ++i) {
            cout << 9 - i;
        }
        cout << "\n";
        return;
    }
    cout << 989;
    for (int i = 0; cnt < n; ++cnt, i = (i + 1) % 10) {
        cout << i;
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

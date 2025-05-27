//
// Created by 幻 on 2025/5/28.
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

// Codeforces Round 988 (Div. 3) 
// C. Superultra's Favorite Permutation
void HuanF() {
    int n;
    cin >> n;
    if (2 * n - 1 >= 9) {
        for (int i = 1; i <= n; i += 2) {
            if (i == 5) continue;
            cout << i << " ";
        }
        cout << 5 << " " << 4 << " ";
        for (int i = 2; i <= n; i += 2) {
            if (i == 4) continue;
            cout << i << " ";
        }
        cout << "\n";
    } else cout << "-1\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

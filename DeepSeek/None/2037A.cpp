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
// A. Twice
void HuanF() {
    int n;
    cin >> n;
    std::map<int, int> cnt;
    int ans = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    for (auto &[x,y]: cnt) {
        ans += y >> 1;
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

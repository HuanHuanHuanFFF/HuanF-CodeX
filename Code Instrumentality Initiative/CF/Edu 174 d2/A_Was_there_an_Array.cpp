//
// Created by 幻 on 2025/6/22.
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

// Educational Codeforces Round 174 (Rated for Div. 2) 
// A. Was there an Array?
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n - 2);
    for (auto &x: a) cin >> x;
    for (int i = 1; i < n - 3; ++i) {
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

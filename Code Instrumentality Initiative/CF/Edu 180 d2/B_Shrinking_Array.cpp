//
// Created by 幻 on 2025/6/23.
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

// Educational Codeforces Round 180 (Rated for Div. 2) 
// B. Shrinking Array
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i - 1]) <= 1) {
            cout << "0\n";
            return;
        }
    }
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    int pm = a[0];
    if (a[1] > a[0])
        for (int i = 1; i < n; ++i) {
            if (a[i] <= pm) {
                cout << "1\n";
                return;
            }
            pm = std::max(pm, a[i]);
        }
    else
        for (int i = 1; i < n; ++i) {
            if (a[i] >= pm) {
                cout << "1\n";
                return;
            }
            pm = std::min(pm, a[i]);
        }
    cout << "-1\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

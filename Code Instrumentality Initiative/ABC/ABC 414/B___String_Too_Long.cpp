//
// Created by 幻 on 2025/7/16.
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

// Mirrativ Programming Contest 2025 (AtCoder Beginner Contest 414) 
// B - String Too Long
void HuanF() {
    int n;
    cin >> n;
    vector<char> s;
    for (int i = 0; i < n; ++i) {
        char x;
        ll c;
        cin >> x >> c;
        if (s.size() + c > 100) {
            cout << "Too Long";
            return;
        }
        for (int j = 0; j < c; ++j) {
            s.emplace_back(x);
        }
    }
    for (auto &c: s) cout << c;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

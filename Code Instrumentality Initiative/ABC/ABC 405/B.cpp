//
// Created by 幻 on 2025/5/12.
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

// https://atcoder.jp/contests/abc405/tasks/abc405_b
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    std::map<int, int> cnt;
    for (auto &x: a) {
        cin >> x;
        ++cnt[x];
    }
    for (int i = 1; i <= m; ++i) {
        if (cnt[i] == 0) {
            cout << 0;
            return;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] <= m)
            if (--cnt[a[i]] == 0) {
                cout << n - i;
                return;
            }
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

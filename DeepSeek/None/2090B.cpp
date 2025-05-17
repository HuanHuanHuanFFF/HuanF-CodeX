//
// Created by 幻 on 2025/5/16.
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
    int n, m;
    cin >> n >> m;
    vector<bool> ver(n), her(m);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                ver[i] = true;
                her[j] = true;
            }
        }
    }
    if (std::count(ver.begin(), ver.end(), true) == n && std::count(her.begin(), her.end(), true)) {
        cout << "yes\n";
    } else cout << "no\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

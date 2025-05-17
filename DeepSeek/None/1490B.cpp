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
    vector<int> cnt(3, 0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
        ++cnt[x % 3];
    }
    ll ans = 0;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < 3; ++i) {
            if (cnt[i] > n / 3) {
                ans += cnt[i] - n / 3;
                cnt[(i + 1) % 3] += cnt[i] - n / 3;
                cnt[i] = n / 3;
            }
        }
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

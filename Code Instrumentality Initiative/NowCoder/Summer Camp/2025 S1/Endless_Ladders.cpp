//
// Created by 幻 on 2025/7/15.
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

//  
// Endless Ladders
void HuanF() {
    ll a, b;
    cin >> a >> b;
    // vector<int> h;
    // for (int i = 1; i <= 1000; ++i) {
    //     h.emplace_back(i * i);
    // }
    // vector<int> lad;
    // for (int i = 0; i < h.size(); ++i) {
    //     for (int j = i + 1; j < h.size(); ++j) {
    //         lad.emplace_back(h[j] - h[i]);
    //     }
    // }
    // std::ranges::sort(lad);
    // lad.erase(std::unique(lad.begin(), lad.end()), lad.end());
    // for (int i = 0; i < 5000; ++i) {
    //     cout << lad[i] << " ";
    // }
    // cout << "\n";
    ll d = std::abs(b * b - a * a);
    if (d == 3) cout << 1;
    else if (d == 5) cout << 2;
    else {
        ll x = d % 4;
        if (x == 3) x = -1;
        else if (x == 1) x = 1;
        d = (d + 2) / 4;
        cout << (d - 1) * 3 + x + 1;
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/20.
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

// AtCoder Beginner Contest 410
// B - Reverse Proxy
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 0, x; i < q; ++i) {
        cin >> x;
        if (x > 0) {
            cout << x << " ";
            ++a[x];
        } else {
            int min = *std::min_element(a.begin() + 1, a.end());
            for (int j = 1; j <= n; ++j) {
                if (min == a[j]) {
                    cout << j << " ";
                    ++a[j];
                    break;
                }
            }
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

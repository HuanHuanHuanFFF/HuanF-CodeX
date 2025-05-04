#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<ll> cost(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (int i = 1, k; i <= m; ++i) {
        cin >> k;
        for (int j = 0, a; j < k; ++j) {
            cin >> a;

        }
    }
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

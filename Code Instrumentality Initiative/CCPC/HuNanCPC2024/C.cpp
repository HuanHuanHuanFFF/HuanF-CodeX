#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// C https://codeforces.com/gym/105423
void HuanF() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ll x = 1, cnt = 0;
        while (x < a) x <<= 1, ++cnt;
        sum += cnt;
    }
    cout << (ll) ceill(sum / std::log2((long double) 2024));
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

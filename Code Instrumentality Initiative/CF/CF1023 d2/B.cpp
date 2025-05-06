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

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void HuanF() {
    ll n, k, all = 0;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
        all += x;
    }
    std::sort(a.begin(), a.end());
    if (a[n - 1] - a[0] > k + 1 || a[n - 2] - a[0] > k) {
        cout << "Jerry\n";
        return;
    }
    if (all & 1) {
        cout << "Tom\n";
    } else cout << "Jerry\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

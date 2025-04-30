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
constexpr int INF = 1e8 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void HuanF() {
    // cout << (1ll << 60) << "\n";
    ll n, ans = 0;
    vector<ll> a(59);
    // std::set<ll> st;
    cin >> n;
    for (int i = 1; i <= 59; ++i) {
        a[i - 1] = 1ll << i;
    }
    for (int i = 0; i < 59; ++i) {
        ll j = 3;
        if (n >= a[i]) ++ans;
        // if (n >= a[i] * 2 * 2) ++ans;
        while (n >= a[i] * j * j) {
            ++ans;
            j += 2;
        }
    }
    cout << ans;
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

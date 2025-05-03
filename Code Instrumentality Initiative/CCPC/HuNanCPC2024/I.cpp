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

// 纯模拟
// https://codeforces.com/gym/105423
void HuanF() {
    ll n, k, m, q;
    cin >> n >> k >> m >> q;
    vector<bool> has(n);
    for (ll i = 0, x, now; i < m; ++i) {
        cin >> x;
        now = x % n;
        for (int j = 0; j < k; ++j) {
            has[now] = true;
            now = x * now % n;
        }
    }
    for (ll i = 0, cnt, x, now; i < q; ++i) {
        cin >> x;
        now = x % n;
        cnt = 0;
        for (int j = 0; j < k; ++j) {
            if (has[now]) ++cnt;
            now = now * x % n;
        }
        cout << (cnt == k ? 1 : 0) << " ";
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

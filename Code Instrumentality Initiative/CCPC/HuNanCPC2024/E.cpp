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

void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(1 << 18);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int now = 0;
        for (int j = i; j <= n; ++j) {
            if (now & 1 << a[j]) break;
            now |= 1 << a[j];
            dp[now] = std::max(dp[now], j - i + 1);
        }
    }
    int mask = (1 << 18) - 1;
    for (int s = 0; s <= mask; ++s) {
        for (int b = 0; b < 18; ++b) {
            if (s & 1 << b) {
                //1<<b是s的子集,不断将b的最佳状态整合到超集
                dp[s] = std::max(dp[s], dp[s ^ 1 << b]);
            }
        }
    }
    int ans = 0;
    for (int s = 0; s <= mask; ++s) {
        ans = std::max(ans, dp[s] + dp[mask ^ s]);
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

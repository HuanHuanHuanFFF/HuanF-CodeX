#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

class Solution {
public:
    // int peopleAwareOfSecret(int n, int delay, int forget) {
    //     vector<ll> dp(n + 1);
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; ++i) {
    //         for (int j = std::max(1, i - forget + 1); j <= i - delay; ++j) {
    //             dp[i] += dp[j];
    //             dp[i] %= MOD;
    //         }
    //     }
    //     ll ans = 0;
    //     for (int i = std::max(n - forget + 1, 1); i <= n; ++i) {
    //         ans += dp[i];
    //         ans %= MOD;
    //     }
    //     return ans;
    // }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> d(n + 2);
        d[1] = 1;
        d[2] = -1;
        ll known = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            known = (known + d[i]) % MOD;
            d[std::min(i + delay, n + 1)] = (d[std::min(i + delay, n + 1)] + known) % MOD;
            d[std::min(i + forget, n + 1)] = (d[std::min(i + forget, n + 1)] - known + MOD) % MOD;
            if (i >= n - forget + 1) ans += known;
        }
        return ans % MOD;
    }
};

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

// https://leetcode.cn/problems/minimum-moves-to-balance-circular-array/description/
// 贪心
class Solution {
public:
    long long minMoves(vector<int> &balance) {
        ll sum = std::accumulate(balance.begin(), balance.end(), 0ll);
        if (sum < 0) return -1;
        ll ans = 0, n = balance.size(), idx = 0, need = 0;
        for (int i = 0; i < n; ++i)
            if (balance[i] < 0) {
                idx = i;
                need = -balance[i];
                break;
            }
        for (int i = 1; i < n; ++i) {
            ll d = std::min((ll) balance[(idx - i + n) % n] + balance[(idx + i) % n], need);
            need -= d;
            ans += d * i;
            if (need == 0) break;
        }
        return ans;
    }
};

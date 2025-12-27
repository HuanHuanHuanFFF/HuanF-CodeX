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
using PII = pair<ll, ll>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e17 + 17;
constexpr ll N = 1e7 + 7;

class Solution {
public:
    int mostBooked(int n, vector<vector<int> > &meetings) {
        std::map<int, int> cnt;
        vector<PII> room(n);
        for (int i = 0; i < n; ++i) room[i].second = i;
        std::ranges::sort(meetings);
        for (auto &v: meetings) {
            ll x = v[0], y = v[1];
            ll idx = 0, min = INF;
            for (auto &[end,num]: room) {
                end = std::max(x, end);
                if (end < min) {
                    idx = num;
                    min = end;
                }
            }
            auto &[end,num] = room[idx];
            ++cnt[num];
            end += y - x;
        }
        int ans = -1, max = 0;
        for (auto &[x,y]: cnt) {
            if (y > max) {
                ans = x;
                max = y;
            }
        }
        return ans;
    }
};
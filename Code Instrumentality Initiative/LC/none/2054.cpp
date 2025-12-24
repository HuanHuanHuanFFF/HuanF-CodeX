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
    int maxTwoEvents(vector<vector<int> > &events) {
        std::map<int, int> pre, suf;
        for (auto &e: events) {
            auto x = e[0], y = e[1], v = e[2];
            pre[y] = std::max(pre[y], v);
            suf[x] = std::max(suf[x], v);
        }
        int best = 0;
        for (auto &[x,y]: pre)
            best = y = std::max(best, y);
        best = 0;
        for (auto &[x,y]: std::views::reverse(suf))
            best = y = std::max(y, best);
        best = 0;
        for (auto &[x,y]: pre) {
            auto it = suf.lower_bound(x + 1);
            best = std::max(best, y + it->second);
        }
        return best;
    }
};

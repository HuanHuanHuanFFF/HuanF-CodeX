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
    vector<double> internalAngles(vector<int> &sides) {
        vector<double> ans;
        std::ranges::sort(sides);
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c) return ans;
        ans.resize(3, 0);
        ld cosa = (b * b + c * c - a * a) / (2 * b * c);
        ld cosb = (a * a + c * c - b * b) / (2 * a * c);
        ld cosc = (b * b + a * a - c * c) / (2 * b * a);
        ans[0] = (double) std::acos(cosa) / std::numbers::pi * 180;
        ans[1] = (double) std::acos(cosb) / std::numbers::pi * 180;
        ans[2] = (double) std::acos(cosc) / std::numbers::pi * 180;
        std::ranges::sort(ans);
        return ans;
    }
};

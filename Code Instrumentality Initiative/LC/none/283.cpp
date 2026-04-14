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
    void moveZeroes(vector<int> &nums) {
        int p = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[++p] = nums[i];
            }
        }
        while (++p < nums.size()) {
            nums[p] = 0;
        }
    }
};

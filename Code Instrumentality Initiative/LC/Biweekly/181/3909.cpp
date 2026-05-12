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
    int compareBitonicSums(vector<int> &nums) {
        ll sum1 = nums[0], sum2 = 0, n = nums.size();
        int i = 1;
        for (; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                sum1 += nums[i];
            else {
                sum2 = nums[i - 1];
                break;
            }
        }
        for (; i < n; ++i) sum2 += nums[i];
        if (sum1 > sum2) return 0;
        if (sum2 > sum1) return 1;
        return -1;
    }
};

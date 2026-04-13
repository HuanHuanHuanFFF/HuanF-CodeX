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
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        std::deque<int> dq;
        vector<int> ans;
        ans.reserve(nums.size() - k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && (i - dq.front()) >= k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.emplace_back(i);
            if (i >= k - 1) ans.emplace_back(nums[dq.front()]);
        }
        return ans;
    }
};

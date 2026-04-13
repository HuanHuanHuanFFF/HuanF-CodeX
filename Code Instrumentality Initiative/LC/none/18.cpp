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
    vector<vector<int> > fourSum(vector<int> &nums, ll target) {
        std::ranges::sort(nums);
        std::set<ll> st(nums.begin(), nums.end());
        std::set<vector<int> > ans;
        ll n = nums.size(), sum = 0;
        for (int i = 0; i < n - 3; ++i) {
            sum = nums[i];
            for (int j = i + 1; j < n - 2; ++j) {
                sum += nums[j];
                for (int k = j + 1; k < n - 1; ++k) {
                    sum += nums[k];
                    ll d = target - sum;
                    if ((d > nums[k] && st.contains(d)) || (d == nums[k] && nums[k + 1] == d))
                        ans.insert({nums[i], nums[j], nums[k], (int) d});
                    sum -= nums[k];
                }
                sum -= nums[j];
            }
        }
        return vector(ans.begin(), ans.end());
    }
};

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
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, r = 0, n = s.size();
        std::set<char> st;
        while (r < n) {
            while (!st.contains(s[r]) && r < n) {
                st.insert(s[r]);
                ++r;
            }
            ans = std::max(r - l, ans);
            st.erase(s[l]);
            ++l;
        }
        return ans;
    }
};

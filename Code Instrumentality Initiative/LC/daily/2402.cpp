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

// https://leetcode.cn/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2025-12-27
// 模拟,对meetings先排序(自动的字典序即按start从小到大排)
// 记录开会次数,数组/map等等都行
// 然后另外用一个数组模拟房间,需要记录end时间和编号
// 从小到大依次遍历meetings
// 每次要校准时间,去当前时间和房间会议结束时间end的最大值
// 然后再选出最早结束和编号最小的
// 这里可以排序实现,我开始就是排序实现的,但遍历同时去找更快
// NlogN>N,所以改掉了堆和排序,直接找
// 这里还能优化,cnt换数组,room换成vector<int>
// 时间复杂度O(n*L+LlogL)
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
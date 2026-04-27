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
constexpr ll N = 1e5 + 7;

/* 1353-Maximum Number of Events That Can Be Attended
 * link: https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/
 * 标签: 贪心, 区间匹配点, 小根堆, 跳跃扫描
 * 思路:
 * 每个事件 [start, end] 可以匹配 start 到 end 中的某一天, 每天最多参加一个事件
 * 本质是求最多能匹配多少个区间
 * 按 start 从小到大排序, 用 cur 表示当前日期
 * 将所有 start <= cur 的事件加入小根堆, 堆中维护这些事件的 end
 * 当前日期 cur 能参加的事件中, 应优先参加 end 最小的事件
 * 因为它最早结束, 若现在不参加, 后面更可能过期
 * 若堆为空, 说明当前没有事件可参加, 中间空日期无意义, 直接跳到下一个事件的 start
 * 若堆顶 end < cur, 说明该事件已经过期, 弹出即可
 * 否则参加堆顶事件, ans 加一, cur 后移一天
 * 正确性关键:
 * 对当前日期 cur, 所有 start <= cur 且未过期的事件都可以参加
 * 若不选 end 最小的事件, 而选了一个 end 更大的事件, 可以交换二者
 * 把当前日期给更早结束的事件不会降低后续可行性, 因为更晚结束的事件有更大的选择空间
 * 因此每次参加最早结束的事件是安全的
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */
class Solution {
public:
    int maxEvents(vector<vector<int> > &events) {
        int ans = 0;
        std::ranges::sort(events);
        std::priority_queue<int, vector<int>, std::greater<> > heap;
        for (int cur = 0, i = 0, n = events.size(); i < n || !heap.empty();) {
            if (heap.empty()) cur = events[i][0];
            while (i < n && events[i][0] <= cur) {
                heap.emplace(events[i][1]);
                ++i;
            }
            if (!heap.empty()) {
                if (heap.top() >= cur) {
                    ++cur;
                    ++ans;
                    heap.pop();
                } else
                    while (heap.size() && heap.top() < cur)
                        heap.pop();
            }
        }
        return ans;
    }
};

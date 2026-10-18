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
    /* 1705 - Maximum Number of Eaten Apples
     * link: https://leetcode.cn/problems/maximum-number-of-eaten-apples/
     * 标签: 贪心, 小根堆, 批次维护
     * 思路: 小根堆保存 (腐烂日, 剩余数量), 每天加入新批次, 优先吃最早腐烂的一批。
     * 第 i+days[i] 天已经腐烂, 先删除腐烂日 <= 当前日期的批次。
     * 每天只吃一个, 剩余放回堆; 生长期结束后继续处理库存。
     * 时间复杂度: O((n+D)logn), D 为 days 最大值; 空间复杂度: O(n)
     */
    int eatenApples(vector<int> &apples, vector<int> &days) {
        ll ans = 0, n = apples.size();
        std::priority_queue<PII, vector<PII>, std::greater<> > heap;
        for (int i = 0; i < n || !heap.empty(); ++i) {
            if (i < n && apples[i] > 0) heap.emplace(i + days[i], apples[i]);
            while (!heap.empty() && heap.top().first <= i) heap.pop();
            if (!heap.empty()) {
                auto [x,y] = heap.top();
                ++ans;
                --y;
                heap.pop();
                if (y > 0) heap.emplace(x, y);
            }
        }
        return ans;
    }
};

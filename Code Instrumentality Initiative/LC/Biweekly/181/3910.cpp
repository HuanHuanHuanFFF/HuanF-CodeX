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

/* Count Connected Subgraphs With Even Node Sum
 * link: https://leetcode.cn/problems/count-connected-subgraphs-with-even-node-sum/
 * 标签: 状态压缩, 枚举子集, DFS, 连通性判断
 * 思路:
 * 题目要统计点权和为偶数的连通子图数量
 * 因为 n 很小, 可以直接枚举所有非空点集 sub
 *
 * 对每个 sub 分两步判断:
 * 1. 统计 sub 中点权和, 如果是奇数, 一定不合法
 * 2. 如果点权和是偶数, 再判断 sub 在原图中是否连通
 *
 * 连通性判断用 DFS, 但这里的 vis 不是普通访问数组
 * 它的含义是:
 * bit 为 1 表示这个点不需要再走
 * bit 为 0 表示这个点还需要在当前集合中被访问
 *
 * 所以先令 vis = ~0, 表示所有点一开始都被封死, DFS 默认不能走
 * 然后枚举 sub 中的点, 把这些点对应 bit 从 1 翻成 0
 * 这样就相当于只把当前集合 sub 挖空成可访问区域
 * sub 外的点仍然是 1, DFS 走到时会直接返回, 自然起到阻断作用
 *
 * DFS 从 sub 中任意一个点 start 出发
 * 每访问到一个当前集合内的点, 就把它在 vis 中重新标成 1
 * 因此 DFS 结束后, 如果 sub 中所有点都被访问过
 * 那么 vis 在 sub 对应的位置也应该全是 1
 *
 * 因为 sub 中被选中的位是 1
 * 所以用 (vis & sub) == sub 判断当前集合是否全部被访问到
 * 若成立, 说明 sub 内所有点属于同一个连通块, 这个子图合法
 *
 * 本质:
 * 枚举点集 -> 用奇偶性筛掉一部分 -> 在当前点集内部 DFS 判断连通性
 *
 * 时间复杂度: O(2^n * (n + m))
 * 空间复杂度: O(n + m)
 */
class Solution {
public:
    int evenSumSubgraphs(vector<int> &nums, vector<vector<int> > &edges) {
        int n = nums.size(), ans = 0, U = (1 << n) - 1;
        vector g(n, vector<int>());
        for (auto &v: edges) {
            g[v[0]].emplace_back(v[1]);
            g[v[1]].emplace_back(v[0]);
        }

        for (unsigned int sub = 1; sub <= U; ++sub) {
            int sum = 0, start = 0;
            unsigned int vis = ~0;
            for (int i = sub, idx = 0; i != 0; i >>= 1, ++idx) {
                if (i & 1) {
                    sum += nums[idx];
                    vis ^= 1 << idx;
                    start = idx;
                }
            }
            if (sum & 1) continue;

            auto dfs = [&](auto &&self, int x)-> void {
                if ((vis >> x) & 1) return;
                vis |= 1 << x;
                for (auto &y: g[x]) {
                    self(self, y);
                }
            };
            dfs(dfs, start);
            if ((vis & sub) == sub) ++ans;
        }
        return ans;
    }
};

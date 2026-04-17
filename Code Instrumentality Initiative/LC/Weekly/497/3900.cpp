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

/* 3900-Longest Balanced Substring After One Swap
 * link: https://leetcode.cn/problems/longest-balanced-substring-after-one-swap/
 * 标签: 前缀和, 哈希表, 分类讨论
 * 思路:
 * 把 '1' 看成 +1, 把 '0' 看成 -1, 则一个子串平衡当且仅当这段区间和为 0, 也就是 pre[r] - pre[l - 1] = 0
 *
 * 一次交换的本质是: 从子串内拿出一个字符, 再从子串外换进来一个字符
 * 因此子串和一次最多只会变化 2
 * 证明: 若换出和换入字符相同, 区间和变化 0
 * 若换出 '0' 换入 '1', 区间和变化 +2
 * 若换出 '1' 换入 '0', 区间和变化 -2
 * 所以一个子串想通过一次交换变平衡, 它原来的区间和只能是 0, +2, -2 三种情况
 *
 * 于是枚举每个右端点 i, 只需要找三类左端点 p:
 * 1. pre[p] = pre[i], 此时区间和为 0, 本来就平衡
 * 2. pre[p] = pre[i] + 2, 此时区间和为 -2, 说明子串内 0 比 1 多 2, 需要区间外至少还有一个 '1' 换进来
 * 3. pre[p] = pre[i] - 2, 此时区间和为 +2, 说明子串内 1 比 0 多 2, 需要区间外至少还有一个 '0' 换进来
 *
 * 对于每个前缀和, 只保留最早和次早两个位置即可
 * 原因是: 最早位置能给出最长区间, 若它合法就是最优
 * 若它不合法, 设同一前缀和的最早和次早位置为 p1, p2, 则区间 (p1, p2] 的和为 0
 * 这说明这段区间本身是平衡段, 其中一定同时包含 '0' 和 '1'
 * 所以把左端点从 p1 移到 p2 后, 一定会从原区间中删掉至少一个 '0' 和一个 '1'
 * 因而原先"某种字符全被区间吃光"导致的不合法会被修正, 不需要再继续看更后面的位置
 *
 * cnt1[n] - cnt1[i] + cnt1[p] 表示区间 [p + 1, i] 外部的 '1' 的个数
 * cnt0[n] - cnt0[i] + cnt0[p] 表示区间 [p + 1, i] 外部的 '0' 的个数
 * 只要对应数量至少为 1, 就说明这次交换可以完成
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 *
 * 如果用的是第二个最早位置,那么就不用再次判断外面有没有0/1了,但是我懒得改了
 */
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        std::map<int, vector<int> > sum_p;
        vector<int> pre(n + 1), cnt0(n + 1), cnt1(n + 1);
        sum_p[0].emplace_back(0);
        for (int i = 1; i <= n; ++i) {
            cnt0[i] = cnt0[i - 1];
            cnt1[i] = cnt1[i - 1];
            pre[i] = pre[i - 1];
            if (s[i - 1] == '1') {
                ++cnt1[i];
                ++pre[i];
            } else {
                ++cnt0[i];
                --pre[i];
            }
            if (sum_p[pre[i]].size() < 2)
                sum_p[pre[i]].emplace_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int p = INF;
            if (sum_p.contains(pre[i]))
                p = sum_p[pre[i]][0];
            int l = i - p;
            ans = std::max(l, ans);
            for (int j = 0; j < 2; j++) {
                p = INF;
                if (sum_p.contains(pre[i] + 2) && sum_p[pre[i] + 2].size() > j)
                    p = sum_p[pre[i] + 2][j];
                l = i - p;
                if (l > 0 && cnt1[n] - cnt1[i] + cnt1[p] >= 1)
                    ans = std::max(l, ans);

                p = INF;
                if (sum_p.contains(pre[i] - 2) && sum_p[pre[i] - 2].size() > j)
                    p = sum_p[pre[i] - 2][j];
                l = i - p;
                if (l > 0 && cnt0[n] - cnt0[i] + cnt0[p] >= 1)
                    ans = std::max(l, ans);
            }
        }
        return ans;
    }
};

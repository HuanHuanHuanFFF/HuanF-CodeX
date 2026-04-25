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

/* 41. 缺失的第一个正数
 * link: https://leetcode.cn/problems/first-missing-positive/
 * 标签: 数组, 原地哈希, 置换
 * 思路:
 * 答案一定在 [1, n + 1] 中, 因为长度为 n 的数组最多只能放下 1 到 n 这 n 个正整数
 * 所以只需要关心 [1, n] 内的数, 其它数都可以忽略
 *
 * 对于一个合法值 x, 它应该被放到下标 x - 1
 * 从左到右扫描数组, 把当前值沿着 x -> x - 1 的映射不断归位
 * 每次把 x 放到 nums[x - 1], 再把原来占着这个位置的数拿出来继续处理
 *
 * 如果目标位置已经是 x, 说明出现重复值, 继续交换没有意义, 直接停止
 * 这也是 nums[x - 1] != x 这个条件的作用, 否则 [2, 2] 会陷入无效重复处理
 *
 * 扫描结束后, 如果 nums[i] != i + 1, 说明 i + 1 没有被放到自己的位置, 它就是最小缺失正数
 * 如果 1 到 n 都在正确位置, 答案就是 n + 1
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == i + 1 || x <= 0 || x > n) continue;
            while (x - 1 > i && nums[x - 1] > 0 && nums[x - 1] <= n && nums[x - 1] != x) {
                int t = nums[x - 1];
                nums[x - 1] = x;
                x = t;
            }
            nums[x - 1] = x;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

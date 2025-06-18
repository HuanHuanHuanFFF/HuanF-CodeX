//
// Created by 幻 on 2025/6/18.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = true;

// Codeforces Round 1031 (Div. 2) 
/* 2113D - Cheater
 * link: https://codeforces.com/contest/2113/problem/D
 * 标签: 前缀极值, 后缀极值, 二分答案, 双指针模拟
 * 思路:
 *  1. 预处理 pre_min[i] 记录前缀 [0..i] 最小牌下标
 *     预处理 suf_max[i] 记录后缀 [i..n-1] 最大牌下标
 *  2. calc() 用双指针模拟整局, O(n) 求当前手牌得分
 *  3. 初始得分 l=calc()
 *     二分目标分数 mid∈[l+1,n)
 *     把前 mid 张里最小牌 a[pre_min[mid-1]] 与后缀最大牌 a[suf_max[mid]] 交换
 *     若 calc() ≥ mid 说明 mid 可行, 否则不可行
 *     每轮后再还原交换, 保证手牌不受破坏
 *  4. 最终 l 即最大可得分
 * 时间复杂度: O(n log n) (calc O(n) × 二分 log n)
 * 空间复杂度: O(n)  (两个辅助数组)
 */
void HuanF() {
    void HuanF() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &x: a) cin >> x;
        for (auto &x: b) cin >> x;
        vector<int> pre_min(n), suf_max(n);
        for (int i = 1; i < n; ++i) {
            pre_min[i] = pre_min[i - 1];
            if (a[i] < a[pre_min[i]])
                pre_min[i] = i;
        }
        suf_max[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            suf_max[i] = suf_max[i + 1];
            if (a[i] > a[suf_max[i]])
                suf_max[i] = i;
        }

        auto calc = [&]() {
            int ans = 0, i = 0, j = 0, c = 0;
            while (c < n) {
                if (a[i] > b[j]) {
                    ++ans;
                    ++i;
                } else ++j;
                ++c;
            }
            return ans;
        };

        int l = calc(), r = n;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            std::swap(a[pre_min[mid - 1]], a[suf_max[mid]]);
            if (calc() >= mid) l = mid;
            else r = mid;
            std::swap(a[pre_min[mid - 1]], a[suf_max[mid]]);
        }
        cout << l << "\n";
    }

    signed main() {
        init();
        int T = 1;
        if (more) cin >> T;
        while (T-- > 0) HuanF();
        return 0;
    }

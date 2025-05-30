//
// Created by 幻 on 2025/5/30.
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

/* P1886-滑动窗口最小最大值
 * link: https://www.luogu.com.cn/problem/P1886
 * 标签: 单调队列, 滑动窗口, 队列
 * 思路:
 * - 使用双端队列 deq 存储窗口索引, 保证 a[deq.front()] 为当前最小值
 * - 遍历 i 从 0 到 n-1:
 *   1) 在队尾弹出所有 a[deq.back()] >= a[i] 的索引, 再将 i 入队 (保持递增)
 *   2) 如果 deq.front() <= i-k, 弹出队头 (过期)
 *   3) 若 i >= k-1, 将 a[deq.front()] 加入 min_res
 * - 清空 deq, 同理但在弹尾时弹出所有 a[deq.back()] <= a[i], 得到 max_res
 * 时间复杂度 O(n), 空间复杂度 O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::deque<int> deq;
    vector<int> ans;
    ans.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (!deq.empty() && a[deq.back()] >= a[i]) deq.pop_back();
        deq.emplace_back(i);
        while (deq.front() <= i - k) deq.pop_front();
        if (i >= k - 1)
            ans.emplace_back(a[deq.front()]);
    }
    for (auto &x: ans) cout << x << " ";
    cout << "\n";
    ans.clear();
    deq.clear();
    for (int i = 0; i < n; ++i) {
        while (!deq.empty() && a[deq.back()] <= a[i]) deq.pop_back();
        deq.emplace_back(i);
        while (deq.front() <= i - k) deq.pop_front();
        if (i >= k - 1)
            ans.emplace_back(a[deq.front()]);
    }
    for (auto &x: ans) cout << x << " ";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

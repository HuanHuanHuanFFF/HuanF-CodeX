//
// Created by 幻 on 2025/5/14.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* 67B - Restoration of the Permutation
 * link: https://codeforces.com/problemset/problem/67/B
 * 思路:
 *   将每个数字 i 视为有向无环图（DAG）中的一个节点，
 *   b[i] 恰好是节点 i 的“入度”——也就是在它之前必须安排的“大数”个数。
 *   利用拓扑排序的思想：把所有入度为 0 的节点（即 b[i]==0）先入最小堆，
 *   每次取出堆顶最小的 x 放入答案，这样保证字典序最小；
 *   然后模拟“删除”节点 x：对所有尚未放入且 x >= i+k 的节点 i，
 *   它们的入度 b[i]--，若变为 0 则压入堆。重复直到堆空。
 *   整体相当于对一个隐式 DAG 做优先队列版的拓扑排序。
 * 复杂度: O(n^2)，n≤1000 时足够。
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1), ans;
    ans.reserve(n);
    // 把b当做“入度”数组
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    // 小顶堆维护当前所有入度为 0 的节点，保证字典序最小
    std::priority_queue<int, vector<int>, std::greater<> > heap;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0) heap.push(i);
    }
    // 拓扑排序主循环
    while (heap.size()) {
        auto x = heap.top();
        ans.push_back(x);
        heap.pop();
        // 删除节点 x：相当于对所有满足 x >= i+k 的 i 减少“入度”
        for (int i = 1; i <= n; ++i) {
            if (x >= i + k)
                if (--b[i] == 0)
                    heap.push(i);
        }
    }
    for (auto &x: ans) cout << x << " ";
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

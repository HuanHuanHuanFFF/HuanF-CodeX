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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = true;

/* ABC214-E
 * link: https://atcoder.jp/contests/abc214/tasks/abc214_e
 * 标签: 贪心, 区间匹配点, 小根堆, 跳跃扫描
 * 思路:
 * 每个球可以放入一个区间 [L, R] 内的任意整数盒子, 每个盒子最多放一个球
 * 本质是判断所有区间能否各自匹配到一个不同的整数点
 * 按 L 从小到大排序, 用 cur 表示当前准备使用的盒子编号
 * 将所有 L <= cur 的区间加入小根堆, 堆中维护这些区间的右端点 R
 * 当前能放入 cur 的区间中, 应优先选择 R 最小的区间
 * 因为 R 最小的区间最早过期, 若不先放它, 之后更可能无法放置
 * 若堆顶 R < cur, 说明这个区间已经错过最晚可放位置, 一定无解
 * 若堆为空, 说明当前没有区间等待放置, 中间空盒子无意义, 直接将 cur 跳到下一个区间的 L
 * 正确性关键:
 * 对当前盒子 cur, 所有 L <= cur 的区间都已经可选
 * 若选择的不是最小 R 的区间, 而选择了一个更大的 R, 则可以交换二者的分配
 * 把 cur 分给更小 R 的区间不会让更大 R 的区间更难放, 因为更大 R 的区间可等待时间更长
 * 因此每次选择最小 R 的区间是安全的
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<PII> lr(n);
    for (auto &[x,y]: lr) cin >> x >> y;
    std::ranges::sort(lr);
    int cur = 0, i = 0;
    std::priority_queue<int, vector<int>, std::greater<> > heap;
    while (i < n || !heap.empty()) {
        if (heap.empty())
            cur = lr[i].first;
        while (i < n && cur >= lr[i].first) {
            heap.emplace(lr[i].second);
            ++i;
        }
        if (!heap.empty()) {
            if (heap.top() >= cur) {
                ++cur;
                heap.pop();
            } else {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

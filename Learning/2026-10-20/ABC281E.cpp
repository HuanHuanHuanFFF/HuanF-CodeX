//
// Created by 幻 on 2026/10/20.
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
using ld = long double;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
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

constexpr bool more = false;

/* ABC281-E - Least Elements
 * link: https://atcoder.jp/contests/abc281/tasks/abc281_e
 * 标签: 滑动窗口, 有序集合, 小根堆, 懒删除
 * 思路: multiset 维护窗口最小的 k 个数及其和, 其余数放入小根堆。
 * 新数更小时替换集合最大值; 删除出窗元素后若不足 k 个, 从堆补最小有效值。
 * 用 (值, 下标) 区分重复元素, 补数前按下标清理过期堆顶。
 * 每个堆项最多入堆、出堆各一次, 不必每轮重新遍历 k 个数。
 * 时间复杂度: O(nlogn), 空间复杂度: O(n)
 */
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    std::multiset<PLL> st;
    std::priority_queue<PLL, vector<PLL>, std::greater<> > heap;
    ll sum = 0;
    for (int i = 0, j = 0; i < n; ++j, ++i) {
        if (j < m) {
            st.emplace(a[i], i);
            sum += a[i];
            if (j >= k) {
                auto it = std::prev(st.end());
                heap.push(*it);
                sum -= it->first;
                st.erase(it);
            }
        } else {
            cout << sum << " ";
            auto it = std::prev(st.end());
            auto [v,idx] = *it;
            if (v > a[i]) {
                heap.push(*it);
                st.erase(it);
                sum = sum - v + a[i];
                st.emplace(a[i], i);
            } else {
                heap.emplace(a[i], i);
            }
            auto x = a[i - m];
            if (st.erase({x, i - m}))
                sum -= x;
            if (st.size() < k) {
                while (heap.top().second <= i - m) heap.pop();
                st.insert(heap.top());
                sum += heap.top().first;
                heap.pop();
            }
        }
    }
    cout << sum;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

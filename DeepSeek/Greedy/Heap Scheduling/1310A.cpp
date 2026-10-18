//
// Created by 幻 on 2026/10/18.
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

/* 1310A - Recommendations
 * link: https://codeforces.com/problemset/problem/1310/A
 * 标签: 贪心, 大根堆, 跳跃扫描
 * 思路: 按原值 a 排序, 扫描最终位置 x, 将所有 a <= x 的待安排元素加入大根堆。
 * 每次优先安排单位代价最大的元素, 让等待代价较小的元素后移, 累加 (x-a)*cost。
 * 堆空时跳到下一个原值; 访问 at[i] 前先判断 i < n。
 * 时间复杂度: O(nlogn), 空间复杂度: O(n)
 */
void HuanF() {
    ll ans = 0, n;
    cin >> n;
    vector<pair<ll, ll> > at(n);
    for (int i = 0; i < n; ++i) cin >> at[i].first;
    for (int i = 0; i < n; ++i) cin >> at[i].second;
    std::ranges::sort(at);
    std::priority_queue<pair<ll, ll> > heap;
    for (ll x = 0, i = 0; i < n || !heap.empty(); ++x) {
        if (i < n && x < at[i].first && heap.empty())
            x = at[i].first;
        while (i < n && x >= at[i].first) {
            heap.emplace(at[i].second, at[i].first);
            ++i;
        }
        if (!heap.empty()) {
            auto [cost,ai] = heap.top();
            heap.pop();
            ans += cost * (x - ai);
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

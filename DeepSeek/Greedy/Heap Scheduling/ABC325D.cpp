//
// Created by 幻 on 2026/10/16.
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

/* ABC325-D - Printing Machine
 * link: https://atcoder.jp/contests/abc325/tasks/abc325_d
 * 标签: 贪心, 小根堆, 跳跃扫描
 * 思路: 按进入时间排序, 将已到达商品的截止时间加入小根堆, 每次打印最早到期的一件。
 * 堆空时跳到下一次进入时间; 截止时刻仍可打印, 仅删除截止时间 < x 的商品。
 * 每打印一件都回到外层加入新商品, 不能一次清空堆。
 * 时间复杂度: O(nlogn), 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<pair<ll, ll> > td(n);
    for (auto &[t,d]: td) {
        cin >> t >> d;
        d = t + d;
    }
    std::ranges::sort(td);
    ll ans = 0, x = 0;
    std::priority_queue<ll, vector<ll>, std::greater<> > heap;
    for (int i = 0; i < n || !heap.empty();) {
        if (i < n && heap.empty() && x < td[i].first) {
            x = td[i].first;
        }
        while (i < n && x >= td[i].first) {
            heap.emplace(td[i].second);
            ++i;
        }
        while (!heap.empty() && heap.top() < x) heap.pop();
        if (!heap.empty()) {
            heap.pop();
            ++x;
            ++ans;
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

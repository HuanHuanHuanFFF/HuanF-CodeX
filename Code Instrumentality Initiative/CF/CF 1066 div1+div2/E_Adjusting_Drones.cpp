//
// Created by 幻 on 2025/11/23.
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
constexpr ll INF = 1e17 + 17;
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

/* Codeforces Round 1066 (Div. 1 + Div. 2)
 * E. Adjusting Drones
 * link: https://codeforces.com/contest/2157/problem/E
 * 标签: 二分答案, 频次计数, 贪心, 模拟
 * 思路: 初始统计每个能量值出现次数 若所有次数均不超过 k 则答案为 0
 * 为判断一般的步数 t 抽象出 check 函数 记 freq 为每个能量值的出现次数 由于每一步同一能量只保留最早出现的一个 剩余副本只能在若干步内向右移动
 * 在给定 t 的情况下 从右到左枚举能量值 i 用栈 st 记录当前右侧的空位置 首先把 freq[i] 等于 0 的位置入栈 表示这些能量值目前无人占用
 * 若 freq[i] 大于 1 则多出的副本优先塞入 st 中且位置不超过 i 加 t 的空位 代表这些无人机在 t 步内移动到最近的可达空位 若所有可达空位用尽仍有剩余 则把剩余副本全部推到位置 i 加 t
 * 这一过程给出了在最多 t 步操作内 最有利情况下各能量值频次的上界 扫描 freq 若存在频次大于 k 则 t 不可行 否则 t 可行
 * 由于 t 变大时可达空位只会变多 check 具有单调性 可在区间 1 到 2n 上二分出最小可行步数 与特判 0 步合并得到最终答案
 * 时间复杂度 O(n log n) 空间复杂度 O(n)
 */
void HuanF() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    std::map<int, int> cnt;
    for (auto &x: a) {
        cin >> x;
        ++cnt[x];
    }
    bool tag = true;
    for (auto &[x,y]: cnt) {
        if (y > k) {
            tag = false;
            break;
        }
    }
    if (tag) {
        cout << 0 << "\n";
        return;
    }
    auto check = [&](ll t) {
        vector<int> freq(n << 2 | 1), st;
        st.reserve(n << 2);
        for (auto &x: a) ++freq[x];
        for (ll i = n << 2; i; --i) {
            if (freq[i] == 0) st.emplace_back(i);
            while (freq[i] > 1 && st.back() <= i + t) {
                --freq[i];
                ++freq[st.back()];
                st.pop_back();
            }
            if (freq[i] > 1) {
                freq[i + t] += freq[i] - 1;
                freq[i] = 1;
            }
        }
        for (auto &x: freq)
            if (x > k) return false;
        return true;
    };
    ll l = 0, r = n << 1;
    while (l + 1 < r) {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

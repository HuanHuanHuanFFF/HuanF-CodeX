//
// Created by 幻 on 2025/8/2.
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

// Codeforces Round 1039 (Div. 2) 
/* 2128E1
 * link: https://codeforces.com/contest/2128/problem/E1
 * 标签: 二分, 前缀和, 中位数判定, 单调性
 * 思路:
 * 1 离散所有 a[i] 作为候选中位数 v，在这些值上二分查找最大 v
 * 2 构造映射 b[i]= (a[i]>=v?1:-1)，并计算前缀和 pre
 * 3 遍历 i=1..n，维护 m = min(pre[0..i-k]) 及对应起点 s
 *   若 pre[i]-m>=0 则存在长度>=k 的子数组 [s..i] 中位数>=v，记录 start=s,end=i 返回真
 * 4 二分结束后 l 即为最大次中位数，输出 l,start,end
 * 时间复杂度 O(n log n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    int start = 0, end = 0, l = 0, r = n + 1;
    auto check = [&](int x) {
        vector<int> pre(n + 1);
        int m = INF, s;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + (a[i] >= x ? 1 : -1);
            if (i >= k) {
                if (pre[i - k] < m) {
                    m = pre[i - k];
                    s = i - k + 1;
                }
                if (pre[i] - m >= 0) {
                    start = s;
                    end = i;
                    return true;
                }
            }
        }
        return false;
    };
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << " " << start << " " << end << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

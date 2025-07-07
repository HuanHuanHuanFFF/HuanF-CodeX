//
// Created by 幻 on 2025/7/6.
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

// EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2) 
/* 2124-E
 * link: https://codeforces.com/contest/2124/problem/E
 * 标签: 前缀和, 双指针, 构造, 贪心
 * 思路:
 * 1. 计算总和 sum, 判断奇偶及最大值是否超 sum/2, 无解输出 -1
 * 2. 线性扫描累加前缀和 now, 寻找 idx 满足 now < sum/2 < now + a[idx+1]
 * 3. 若 now == sum/2, 一步操作 b = a 即可
 * 4. 否则两步操作:
 *    - 第一步: extra = sum - 2*now, extra/2 从 a[idx+1] 和右侧元素中扣除, 记录到 ans1
 *    - 第二步: 选取 b = 当前 a (已变为前缀和为 sum/2), 全部清零
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    ll sum = std::accumulate(a.begin(), a.end(), 0ll);
    ll max = std::ranges::max(a);
    if (sum & 1 || max * 2 > sum) {
        cout << -1 << "\n";
        return;
    }
    ll now = 0, idx = 0;
    for (int i = 0; i < n - 1; ++i) {
        now += a[i];
        if (now + a[i + 1] > sum / 2) {
            idx = i;
            break;
        }
    }
    if (now == sum / 2) {
        cout << "1\n";
        for (auto x: a) cout << x << " ";
        cout << "\n";
    } else {
        vector<ll> ans1(n);
        ll more = sum - 2 * now;
        more /= 2;
        a[idx + 1] -= more;
        ans1[idx + 1] = more;
        for (int i = n - 1; i > idx + 1 && more; --i) {
            if (a[i] <= more) {
                more -= a[i];
                ans1[i] = a[i];
                a[i] = 0;
            } else {
                a[i] -= more;
                ans1[i] = more;
                more = 0;
            }
        }
        cout << "2\n";
        for (auto &x: ans1) cout << x << " ";
        cout << "\n";
        for (auto &x: a) cout << x << " ";
        cout << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

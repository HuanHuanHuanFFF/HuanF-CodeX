//
// Created by 幻 on 2025/7/31.
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

template<typename T>
struct BIT {
    int n;
    vector<T> t;

    explicit BIT(int n): n(n), t(vector<T>(n + 1)) {
    }

    int lowbit(int x) { return x & -x; }

    //单点修改
    void add(int x, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            t[i] += val;
        }
    }

    //查询前缀和
    ll pre_sum(int x) {
        ll ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += t[i];
        }
        return ans;
    }

    //查询闭区间和
    ll query(int l, int r) {
        return pre_sum(r) - pre_sum(l - 1);
    }
};

// Codeforces Round 1040 (Div. 2) 
// D. Stay or Mirror
// https://codeforces.com/contest/2130/problem/D
// 能过也是无敌了
// 只能想到无法证明的贪心
// 对于每一个变还是不变,去看能消除的和新造成的逆序对
// 但是由于不清楚对不对的影响,靠着BIT优越的时间复杂度,直接写了来了个n方的枚举,居然过了
// 第二天才知道原来一次枚举就是对的,n方是留下给不用BIT的暴力的
// void HuanF() {
//     int n;
//     cin >> n;
//     vector<int> p(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> p[i];
//     }
//     ll ans = INF;
//     for (int i = 1; i <= n; ++i) {
//         BIT<int> bit(n << 1), bck(n);
//         ll now = 0;
//         for (int j = 1; j < i; ++j) {
//             now += bit.query(p[j] + 1, n << 1);
//             bit.add(p[j], 1);
//             bck.add(p[j], 1);
//         }
//         for (int j = i; j <= n; ++j) {
//             auto inv = bit.query(p[j] + 1, n << 1);
//             auto del = bit.query(p[j] + 1, n * 2 - p[j]);
//             auto back = n - p[j] - bck.query(p[j] + 1, n);
//             if (del > back) {
//                 inv -= del;
//                 bit.add(n * 2 - p[j], 1);
//             } else {
//                 bit.add(p[j], 1);
//             }
//             bck.add(p[j], 1);
//             now += inv;
//         }
//         ans = std::min(now, ans);
//     }
//     cout << ans << "\n";
// }

/* D. Stay or Mirror
 * link: https://codeforces.com/contest/2130/problem/D
 * 标签: 逆序数、贪心、BIT
 * 思路:
 *  1. 每个位置 i 有两种选择:
 *     - 取原值  ai = p_i  → 必产生 left_i = # { j<i | p_j > p_i }  个逆序
 *     - 取镜像 ai = 2n-p_i → 必产生 right_i = # { j>i | p_j > p_i } 个逆序
 *  2. **互斥性证明**:
 *     对任意对 (i,j)(i<j):
 *       若 p_i > p_j, 则
 *         · 若 i 计 left_i, (i,j) 已计入答案, j 不再计 right_j
 *         · 若 j 计 right_j, (i,j) 已计入答案, i 不再计 left_i
 *       故 (i,j) 最多被计一次, 不会重复 (保证正确), 至少被计一次 (保证最优下界可达)
 *  3. 对每 i 付 min(left_i, right_i) 即达到全局最小逆序数
 *  4. 实现: 朴素双循环 O(n²) 统计左右更大数; n≤5·10³ 可通过
 * 时间复杂度: O(n²) (若用 BIT 为 O(NlogN))
 * 空间复杂度: O(N)
 */
void HuanF() {
    int n, ans = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) {
        int left = 0, right = 0;
        for (int j = 0; j < i; j++) if (p[j] > p[i]) left++;
        for (int j = i + 1; j < n; j++) if (p[j] > p[i]) right++;
        ans += std::min(left, right);
    }
    cout << ans << '\n';
}


signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

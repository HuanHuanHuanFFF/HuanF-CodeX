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

/* Meximum Array 2
 * link: https://codeforces.com/contest/2157/problem/C
 * 标签: mex, 区间约束, 分类构造
 * 思路:
 * 记每个位置 i 所属的约束类型
 * 用 tag[i] 的二进制低两位表示:
 *  - 第 0 位: 是否出现在某个 min 区间内
 *  - 第 1 位: 是否出现在某个 mex 区间内
 * 读入每个操作 [c,l,r] 时:
 *  - c=1 (min=k): 对 [l,r] 内位置, 若当前 tag 为偶数则加 1, 表示仅标记一次 min 约束
 *  - c=2 (mex=k): 对 [l,r] 内位置, 统一加 2, 标记其属于 mex 约束
 *
 * 最终对每个位置分类赋值:
 * 1) tag[i]==1: 仅在 min 区间内
 *    为了保证该区间 min=k, 给这些位置赋值 k
 * 2) tag[i] 为奇数且 >1: 同时在 min 与 mex 区间内
 *    min 约束要求 a[i] >= k, mex 约束区间内不能把该值取成 k
 *    所以令 a[i] = k+1, 即 >=k 且 !=k
 * 3) 其他情况 (tag[i] 为偶数): 不在 min 区间内, 可以取 <k
 *    同时若在 mex 区间内, 需要整个 mex 区间内出现 0..k-1
 *    只在 mex 而不在 min 的点在每个 mex 区间里一定不少于 k 个
 *    因此将所有 tag 为偶数的位置按下标顺序循环赋值
 *    k-1,k-2,...,1,0,k-1,...,0
 *    或者填0,1,......,k-1也可以
 *    任意长度 >=k 的连续一段都包含 0..k-1, 从而保证所有 mex=k 的区间成立
 *
 * 时间复杂度: O(nq) 暴力打标 + O(n) 构造答案 (题目保证数据范围下可通过)
 * 空间复杂度: O(n)
 *
 * 若使用2个数组标记可优化到O(n+q)+O(n)
 */
void HuanF() {
    void HuanF() {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> tag(n + 1);
        for (int i = 0, c, l, r; i < q; ++i) {
            cin >> c >> l >> r;
            if (c == 1) {
                for (int t = l; t <= r; ++t)
                    if (tag[t] % 2 == 0) ++tag[t];
            } else {
                for (int t = l; t <= r; ++t) tag[t] += 2;
            }
        }
        vector<int> ans(n + 1);
        int num = k - 1;
        for (int i = 1; i <= n; ++i) {
            if (tag[i] == 1) ans[i] = k;
            else if (tag[i] & 1) ans[i] = k + 1;
            else {
                ans[i] = num;
                num = (num - 1 + k) % k;
            }
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << "\n";
    }

    signed main() {
        init();
        int T = 1;
        if (more) cin >> T;
        while (T-- > 0) HuanF();
        return 0;
    }

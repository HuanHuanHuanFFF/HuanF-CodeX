//
// Created by 幻 on 2025/7/14.
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

// Codeforces Round 899 (Div. 2) 
/* 1882C
 * link: https://codeforces.com/contest/1882/problem/C
 * 标签: 枚举, 后缀和, 贪心
 * 思路:
 *   1. 预处理后缀正数和
 *      suf[i]=∑_{j=i}^{n-1} max(a[j],0)，表示从第 i 张开始能摘到的所有正数之和
 *   2. 枚举首次摘牌位置 i（0 基）：
 *      - 若 i 为偶数（原题中奇数位），则第一步得分 a[i]；否则得 0
 *      - 之后可以按策略摘完剩余所有正数，得分 suf[i+1]
 *      → 总分 = (i%2==0 ? a[i] : 0) + suf[i+1]
 *   3. 答案为所有 i 的最大总分
 *
 * 证明:
 *   策略：在剩余牌堆上，若栈顶为正数则摘，否则删除第 2 张
 *   - 若栈顶正数，直接摘取
 *   - 若栈顶非正，则删第 2 张，使下一张上移
 *   对任一正数，经过若干次删除偶数位后必会轮到栈顶，再被摘走
 *   因此后缀中所有正数都能摘完，得分恰为 suf[i+1]
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    vector<ll> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + std::max(0ll, a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll now = (i % 2 == 0 ? a[i] : 0) + suf[i + 1];
        ans = std::max(now, ans);
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/31.
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

// Codeforces Round 1028 (Div. 2)
/* D. Gellyfish and Camellia Japonica
 * link: https://codeforces.com/contest/2116/problem/D
 * 标签: 倒序逆推, 贪心, 模拟, 下界传递
 * 思路:
 *   目标: 在正序执行 q 次 “c[z]=min(c[x],c[y])” 操作后得到给定的 b 数组
 *   从后往前逆推每个位置的最小下界 low[i]
 *   1. 初始化 low[i]=b[i]
 *   2. 倒序遍历每条操作 (x,y,z):
 *      - 记 v=low[z] 代表“操作后 c[z] 至少要达到 b[z]”
 *      - 把 low[z]=0 表示“在这一步之前 z 上的值会被覆盖，不再需要保留下界”
 *      - 更新 low[x]=max(low[x],v), low[y]=max(low[y],v) 保证正序执行时
 *        c[x] 和 c[y] 中至少一个 ≥ v，才能让 min(c[x],c[y]) ≥ v
 *   3. 倒推结束后，low[i] 即为 a[i] 的最小可行值，记作 ans = low
 *   4. 再正序模拟一次：令 c=ans，依次执行 c[z]=min(c[x],c[y])，
 *      最终若 c[i] 恰好等于 b[i]，则输出 ans，否则输出 -1
 *   核心在于通过“倒序下界传递”得到最紧 a 数组，再“正序验证”保证可行
 * 时间复杂度: O(n+q)
 * 空间复杂度: O(n+q)
 */
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1);
    vector xyz(q, std::array<int, 3>());
    for (auto &x: b | std::views::drop(1)) cin >> x;
    auto low = b;
    for (auto &[x,y,z]: xyz) {
        cin >> x >> y >> z;
    }
    for (int i = q - 1; i >= 0; --i) {
        auto [x,y,z] = xyz[i];
        int v = low[z];
        low[z] = 0;
        low[x] = std::max(low[x], v);
        low[y] = std::max(low[y], v);
    }
    auto ans = low;
    for (auto &[x,y,z]: xyz) {
        low[z] = std::min(low[x], low[y]);
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] != low[i]) {
            cout << "-1\n";
            return;
        }
    }
    for (auto &x: ans | std::views::drop(1)) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

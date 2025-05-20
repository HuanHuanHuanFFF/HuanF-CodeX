//
// Created by 幻 on 2025/5/20.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* 2084D-Arcology On Permafrost
 * link: https://codeforces.com/problemset/problem/2084/D
 * 思路:
 * 1 由于最多删 m 段 长度 k, 剩余长度 n-m*k, 故 mex<=n-m*k
 * 2 每要保留 [0..mex-1] 中每个数需出现 m+1 次, 故 mex<=floor(n/(m+1))
 * 3 最大 mex = min(n-m*k, floor(n/(m+1))) 但 floor(n/(m+1))<=n-m*k 等价 n<(m+1)k 否则取 floor(n/(m+1))
 * 4 构造时令 max=floor(n/(m+1)), 周期= max(k, max), 保证相同元素间距>=k
 * 5 在每周期位置 i(0<=i<max) 填 i, 其余位置填 max
 * 6 删除任意 m 段皆无法完全移除 0..max-1 中任一元素, 保证 f(a)=max
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans(n, -1);
    int max = n / (m + 1);
    for (int i = 0; i < max; ++i) {
        for (int j = i; j < n; j += std::max(max, k)) {
            if (ans[j] == -1)
                ans[j] = i;
        }
    }
    for (auto &x: ans) cout << (x >= 0 ? x : max) << " ";
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

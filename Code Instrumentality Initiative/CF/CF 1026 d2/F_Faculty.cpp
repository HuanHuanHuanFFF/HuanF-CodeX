//
// Created by 幻 on 2025/5/26.
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

// Codeforces Round 1026 (Div. 2) 
/* 2110F-教职员
 * link: https://codeforces.com/contest/2110/problem/F
 * 标签: 模拟, 数学, 前缀, 摊还分析
 * 思路:
 *  - 定义 lambda f(x,y)=x%y+y%x 计算单对 beauty
 *  - 维护前缀最大值 max 和当前答案 ans
 *  - 对每个新元素 a[i]:
 *    1) 更新 ans = std::max(ans, f(max, a[i]))
 *    2) 若 a[i] > max:
 *       ├ 若 a[i] < 2*max, 则 ⌊a[i]/max⌋=1, f(a[i],max)=a[i], 可直接 ans=a[i]
 *       └ 否则 a[i]>=2*max, 此时 max 至少翻倍, 暴力遍历 j<i 更新 ans=f(a[i],a[j])
 *    3) 更新 max = a[i]
 *  - 每步输出 ans
 *
 * 时间复杂度 O(n log A) (摊还遍历至多 logA 次全遍历)
 * 空间复杂度 O(1) 额外 (不含输入和输出)
 */
void HuanF() {
    auto f = [](int x, int y) { return x % y + y % x; };
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int ans = 0, max = a[0];
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, f(max, a[i]));
        if (a[i] > max) {
            if (a[i] >= 2 * max) {
                max = a[i];
                for (int j = 0; j < i; ++j) {
                    ans = std::max(ans, f(a[i], a[j]));
                }
            } else {
                max = a[i];
                ans = max;
            }
        }
        cout << ans << " ";
    }
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

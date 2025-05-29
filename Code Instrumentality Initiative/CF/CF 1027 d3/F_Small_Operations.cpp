//
// Created by 幻 on 2025/5/28.
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

// Codeforces Round  1027 (Div. 3) 
/* 2114F. Small Operations
 * link: https://codeforces.com/contest/2114/problem/F
 * 标签: 数论, 动态规划, 枚举除数, 最短路
 * 思路:
 * 1. 设 g = gcd(x, y)，将 x、y 同时除以 g，问题拆为 x/g -> 1（整除步数）和 1 -> y/g（乘法步数）。
 * 2. 对任意整数 a，枚举其所有除数 divs，并对 divs 进行排序；
 * 3. 定义 dp[i] 为从 1 通过乘 ≤k 的因子到达 divs[i] 的最少步数，dp[0]=0（divs[0]=1），其余初始化为 INF；
 * 4. 状态转移：对 i 从 1 到 n-1，枚举 j 从 i-1 到 0：
 *      e = divs[i] / divs[j]，若 e > k 则 break（后续 j 更小 e 更大）；
 *      若 divs[i] % divs[j] == 0，则 dp[i] = min(dp[i], dp[j] + 1)；
 * 5. dp.back() 即为分解 a 的最少因子数，若仍为 INF 则返回 -1；
 * 6. 最终结果为 help(x/g, k) + help(y/g, k)，任一段不可达则输出 -1。
 * 时间复杂度：O(D^2)，D 为除数个数，对于 a ≤ 1e6 足够。
 */
void HuanF() {
    int x, y, k;
    cin >> x >> y >> k;
    int g = std::gcd(x, y);
    x /= g;
    y /= g;

    auto help = [](int x, int k) {
        if (x == 1) return 0;
        vector<int> divs;
        divs.reserve(x);
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                divs.emplace_back(i);
                divs.emplace_back(x / i);
            }
        }
        std::ranges::sort(divs);
        int n = divs.size();
        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int e = divs[i] / divs[j];
                if (e > k) break;
                if (divs[i] % divs[j] == 0)
                    dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    };

    int ax = help(x, k);
    int ay = help(y, k);
    if (ax == -1 || ay == -1) cout << -1;
    else cout << ax + ay;
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

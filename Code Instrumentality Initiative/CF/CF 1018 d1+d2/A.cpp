#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* 1018A-Wonderful Sticks
 * link: https://codeforces.com/contest/2096/problem/A
 * 思路:
 * 使用相对坐标方法，通过一个中心值同时向下和向上扩展，使得区间长度恰为 n
 * 1. 初始化 ans[0] = 1017, low = high = 1017
 * 2. 遍历 s:
 *    - 当 s[i] == '<' 时, 需要 ans[i+1] 小于之前所有元素, low--, ans[i+1] = low
 *    - 当 s[i] == '>' 时, 需要 ans[i+1] 大于之前所有元素, high++, ans[i+1] = high
 * 3. 此时 ans 中数值范围为 [low, high], 且 high-low+1 == n
 * 4. 将 ans 的每个元素映射到 [1, n], 输出时使用 ans[i] - low + 1
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n);
    ans[0] = 1017;
    int low = ans[0], high = ans[0];
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') ans[i + 1] = --low;
        else ans[i + 1] = ++high;
    }
    for (auto &x: ans) cout << x - low + 1 << " ";
    cout << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}
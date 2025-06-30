//
// Created by 幻 on 2025/6/28.
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

// Codeforces Round 991 (Div. 3) 
/* D-Digital string maximization
 * link: https://codeforces.com/problemset/problem/2050/D
 * 标签: 贪心 数位操作 滑动窗口 暴力枚举
 * 思路: 对每个下标 i 只需考虑区间 [i,i+9] 中能左移到 i 的数字 j
 *       候选价值 = s_j-(j-i) 取最大; 并列取最小 j 保证字典序最大
 *       将该数值先减去 (j-i) 再不断 swap 向左移到 i
 *       已确定的位置后续不再参与
 * 时间复杂度 O(n)  每位最多比较 10 个候选
 * 空间复杂度 O(1)
 */
void HuanF() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int max = s[i] - '0', pos = i;
        for (int j = 1; j < 10 && i + j < n; ++j) {
            if (s[i + j] - '0' - j > max) {
                max = s[i + j] - '0' - j;
                pos = i + j;
            }
        }
        s[pos] = (char) s[pos] - (pos - i);
        while (pos > i) {
            std::swap(s[pos], s[pos - 1]);
            --pos;
        }
        cout << s[i] - '0';
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/7/19.
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

constexpr bool more = false;

// Codeforces Beta Round 5
/* 5C-最长合法括号子串
 * link: https://codeforces.com/problemset/problem/5/C
 * 标签: 动态规划、括号匹配
 * 思路:
 * 定义 dp[i] 为以 i 结尾的最长合法括号子串长度
 * 如果 s[i]==')' 且 s[i-1]=='(' 则 dp[i]=2 + (i>=2 ? dp[i-2] : 0)
 * 否则若 s[i-1]==')' 且 i-dp[i-1]-1>=0 且 s[i-dp[i-1]-1]=='('
 * 则 dp[i]=dp[i-1] + 2 + (i-dp[i-1]>=2 ? dp[i-dp[i-1]-2] : 0)
 * 遍历时更新 max 和 cnt
 * 时间复杂度 O(n)  空间复杂度 O(n)
 */
void HuanF() {
    string s;
    cin >> s;
    int n = s.length(), max = 0, cnt = 1;
    vector<int> dp(n);
    for (int i = 1; i < n; ++i) {
        if (s[i] == ')') {
            if (s[i - 1] == '(')
                dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
            else if (s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
        }
        if (dp[i] > max) max = dp[i], cnt = 1;
        else if (dp[i] == max && max != 0) ++cnt;
    }
    cout << max << " " << cnt;
}

/* 5C-最长合法括号子串
 * link: https://codeforces.com/problemset/problem/5/C
 * 标签: 动态规划、括号匹配
 * 思路:
 * 定义 dp[i] 为以 i 结尾的最长合法括号子串长度
 * 如果 s[i]==')' 且 s[i-1]=='(' 则 dp[i]=2 + (i>=2 ? dp[i-2] : 0)
 * 否则若 s[i-1]==')' 且 i-dp[i-1]-1>=0 且 s[i-dp[i-1]-1]=='('
 * 则 dp[i]=dp[i-1] + 2 + (i-dp[i-1]>=2 ? dp[i-dp[i-1]-2] : 0)
 * 遍历时更新 max 和 cnt
 * 时间复杂度 O(n)  空间复杂度 O(n)
 */
void HuanF2() {
    string s;
    cin >> s;
    int n = s.length(), max = 0, cnt = 1;
    vector<int> stk;
    stk.reserve(n);
    stk.emplace_back(-1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') stk.emplace_back(i);
        else {
            stk.pop_back();
            if (stk.empty()) stk.emplace_back(i);
            else {
                int len = i - stk.back();
                if (len > max) max = len, cnt = 1;
                else if (len == max) ++cnt;
            }
        }
    }
    cout << max << " " << cnt;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF2();
    return 0;
}

//
// Created by 幻 on 2025/5/24.
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
// B. Down with Brackets
// link: https://codeforces.com/contest/2110/problem/B
/*
 * 思路:
 *  任何平衡括号序列都可以分解成若干个“原语”片段（primitive), 即无法再拆分的最小平衡子串。
 *  当且仅当原语片段数 > 1 时，删除第一个 '(' 和最后一个 ')' 会破坏平衡性。
 *  因此，扫描原序列，用栈统计在遇到 ')' 后栈为空的次数 cnt:
 *    - 每当 pop 导致栈空，即完成一个原语片段，cnt++。
 *  最终若 cnt > 1，则可删除使序列失衡，输出 "YES"，否则输出 "NO"。
 *
 * 时间复杂度: O(n)
 * 空间复杂度: O(n) （栈）
 */
void HuanF() {
    string s;
    cin >> s;
    std::stack<char> st;
    ll cnt = 0;
    for (auto c: s) {
        if (c == '(') {
            st.push(c);
        } else {
            st.pop();
            if (st.empty())
                ++cnt;
        }
    }
    cout << (cnt > 1 ? "YES" : "NO") << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

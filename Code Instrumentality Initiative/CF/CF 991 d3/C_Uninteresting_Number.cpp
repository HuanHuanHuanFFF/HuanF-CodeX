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
/* C-Uninteresting Number
 * link: https://codeforces.com/problemset/problem/2050/C
 * 标签: 模拟 数学 暴力枚举 数位操作
 * 思路:
 * 1 统计 sum、cnt2、cnt3
 * 2 若 sum%9==0 则输出 YES
 * 3 构造 add 数组: 存所有可由若干 2→4(增量2) 和 3→9(增量6) 组合成的增量
 *   枚举 i 从 2 到 cnt2*2+cnt3*6 步长 2
 *   令 x=min(i/6,cnt3), p=i-x*6, 若 p/2<=cnt2 则 i 合法
 *   将 i 加入 add
 * 4 遍历 add 若 (sum+x)%9==0 则输出 YES
 * 5 否则输出 NO
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    string s;
    cin >> s;
    ll sum = 0;
    int n = s.length(), cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i] - '0';
        if (s[i] - '0' == 2) ++cnt2;
        if (s[i] - '0' == 3) ++cnt3;
    }
    if (sum % 9 == 0) {
        cout << "YES\n";
        return;
    }
    vector<int> add;
    add.reserve(n << 1);
    for (int i = 2; i <= cnt2 * 2 + cnt3 * 6; i += 2) {
        int x = std::min(i / 6, cnt3);
        int p = i - x * 6;
        if (p / 2 <= cnt2 && x <= cnt3)
            add.emplace_back(i);
    }
    for (auto &x: add) {
        if ((sum + x) % 9 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

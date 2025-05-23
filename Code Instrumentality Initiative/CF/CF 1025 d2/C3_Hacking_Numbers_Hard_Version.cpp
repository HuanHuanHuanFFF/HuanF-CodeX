//
// Created by 幻 on 2025/5/23.
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

// Codeforces Round 1025 (Div. 2) 
/* C3. Hacking Numbers (Hard Version)
 * link: https://codeforces.com/contest/2042/problem/C3
 * 标签：交互、数论、数字根、9 补码
 * 思路：
 *   1. mul 999999999   // 将任意 x 乘以 10^9−1，使其数位和固定为 81
 *   2. digit           // 取数位和，x ← 81
 *   3. add n-81        // （若 n≠81）将 81 调整到目标 n
 *   4. !               // 输出答案并验证
 * f(81)=2，其它 n 时 f(n)=3
 */
void HuanF() {
    int n;
    cin >> n;

    cout << "mul 999999999" << endl;
    int x;
    cin >> x;

    cout << "digit" << endl;
    cin >> x;

    if (n != 81) {
        cout << "add " << n - 81 << endl;
        cin >> x;
    }

    cout << "!" << endl;
    cin >> x;
    assert(x == 1);
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

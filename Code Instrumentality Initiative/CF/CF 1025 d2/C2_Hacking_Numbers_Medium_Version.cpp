//
// Created by 幻 on 2025/5/22.
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

/* C2. Hacking Numbers (Medium Version)
 * link: https://codeforces.com/contest/2042/problem/C2
 * 思路:
 *   1. mul 9      // x 变为 9 的倍数
 *   2. digit      // 各位和仍为 9 的倍数，x ∈ {9,18,27,…,81}
 *   3. digit      // 再次求各位和，必得 9
 *   4. add n-9    // x 从 9 变为目标 n
 * 共 4 条命令，满足限制
 */
void HuanF() {
    int n, res;
    cin >> n;
    cout << "mul 9" << endl; // x ← x * 9，使 x 为 9 的倍数
    cin >> res;
    cout << "digit" << endl; // x ← S(x)，各位和仍为 9 的倍数
    cin >> res;
    cout << "digit" << endl; // x ← S(x)，数字根变成 9
    cin >> res;
    cout << "add " << n - 9 << endl; // x ← 9 + (n-9) = n
    cin >> res;
    cout << "!" << endl; // 输出结果并读取验证
    cin >> res;
    assert(res == 1);
}


signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

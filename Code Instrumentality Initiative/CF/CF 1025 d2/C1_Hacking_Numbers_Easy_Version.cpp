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

/* C1. Hacking Numbers (Easy Version)
 * link: https://codeforces.com/contest/2042/problem/C1
 * 思路:
 *   1. 对未知 x 先执行两次 "digit"，将 x 限制到 [1,16]
 *   2. 对 i=8,4,2,1 依次尝试 "add -i"，每次将 x 缩小到下一半区间，最终 x=1
 *   3. 然后执行 "add n-1"，将 x 从 1 变为目标 n
 *   4. 输出 "!" 并读取响应，确认 x==n
 */
void HuanF() {
    int n, res;
    cin >> n;
    // 第一次 digit：x∈[1,81]
    cout << "digit" << endl;
    cin >> res;
    // 第二次 digit：x∈[1,16]
    cout << "digit" << endl;
    cin >> res;
    // 依次减去 8,4,2,1，使 x 缩至 1
    for (int i = 8; i >= 1; i >>= 1) {
        cout << "add " << -i << endl;
        cin >> res;
    }
    // 最后将 x 从 1 变为 n
    cout << "add " << n - 1 << endl;
    cin >> res;
    // 输出答案并验证
    cout << "!" << endl;
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

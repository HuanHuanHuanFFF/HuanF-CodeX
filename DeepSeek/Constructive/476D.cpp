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
constexpr int N = 1e6 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

std::bitset<N> isp;
vector<int> num;

void init() {
    IOS();
}

// Codeforces Round 272 (Div. 2) 
/* D. Dreamoon and Sets
 * link: https://codeforces.com/problemset/problem/477/B
 * 思路:
 * 1. 要求集合中任意两数 gcd = k, 可令每个数除以 k, 化为两两互素的秩1集合 t_i = s_i / k
 * 2. 构造秩1模板 {6a+1, 6a+2, 6a+3, 6a+5}, 对于任意 a:
 *    - (6a+1),(6a+5) 为奇数互素
 *    - (6a+2) 仅含质因子2, 与奇数互素
 *    - (6a+3) 仅含质因子3, 与其它互素
 * 3. 将该模板按 a = 0…n-1 平移, 每组不重叠, 最大元素 t_max = 6(n-1)+5
 * 4. 最终答案 m = t_max * k, 每个 t_i 再乘回 k 输出
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    cout << ((n - 1) * 6 + 5) * k << "\n";
    for (int i = 0; i < n; ++i) {
        cout << (6 * i + 1) * k << " " << (6 * i + 2) * k << " " << (6 * i + 3) * k << " " << (6 * i + 5) * k << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

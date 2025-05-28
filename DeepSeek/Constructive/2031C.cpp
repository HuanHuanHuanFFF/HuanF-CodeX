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

// Codeforces Round 987 (Div. 2) 
/* 2031C - Penchick and BBQ Buns
 * link: https://codeforces.com/contest/2031/problem/C
 * 标签: 构造, 数学, 实现
 * 思路:
 * 区分奇偶 n
 * if n is even then 按 cnt=1,2,… 输出 cnt cnt 两两一对 保证距离1=1^2
 * if n is odd and n<27 then 无解
 * if n is odd and n>=27 then
 *   1. 先输出长度为27的硬编码前缀 满足多次出现的填充物间距为完美平方
 *   2. 对剩余 n-27 部分, 按 cnt=14,15,… 输出 cnt cnt 保证距离1=1^2
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    if (n & 1 && n < 27) {
        cout << "-1\n";
        return;
    }
    if (n & 1) {
        cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
        n -= 27;
        int cnt = 14;
        for (int i = 0; i < n; i += 2, ++cnt) {
            cout << cnt << " " << cnt << " ";
        }
        cout << "\n";
    } else {
        int cnt = 1;
        for (int i = 0; i < n; i += 2, ++cnt) {
            cout << cnt << " " << cnt << " ";
        }
        cout << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

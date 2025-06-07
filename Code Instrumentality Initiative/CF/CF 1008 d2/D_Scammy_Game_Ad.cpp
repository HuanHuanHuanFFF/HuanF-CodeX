//
// Created by 幻 on 2025/6/5.
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

// Codeforces Round 1008 (Div. 2) 
/* 2078D - 骗局游戏广告
 * link: https://codeforces.com/problemset/problem/2078/D
 * 标签: 贪心, 模拟
 * 思路:
 *   1. 把每个“+ a”看作直接增加 a 人，把每个“× a”看作新增 (a−1)*当前人数。
 *   2. 预处理数组 chose[i]：表示从第 i+1 对门开始，下一次出现“×”时，
 *      左右哪侧的乘数更大（0 表示左侧更大或相等，1 表示右侧更大）。
 *      逆序计算：若本对两侧均为“+”，继承下一位；若一侧为“×”另一侧为“+”，则“×”一侧更大；
 *      若两侧均为“×”，比较系数大小，相等时继承下一位。
 *   3. 顺序模拟：a[0], a[1] 初始为 1，表示左右当前人数。遍历第 i 对门：
 *      - 计算本对“新增总人数” add：
 *        若左是“+”，add+=vl[i]，否则 add+=(vl[i]−1)*a[0]；
 *        右侧同理。
 *      - 把 add 全部加到 a[chose[i+1]]，即未来乘数更大的一侧。
 *   4. 最终输出 a[0]+a[1] 即可。
 * 时间复杂度: O(n)，空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<char> opl(n), opr(n);
    vector<ll> vl(n), vr(n), chose(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> opl[i] >> vl[i] >> opr[i] >> vr[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (opl[i] == '+' && opr[i] == '+')
            chose[i] = chose[i + 1];
        else if (opl[i] == 'x' && opr[i] == '+')
            chose[i] = 0;
        else if (opl[i] == '+' && opr[i] == 'x')
            chose[i] = 1;
        else {
            if (vl[i] > vr[i]) chose[i] = 0;
            else if (vl[i] < vr[i]) chose[i] = 1;
            else chose[i] = chose[i + 1];
        }
    }
    vector<ll> a(2, 1);
    for (int i = 0; i < n; ++i) {
        ll add = 0;
        if (opl[i] == '+')
            add += vl[i];
        else add += (vl[i] - 1) * a[0];
        if (opr[i] == '+')
            add += vr[i];
        else add += (vr[i] - 1) * a[1];
        int cho = chose[i + 1];
        a[cho] += add;
    }
    cout << (a[0] + a[1]) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

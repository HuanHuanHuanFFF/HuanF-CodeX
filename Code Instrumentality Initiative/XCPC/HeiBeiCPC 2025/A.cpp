//
// Created by 幻 on 2025/5/20.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* A-棋盘
 * link: https://codeforces.com/gym/105909
 * 思路:
 * l和r表示走到相距两格时必须做出抉择往上走能获得的最大分数
 * 1 统计两行总分 r1,r2 并计算总得分 all=r1+r2
 * 2 统计左半区 l=1…n/2 各格得分之和 右半区 r=(n/2+2)…n 各格得分之和
 * 3 若 l>all-l 则 Mandy 必胜
 * 4 若 r>all-r 则 brz 必胜
 * 5 若 l==all-l 则比较 r1 与 r2 决胜或平局
 * 6 若 r==all-r 则比较 r2 与 r1 决胜或平局
 * 7 以上均不成立 则比较 r1 与 r2 决胜或平局
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<std::array<ll, 2> > g(n + 1);
    for (int i = 1; i <= n; ++i) cin >> g[i][0];
    for (int i = 1; i <= n; ++i) cin >> g[i][1];
    ll l = 0, r = 0, r1 = 0, r2 = 0, all = 0;
    for (int i = 1; i <= n; ++i) {
        r1 += g[i][0];
        r2 += g[i][1];
    }
    all = r1 + r2;
    for (int i = 1; i <= n / 2; ++i) {
        l += g[i][0] + g[i][1];
    }
    for (int i = n / 2 + 2; i <= n; ++i) {
        r += g[i][0] + g[i][1];
    }
    if (l > all - l) {
        cout << "Mandy\n";
        return;
    }
    if (r > all - r) {
        cout << "brz\n";
        return;
    }
    if (l == all - l) {
        if (r1 > r2)
            cout << "Mandy\n";
        else cout << "draw\n";
        return;
    }
    if (r == all - r) {
        if (r2 > r1)
            cout << "brz\n";
        else cout << "draw\n";
        return;
    }
    if (r1 > r2)
        cout << "Mandy\n";
    else if (r2 > r1)
        cout << "brz\n";
    else cout << "draw\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

/*
3
1
3
2
3
1 2 3
3 2 1
10
3 2 1 3 3 2 3 9 4 2
1 3 1 1 4 3 9 3 4 1
*/

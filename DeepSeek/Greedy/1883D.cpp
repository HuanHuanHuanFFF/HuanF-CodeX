//
// Created by 幻 on 2025/7/9.
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

// Codeforces Round 905 (Div. 3) 
// D. In Love
// https://codeforces.com/problemset/problem/1883/D
// 贪心
// 注意这里的线段不会合并,所有只需要保证最右边的线段和最左边的线段不重合就行
void HuanF() {
    int q;
    cin >> q;
    std::multiset<int> ls, rs;
    for (int i = 0, x, y; i < q; ++i) {
        char opt;
        cin >> opt >> x >> y;
        if (opt == '+') {
            ls.insert(x);
            rs.insert(y);
        } else {
            ls.erase(ls.find(x));
            rs.erase(rs.find(y));
        }
        if (ls.size() > 1 && *ls.rbegin() > *rs.begin()) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

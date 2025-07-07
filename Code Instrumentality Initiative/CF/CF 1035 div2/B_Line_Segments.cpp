//
// Created by 幻 on 2025/7/5.
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

// Codeforces Round 1035 (Div. 2) 
// B. Line Segments
// https://codeforces.com/contest/2119/problem/B
// 给你n个模长为ai的向量,是否能合成一个特定向量?
// 向量的加法遵循三角形法则,所以自然想到判断三角形是否成立
// 最通用的方法即为小的两条边相加大于打边
// 一切所需的向量最后都能分解到已有的向量上,判断三角形
// 找到模最长的向量v_max,把其他向量模长加在一起sum,sum>=v_max即可
// 同时要考虑几种特殊情况
void HuanF() {
    int n;
    cin >> n;
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    ll all = 0;
    vector<int> a(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[i] = x;
        all += x;
    }
    ll vx = qx - px, vy = qy - py;
    double vlen = sqrt(vx * vx + vy * vy);
    if (vlen == 0) {
        if (n == 1) cout << "No\n";
        else if (n == 2) {
            if (a[0] == a[1]) cout << "Yes\n";
            else cout << "No\n";
        } else {
            int max = std::ranges::max(a);
            all -= max;
            if (all >= max) cout << "Yes\n";
            else cout << "No\n";
        }
        return;
    }
    if (n == 1) {
        if (all == vlen) cout << "Yes\n";
        else cout << "No\n";
    } else {
        int max = std::ranges::max(a);
        if (max > vlen) {
            all -= max;
            if (all + vlen >= max) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if (all >= vlen) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

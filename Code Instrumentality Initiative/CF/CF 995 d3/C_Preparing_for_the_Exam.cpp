//
// Created by 幻 on 2025/6/27.
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

// Codeforces Round 995 (Div. 3) 
// C. Preparing for the Exam
// https://codeforces.com/contest/2051/problem/C
// 显然只有三种情况,进行简单的分类讨论
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    std::set<int> know;
    for (auto &x: a) cin >> x;
    for (int i = 0, x; i < k; ++i) {
        cin >> x;
        know.insert(x);
    }
    if (n == k) {
        for (int i = 0; i < m; ++i) {
            cout << 1;
        }
        cout << "\n";
        return;
    }
    if (k + 1 == n) {
        for (int i = 0; i < m; ++i) {
            if (!know.contains(a[i])) {
                cout << 1;
            } else cout << 0;
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < m; ++i) {
        cout << 0;
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

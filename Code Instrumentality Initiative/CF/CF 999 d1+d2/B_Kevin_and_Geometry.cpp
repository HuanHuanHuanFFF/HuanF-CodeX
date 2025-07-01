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

// IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2) 
// B. Kevin and Geometry
// https://codeforces.com/contest/2061/problem/B
// 几种情况分类讨论
void HuanF() {
    int n;
    cin >> n;
    std::map<int, int> cnt;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    vector<int> a, c;
    for (auto &[x,y]: cnt) {
        if (y >= 2) a.emplace_back(x);
        else c.emplace_back(x);
        if (y >= 3) c.emplace_back(x);
        if (y >= 4) {
            for (int i = 0; i < 4; ++i) {
                cout << x << " ";
            }
            cout << "\n";
            return;
        }
    }
    if (a.size() >= 2) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    } else if (a.size() == 0) {
        cout << "-1\n";
    } else {
        int p = a[0] << 1;
        for (int i = 0; i < c.size() - 1; ++i) {
            if (p + c[i] > c[i + 1]) {
                cout << a[0] << " " << a[0] << " " << c[i] << " " << c[i + 1] << "\n";
                return;
            }
        }
        cout << "-1\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

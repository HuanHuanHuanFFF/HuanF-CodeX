//
// Created by 幻 on 2025/7/6.
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

// EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2) 
// A. Deranged Deletions
// https://codeforces.com/contest/2124/problem/A
// 直接排序,把顺序相同的删掉
// 排序 O(NlogN)
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto b = a;
    std::ranges::sort(b);
    vector<bool> del(n);
    int d = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            ++d;
            del[i] = true;
        }
    }
    if (d == n) cout << "NO\n";
    else {
        cout << "YES\n" << n - d << "\n";
        for (int i = 0; i < n; ++i) {
            if (!del[i]) cout << a[i] << " ";
        }
        cout << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

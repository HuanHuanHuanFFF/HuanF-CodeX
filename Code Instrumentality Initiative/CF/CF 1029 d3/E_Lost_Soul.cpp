//
// Created by 幻 on 2025/6/8.
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

// Codeforces Round 1029 (Div. 3) 
// E. Lost Soul
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    for (auto &x: b | std::views::drop(1)) cin >> x;
    if (a[n] == b[n]) {
        cout << n << "\n";
        return;
    }
    int r = 0;
    std::set<int> suf;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || suf.contains(a[i]) || suf.contains(b[i])) {
            r = i;
            break;
        }
        suf.insert(a[i + 1]);
        suf.insert(b[i + 1]);
    }
    cout << r << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

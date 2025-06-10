//
// Created by 幻 on 2025/5/31.
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

// https://atcoder.jp/contests/abc408/tasks/abc408_b
// set
void HuanF() {
    int n;
    cin >> n;
    std::set<int> st;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << "\n";
    for (auto &x: st) cout << x << " ";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

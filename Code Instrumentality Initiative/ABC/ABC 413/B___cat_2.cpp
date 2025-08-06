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

constexpr bool more = false;

// Denso Create Programming Contest 2025（AtCoder Beginner Contest 413） 
// B - cat 2
void HuanF() {
    int n;
    std::set<string> st;
    cin >> n;
    vector<string> s(n);
    for (auto &x: s) cin >> x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            string x = s[i] + s[j];
            st.insert(x);
        }
    }
    cout << st.size();
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

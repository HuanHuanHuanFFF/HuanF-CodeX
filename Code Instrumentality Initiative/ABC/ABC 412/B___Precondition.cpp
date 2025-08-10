//
// Created by 幻 on 2025/6/28.
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

// AtCoder Beginner Contest 412 
// B - Precondition
void HuanF() {
    string s, t;
    cin >> s >> t;
    std::set<char> st(t.begin(), t.end());
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (!st.contains(s[i - 1])) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

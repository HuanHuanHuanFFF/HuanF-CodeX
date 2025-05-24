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

// https://codeforces.com/gym/105909
// 签到
void HuanF() {
    string s;
    cin >> s;
    string x = "isallyouneed";
    int n = s.size();
    if (s.substr(n - x.size()) == x) {
        cout << "Yes\n";
        cout << s.substr(0, n - x.size());
    } else cout << "No\n";
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

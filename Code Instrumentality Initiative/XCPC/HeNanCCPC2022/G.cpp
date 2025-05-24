//
// Created by 幻 on 2025/5/12.
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

// https://codeforces.com/gym/103941/problem/G
// 和操作,概率都没关系
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            cnt[j] += s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (cnt[i] == n) ++ans;
    }
    cout << ans;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

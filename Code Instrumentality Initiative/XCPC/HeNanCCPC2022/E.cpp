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

// https://codeforces.com/gym/103941/problem/E
// 贪心,最先满足的一定是最优的
void HuanF() {
    int n;
    cin >> n;
    std::map<char, int> cnt;
    string s, ans;
    cin >> s;
    int c[] = {5, 7, 5}, p = 0;
    for (int i = 0; i < n; ++i) {
        if (p < 3 && ++cnt[s[i]] == c[p]) {
            for (int j = 0; j < c[p]; ++j) {
                ans += s[i];
            }
            ++p;
            cnt.clear();
        }
    }
    if (ans.size() == 17)
        cout << ans;
    else cout << "none";
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

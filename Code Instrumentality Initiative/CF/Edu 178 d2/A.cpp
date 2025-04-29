#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e5 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 2104A – Three Decks
// Link: https://codeforces.com/contest/2104/problem/A
// 思路：sum = a+b+c；若 sum%3==0 且 sum/3 ≥ b 则可平分
void HuanF() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a + b + c) % 3 == 0 && b <= (a + b + c) / 3 ? "YES\n" : "NO\n");
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

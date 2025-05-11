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

// 其实是固定3个单词,不用getline
// https://codeforces.com/contest/2094/problem/A
void HuanF() {
    string s;
    std::getline(cin, s);
    cout << s[0];
    for (int i = 1; i < s.length() - 1; ++i) {
        if (s[i] == ' ') cout << s[i + 1];
    }
    cout << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    cin.ignore(999, '\n');
    while (T-- > 0)
        HuanF();
    return 0;
}

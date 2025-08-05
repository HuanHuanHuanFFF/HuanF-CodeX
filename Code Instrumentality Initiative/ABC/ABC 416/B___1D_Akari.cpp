//
// Created by 幻 on 2025/7/26.
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

// AtCoder Beginner Contest 416 
// B - 1D Akari
// 在每个#左边放一个o,最后在放一个o就是最多的
// https://atcoder.jp/contests/abc416/tasks/abc416_b
void HuanF() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '#') {
            ++cnt;
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] != '#') {
                    s[j] = 'o';
                    break;
                }
            }
        }
    }
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] != '#') {
            s[i] = 'o';
            break;
        }
    }
    cout << s;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

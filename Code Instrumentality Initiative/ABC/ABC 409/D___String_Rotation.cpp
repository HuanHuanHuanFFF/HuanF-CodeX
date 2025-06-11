//
// Created by 幻 on 2025/6/7.
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

// AtCoder Beginner Contest 409
// D - String Rotation
// https://atcoder.jp/contests/abc409/tasks/abc409_d
// 贪心,如果大就一直往后移
void HuanF() {
    int n;
    string s;
    cin >> n >> s;
    int start = -1, end = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            start = i;
            for (int j = i + 2; j < n; ++j) {
                if (s[i] < s[j]) {
                    end = j;
                    break;
                }
            }
            if (end == -1) end = n;
            break;
        }
    }
    if (start != -1) {
        s = s.substr(0, start) + s.substr(start + 1, end - start - 1) + s[start] + s.substr(end);
    }
    cout << s << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

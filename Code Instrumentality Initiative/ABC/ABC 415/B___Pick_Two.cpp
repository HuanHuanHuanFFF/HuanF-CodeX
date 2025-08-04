//
// Created by 幻 on 2025/8/4.
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
using ld = long double;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = false;

// Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415) 
// B - Pick Two
void HuanF() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '#') {
            for (int j = i + 1; j < s.length(); ++j) {
                if (s[j] == '#') {
                    cout << i + 1 << "," << j + 1 << "\n";
                    i = j;
                    break;
                }
            }
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

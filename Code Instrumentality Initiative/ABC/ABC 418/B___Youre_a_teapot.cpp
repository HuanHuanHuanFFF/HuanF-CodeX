//
// Created by 幻 on 2025/8/9.
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
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

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

// AtCoder Beginner Contest 418 
// B - You're a teapot
void HuanF() {
    string s;
    cin >> s;
    double ans = 0;
    int n = s.length();
    vector<int> pre(n), pos;
    if (s[0] == 't') {
        pre[0] = 1;
        pos.emplace_back(0);
    }
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + (s[i] == 't');
        if (s[i] == 't') pos.emplace_back(i);
    }
    int sz = pos.size();
    for (int i = 0; i < sz; ++i) {
        double now;
        for (int j = i + 1; j < sz; ++j) {
            now = (pre[pos[j] - 1] - pre[pos[i]]) / (double) (pos[j] - pos[i] + 1 - 2);
            ans = std::max(ans, now);
        }
    }
    printf("%.15lf", ans);
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/9/1.
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

// AtCoder Beginner Contest 420 
// B - Most Minority
void HuanF() {
    int n, m, max = 0;
    cin >> n >> m;
    vector s(n, vector<char>(m));
    std::map<int, int> scores;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
        }
    }
    for (int y = 0; y < m; ++y) {
        int cnt0 = 0;
        vector<int> c0, c1;
        for (int x = 0; x < n; ++x) {
            if (s[x][y] == '0') {
                ++cnt0;
                c0.emplace_back(x + 1);
            } else c1.emplace_back(x + 1);
        }
        if ((cnt0 + cnt0 > n && cnt0 != n) || cnt0 == 0) for (auto &x: c1) max = std::max(max, ++scores[x]);
        else if (cnt0 + cnt0 < n || cnt0 == n) for (auto &x: c0) max = std::max(max, ++scores[x]);
    }
    for (auto &[x,y]: scores)
        if (y == max) cout << x << " ";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

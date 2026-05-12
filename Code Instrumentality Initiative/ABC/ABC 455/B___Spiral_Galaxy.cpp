//
// Created by 幻 on 2026/4/25.
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

// Ｓｋｙ Inc, Programming Contest 2026 (AtCoder Beginner Contest 455) 
// B - Spiral Galaxy
void HuanF() {
    int h, w;
    cin >> h >> w;
    vector g(h + 1, vector<char>(w + 1));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> g[i][j];
        }
    }
    ll ans = 0;
    for (int h1 = 1; h1 <= h; ++h1) {
        for (int w1 = 1; w1 <= w; ++w1) {
            for (int h2 = h1; h2 <= h; ++h2) {
                for (int w2 = w1; w2 <= w; ++w2) {
                    bool tag = true;
                    for (int i = h1; i <= h2; ++i) {
                        for (int j = w1; j <= w2; ++j) {
                            if (g[i][j] != g[h1 + h2 - i][w1 + w2 - j]) {
                                tag = false;
                                break;
                            }
                        }
                    }
                    if (tag) ++ans;
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

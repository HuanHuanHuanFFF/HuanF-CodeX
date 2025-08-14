//
// Created by 幻 on 2025/8/7.
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

constexpr bool more = true;

// Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2) 
// B. Hamiiid, Haaamid... Hamid?
void HuanF() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int l = 0, r = 0, le = 0, ri = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            if (i < x - 1) ++l, le = std::max(le, i);
            else ++r, ri = std::min(ri, i);
        }
    }
    if ((l == 0 && r == 0) || x == 1 || x == n) {
        cout << 1 << "\n";
    } else {
        cout << std::min({std::max(le + 1, n - ri) + 1, x, n - x + 1}) << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

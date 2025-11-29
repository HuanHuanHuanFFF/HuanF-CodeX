//
// Created by 幻 on 2025/11/23.
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

// Codeforces Round 1066 (Div. 1 + Div. 2) 
// A. Dungeon Equilibrium
// 贪心,模拟
// 先统计全部数字的个数,再依次看处理,数量不够就全删掉,多的话就删掉多出来的
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    std::map<int, int> cnt;
    for (auto &x: a) {
        cin >> x;
        ++cnt[x];
    }
    int ans = 0;
    for (auto [x,y]: cnt) {
        ans += y - x < 0 ? y : y - x;
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

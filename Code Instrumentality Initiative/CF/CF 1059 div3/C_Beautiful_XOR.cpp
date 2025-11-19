//
// Created by 幻 on 2025/11/17.
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

// Codeforces Round 1059 (Div. 3)
// C. Beautiful XOR
// https://codeforces.com/contest/2162/problem/C
// 0<=x<=a
// 试图去调整a二进制上的每一位,与b对准
// 最大是a从最高位开始全部为1,如果b大于这个值则不能
// 然后将二进制每一位变的与b一样
void HuanF() {
    int a, b, cnt = 0;
    cin >> a >> b;
    for (int x = a; x > 0; x >>= 1) {
        ++cnt;
    }
    ll max = (1 << cnt) - 1;
    if (b > max) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    ans.reserve(cnt);
    for (int i = 0; i < cnt; ++i) {
        if ((b >> i & 1) != (a >> i & 1))
            ans.emplace_back(1 << i);
    }
    cout << ans.size() << "\n";
    if (!ans.empty()) {
        for (auto &x: ans) cout << x << " ";
        cout << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

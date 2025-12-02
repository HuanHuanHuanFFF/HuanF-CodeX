//
// Created by 幻 on 2025/11/30.
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

// Codeforces Round 1065 (Div. 3) 
// D. Rae Taylor and Trees (easy version)
// https://codeforces.com/contest/2171/problem/D
// 如果前面部分的最小值大于后面部分的最大值,那么一定不可能连成一棵树
void HuanF() {
    int n;
    cin >> n;
    vector<int> p(n + 1), pre(n + 1, INF), suf(n + 2);
    for (auto &x: p | std::views::drop(1)) cin >> x;
    for (int i = 1; i <= n; ++i) pre[i] = std::min(pre[i - 1], p[i]);
    for (int i = n; i >= 1; --i) suf[i] = std::max(suf[i + 1], p[i]);
    for (int i = 2; i <= n; ++i) {
        if (pre[i - 1] > suf[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

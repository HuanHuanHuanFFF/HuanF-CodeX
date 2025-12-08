//
// Created by 幻 on 2025/12/8.
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

// Codeforces Round 1050 (Div. 4) 
// D. Destruction of the Dandelion Fields
// https://codeforces.com/contest/2148/problem/D
// 需要一个奇数启动
// 后面都用大的奇数启动收割
// 开关开关开,可收割全部的(奇数/2)向上取整的个数,收割大的
void HuanF() {
    int n;
    cin >> n;
    std::priority_queue<int> heap;
    ll ans = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x & 1) heap.emplace(x);
        else ans += x;
    }
    if (heap.empty()) {
        cout << "0\n";
        return;
    }
    n = (heap.size() + 1) / 2;
    for (int i = 0; i < n; ++i) {
        ans += heap.top();
        heap.pop();
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

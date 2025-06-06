//
// Created by 幻 on 2025/6/1.
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

// Codeforces Round 1009 (Div. 3) 
// B. The Third Side
// https://codeforces.com/contest/2074/problem/B
// 无脑贪心
void HuanF() {
    int n;
    cin >> n;
    std::priority_queue<ll> heap;
    for (ll i = 0, x; i < n; ++i) {
        cin >> x;
        heap.emplace(x);
    }
    while (heap.size() > 1) {
        auto a = heap.top();
        heap.pop();
        auto b = heap.top();
        heap.pop();
        heap.emplace(a + b - 1);
    }
    cout << heap.top() << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/30.
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

// P5788 【模板】单调栈
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), ans(n + 1);
    for (auto &x: a | std::views::drop(1)) cin >> x;
    std::stack<int> stk;
    stk.emplace(1);
    for (int i = 2; i <= n; ++i) {
        while (!stk.empty() && a[i] > a[stk.top()]) {
            ans[stk.top()] = i;
            stk.pop();
        }
        stk.emplace(i);
    }
    for (auto &x: ans | std::views::drop(1)) cout << x << " ";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

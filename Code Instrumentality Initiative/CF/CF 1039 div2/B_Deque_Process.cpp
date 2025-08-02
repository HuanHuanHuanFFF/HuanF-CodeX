//
// Created by 幻 on 2025/7/27.
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

constexpr bool more = true;

// Codeforces Round 1039 (Div. 2) 
// B. Deque Process
// https://codeforces.com/contest/2128/problem/B
// 贪心 模拟
void HuanF() {
    int n;
    cin >> n;
    std::deque<int> dq;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        dq.emplace_back(x);
    }
    vector<int> a;
    vector<char> ans;
    ans.reserve(n);
    a.reserve(n);
    a.emplace_back(dq.back());
    dq.pop_back();
    ans.emplace_back('R');
    int cnt = 1;
    while (dq.size()) {
        if (cnt & 1) {
            if (dq.front() > dq.back()) {
                a.emplace_back(dq.front());
                dq.pop_front();
                ans.emplace_back('L');
            } else {
                a.emplace_back(dq.back());
                dq.pop_back();
                ans.emplace_back('R');
            }
        } else {
            if (dq.front() < dq.back()) {
                a.emplace_back(dq.front());
                dq.pop_front();
                ans.emplace_back('L');
            } else {
                a.emplace_back(dq.back());
                dq.pop_back();
                ans.emplace_back('R');
            }
        }
        ++cnt;
    }
    for (auto c: ans) cout << c;
    cout << "\n";
    for (auto x: a) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

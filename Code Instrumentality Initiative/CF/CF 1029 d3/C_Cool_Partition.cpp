//
// Created by 幻 on 2025/6/8.
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

// Codeforces Round 1029 (Div. 3) 
// C. Cool Partition
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int ans = 0;
    std::set<int> pre, now;
    for (auto x: a) {
        pre.insert(x);
        now.insert(x);
        if (now.size() == pre.size()) {
            ++ans;
            now.clear();
        }
    }
    cout << ans << "\n";
}

/*
// 狗屎贪心,赛时没有注意到出现过的一定会在后面出现
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int ans = 0;
    std::set<int> st1, st2;
    st1.insert(a[0]);
    for (int i = 1; i < n; ++i) {
        st2.insert(a[i]);
        if (st1.contains(a[i])) {
            st1.erase(a[i]);
            if (st1.empty()) {
                st1 = std::set<int>(st2);
                st2.clear();
                ++ans;
            }
        }
    }
    cout << ans + 1 << "\n";
}
 */

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

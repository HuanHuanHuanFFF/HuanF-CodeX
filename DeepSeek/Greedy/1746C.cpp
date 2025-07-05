//
// Created by 幻 on 2025/7/4.
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

// Codeforces Global Round 23 
// C. Permutation Operations
// https://codeforces.com/problemset/problem/1746/C
// 从后往前遍历,只要当前的和前一个抹平了,再看前面的就不会影响
// 由于给的是一个排列,所以一定能变成0逆序对
// 维护一个set集合,放的是第x次操作加上x
// 从后往前遍历,每次遇到前面一个比当前大的就从set中二分找>=差的,然后移除
// O(NlogN)
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), ans(n + 1, 1);
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        st.insert(i);
    }
    for (int i = n; i >= 2; --i) {
        if (a[i] < a[i - 1]) {
            int d = a[i - 1] - a[i];
            auto it = st.lower_bound(d);
            ans[*it] = i;
            st.erase(it);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

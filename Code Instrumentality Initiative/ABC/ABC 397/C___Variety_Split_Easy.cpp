//
// Created by 幻 on 2025/8/8.
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

constexpr bool more = false;

// OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397) 
// C - Variety Split Easy
void HuanF() {
    std::set<int> st;
    int n;
    cin >> n;
    vector<int> pre(n), suf(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.insert(a[i]);
        pre[i] = st.size();
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        st.insert(a[i]);
        suf[i] = st.size();
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans = std::max(ans, pre[i] + suf[i + 1]);
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

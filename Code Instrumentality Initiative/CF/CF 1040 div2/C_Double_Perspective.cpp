//
// Created by 幻 on 2025/7/31.
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

// Codeforces Round 1040 (Div. 2) 
// C. Double Perspective
// 贪心 排序
// 只要保证无环就一定是最优的
// 并集长度就是尽可能选多的元素
// 而环只有当选了新的集合,这个新集合的l和r都是当前并集的两端
// 而如果l到r已经选过了,也不用选
// 注意到数据范围可以n^2
// 直接用排序一下用set暴力维护集合就行
void HuanF() {
    int n;
    cin >> n;
    vector<std::array<int, 3> > ss(n);
    int pos = 0;
    for (auto &[a,b,p]: ss) cin >> a >> b, p = ++pos;
    std::ranges::sort(ss);
    std::set<int> st;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        auto [l,r,p] = ss[i];
        if (st.contains(l) && st.contains(r - 1)) continue;
        for (int j = l; j < r; ++j) {
            st.insert(j);
        }
        ans.emplace_back(p);
    }
    cout << ans.size() << "\n";
    for (auto &x: ans) cout << x << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

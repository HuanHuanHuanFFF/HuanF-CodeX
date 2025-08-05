//
// Created by 幻 on 2025/7/26.
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

// AtCoder Beginner Contest 416 
// D - Match, Mod, Minimize 2
// https://atcoder.jp/contests/abc416/tasks/abc416_d
// 二分,贪心
// 思考如何消掉最多的M?
// 那就让每个Ai和加起来>=Bi的数相加,同时为了避免浪费,让A从大到小排序
// 再依次查找合适的Bi
// 使用multiset进行查找删除过程即可
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
        x %= m;
    }
    for (auto &x: b) {
        cin >> x;
        x %= m;
    }
    std::multiset<ll> bs;
    for (auto &x: b) bs.insert(x);
    std::ranges::sort(a, std::ranges::greater());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = bs.lower_bound(m - a[i]);
        if (it == bs.end()) --it;
        ans += (a[i] + *it) % m;
        bs.erase(it);
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

//
// Created by 幻 on 2025/8/24.
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

// Codeforces Round 1044 (Div. 2) 
// B. Villagers
// https://codeforces.com/contest/2133/problem/B
// 每两个村民参加,消耗最大暴躁值的宝石,有一个村民的暴躁值变为0
// 为了让消耗最少,从大到小排序,从头到尾每次消耗两个大的中的最大值
// 最后通过0消耗让他们连起来,如果多出一个人要加上那个人
// O(NlogN)
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::ranges::sort(a, std::ranges::greater());
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += a[i];
    }
    cout << ans << "\n";
}

/*void HuanF() {
    int n;
    cin >> n;
    std::priority_queue<int> heap;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        heap.emplace(x);
    }
    ll ans = 0;
    while (heap.size()) {
        auto x = heap.top();
        heap.pop();
        if (heap.empty()) {
            ans += x;
            break;
        }
        auto y = heap.top();
        heap.pop();
        ans += x;
    }
    cout << ans << "\n";
}*/

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

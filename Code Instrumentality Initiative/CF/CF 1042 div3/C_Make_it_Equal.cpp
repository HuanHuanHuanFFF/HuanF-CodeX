//
// Created by 幻 on 2025/8/10.
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

// Codeforces Round 1042 (Div. 3) 
// C. Make it Equal
// https://codeforces.com/contest/2131/problem/C
// 模拟
// 所有的数经过加减,最后都能映射到x%k,|x%k-k|这两个值上
// 用map统计模拟即可
void HuanF() {
    int n, k;
    cin >> n >> k;
    std::map<int, int> s;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ++s[x % k];
    }
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (s.contains(x % k)) {
            if (--s[x % k] == 0)
                s.erase(x % k);
        } else if (s.contains(abs(x % k - k)))
            if (--s[abs(x % k - k)] == 0)
                s.erase(abs(x % k - k));
    }
    if (s.size() == 0) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

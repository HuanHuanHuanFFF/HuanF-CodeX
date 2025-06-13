//
// Created by 幻 on 2025/6/12.
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
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18 + 17;
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

// Codeforces Round 1030 (Div. 2) 
// C. Make It Beautiful
void HuanF() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x: a) cin >> x;
    std::priority_queue<PII, vector<PII>, std::greater<> > heap;
    for (auto &x: a) {
        for (int i = 0; i < 62; ++i) {
            if ((x >> i & 1) == 0) {
                ll dis = 1ll << i;
                heap.emplace(dis, x);
                break;
            }
        }
    }
    while (heap.size() && k) {
        auto [dis,x] = heap.top();
        if (dis > k) {
            break;
        }
        heap.pop();
        k -= dis;
        x += dis;
        for (int i = 0; i < 62; ++i) {
            if ((x >> i & 1) == 0) {
                ll d = 1ll << i;
                heap.emplace(d, x);
                break;
            }
            if (i == 61) heap.emplace(INF, x);
        }
    }
    ll ans = 0;
    while (heap.size()) {
        auto [d,x] = heap.top();
        heap.pop();
        for (int i = 0; i < 62; ++i) {
            if (x >> i & 1) {
                ++ans;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    // cout << std::log2(100000000000ll) << "\n";
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

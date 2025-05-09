#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// 排序模拟
// https://codeforces.com/gym/104417/problem/A
void HuanF() {
    ll n, k;
    cin >> n >> k;
    vector<PII> a(n);
    for (auto &[x,y]: a) {
        cin >> x >> y;
    }
    std::sort(a.begin(), a.end());
    ll now = 0, last = 0;
    for (auto &[x,y]: a) {
        now += (x - last) * k;
        now -= y;
        if (now < 0) {
            cout << "No\n";
            return;
        }
        last = x;
    }
    cout << "Yes\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

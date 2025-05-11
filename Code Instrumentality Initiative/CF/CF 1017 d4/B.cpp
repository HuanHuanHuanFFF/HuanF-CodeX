#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// 因为从0开始,所以必须保留0
// https://codeforces.com/contest/2094/problem/B
void HuanF() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int dis = n - m;
    if (dis > r) {
        dis -= r;
        r = 0;
        l += dis;
    } else {
        r -= dis;
    }
    cout << l << " " << r << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

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

// https://codeforces.com/contest/2094/problem/C
// 按题意模拟,最后填上没有的,用一个set即可
void HuanF() {
    int n;
    cin >> n;
    std::set<int> s;
    for (int i = 1; i <= n << 1; ++i) s.insert(i);
    vector<int> ans(n << 1 | 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, x; j <= n; ++j) {
            cin >> x;
            s.erase(x);
            ans[i + j] = x;
        }
    }
    for (int i = 1; i <= n << 1; ++i) {
        if (ans[i] == 0) {
            ans[i] = *s.begin();
            s.erase(s.begin());
        }
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

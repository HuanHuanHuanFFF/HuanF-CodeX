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

// https://codeforces.com/contest/2094/problem/F
// 构造,按m%k分类讨论
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    bool tag = false;
    if (m % k != 0)
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int ans = (i * m + j) % k + 1;
                cout << ans << " ";
            }
            cout << "\n";
        }
    else {
        vector<int> ans(m + 1);
        for (int i = 1; i <= m; ++i) {
            ans[i] = i % k + 1;
        }
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                cout << ans[m] << " ";
                for (int j = 1; j < m; ++j) {
                    cout << ans[j] << " ";
                }
                cout << "\n";
            } else {
                for (int j = 1; j <= m; ++j) {
                    cout << ans[j] << " ";
                }
                cout << "\n";
            }
        }
    }
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

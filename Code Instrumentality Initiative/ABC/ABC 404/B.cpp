#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
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

// https://atcoder.jp/contests/abc404/tasks/abc404_b
// 模拟旋转后的矩阵,依次对比取最大值
void HuanF() {
    int n;
    cin >> n;
    vector a(n, vector<bool>(n)), b(n, vector<bool>(n)), c(n, vector<bool>(n)), d(n, vector<bool>(n)), t(
        n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] == '.';
        }
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            t[i][j] = s[j] == '.';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[n - 1 - j][i];
            c[i][j] = a[n - 1 - i][n - 1 - j];
            d[i][j] = a[j][n - i - 1];
        }
    }
    ll ansa = 0, ansb = 1, ansc = 2, ansd = 3;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != t[i][j])++ansa;
            if (b[i][j] != t[i][j])++ansb;
            if (c[i][j] != t[i][j])++ansc;
            if (d[i][j] != t[i][j])++ansd;
        }
    }
    cout << std::min(std::min(ansa, ansb), std::min(ansc, ansd));
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

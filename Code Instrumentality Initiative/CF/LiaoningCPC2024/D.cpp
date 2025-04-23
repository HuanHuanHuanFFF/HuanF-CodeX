#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void HuanF() {
    int n;
    cin >> n;
    vector<long double> f(n + 1);
    vector max_d(n + 1, vector<long double>(n + 1));
    vector<int> xs(n + 1), ys(n + 1);
    for (int i = 1; i <= n; ++i) cin >> xs[i] >> ys[i];

    //计算i到j这一段点集能产生的最大距离
    //点集中每新增一个点,计算到其他所有点的距离,与新增前的点集最大距离比较
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            long double x = xs[i] - xs[j], y = ys[i] - ys[j];
            max_d[i][j] = std::max(max_d[i][j - 1], std::sqrt(x * x + y * y));
        }
    }
    //计算以i点结尾时能得到的最大距离
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            f[i] = std::max(f[i], f[j - 1] + max_d[j][i]);
        }
    }
    printf("%.10Lf", f[n]);
}

signed main() {
    IOS();
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

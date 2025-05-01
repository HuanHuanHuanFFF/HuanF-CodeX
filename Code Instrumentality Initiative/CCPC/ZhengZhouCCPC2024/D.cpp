#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 998244353;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* D-距离之比
 * 思路:
 * 1 通过分析可知 L1/L2 最大时斜率趋近 ±1
 * 2 旋转坐标系45度后对应一维投影 u=x-y, v=x+y
 * 3 分别对 u, v 排序, 只需枚举相邻点对计算比值
 * 时间复杂度 O(n log n), 空间 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    vector<pair<ll, int> > plus, minus;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        plus.emplace_back(x[i] + y[i], i);
        minus.emplace_back(x[i] - y[i], i);
    }
    std::sort(plus.begin(), plus.end());
    std::sort(minus.begin(), minus.end());

    auto cacl = [&](int i, int j) {
        return (abs(x[i] - x[j]) + abs(y[i] - y[j])) /
               std::sqrt((long double) (x[i] - x[j]) * (x[i] - x[j])
                         + (y[i] - y[j]) * (y[i] - y[j]));
    };

    long double ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, cacl(plus[i].second, plus[i - 1].second));
        ans = std::max(ans, cacl(minus[i].second, minus[i - 1].second));
    }
    printf("%.15Lf\n", ans);
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

/*
2
 2
 0 0
 0 1
 3
 1 1
 2 3
 5 8
*/

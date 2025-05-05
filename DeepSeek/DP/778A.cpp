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

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* 788A-Functions again
 * link: https://codeforces.com/problemset/problem/788/A
 * 思路:
 * 计算相邻差分并交替赋予符号得到b和c
 * 分别在b和c上运行Kadane算法求最大子段和
 * 答案为两者的最大值
 * 时间复杂度O(n) 空间复杂度O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1), c(n - 1);
    for (auto &x: a) cin >> x;
    for (int i = 0; i < n - 1; ++i) {
        if (i & 1)
            b[i] = abs(a[i] - a[i + 1]);
        else
            b[i] = -abs(a[i] - a[i + 1]);
        c[i] = -b[i];
    }
    ll ans = -INF, now = 0;
    for (int i = 0; i < n - 1; ++i) {
        now = std::max(0ll, now + b[i]);
        ans = std::max(now, ans);
    }
    now = 0;
    for (int i = 0; i < n - 1; ++i) {
        now = std::max(0ll, now + c[i]);
        ans = std::max(now, ans);
    }
    cout << ans;
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

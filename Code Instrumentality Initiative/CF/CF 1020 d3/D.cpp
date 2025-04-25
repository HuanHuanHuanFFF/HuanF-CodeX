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

auto AC() {
    //AC!
    //WA->AC
    //TLE/MLE->AC
}


/*
 * https://codeforces.com/contest/2106/problem/D
 * 核心思路：
 * 1. 预处理 pre[i] ：a[0..i] 用从左到右贪心可匹配的 b 前缀数量。
 * 2. 预处理 suf[i] ：a[i..n-1] 用从右到左贪心可匹配的 b 后缀数量。
 * 3. 枚举插花位置 i (插在 i-1 与 i 之间)：
 *      - 若 pre[i-1] + suf[i] >= m            → 不用插花即可满足，答案 0。
 *      - 若 pre[i-1] + suf[i] == m - 1        → 只差 1 朵，需要插入一朵 ≥ b[pre[i-1]] 的花，更新最小答案。
 * 4. 特判插在最左端 / 最右端，以及原本就能匹配 m 朵的情形。
*/
void HuanF() {
    int n, m, ans = INF;
    cin >> n >> m;
    vector<int> a(n), b(m), pre(n), suf(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    // pre
    for (int i = 0, j = 0; i < n; ++i) {
        if (j < m && a[i] >= b[j]) ++j;
        pre[i] = j;
    }
    // suf
    for (int i = n - 1, j = m - 1; i >= 0; --i) {
        if (j >= 0 && a[i] >= b[j]) --j;
        suf[i] = m - 1 - j;
    }

    for (int i = 1; i < n; ++i) {
        int have = pre[i - 1] + suf[i];
        if (have >= m) {
            ans = 0;
            break;
        }
        if (have == m - 1) ans = std::min(ans, b[pre[i - 1]]);
    }
    if (suf[0] == m - 1) ans = std::min(ans, b[0]);
    if (pre[n - 1] == m - 1) ans = std::min(ans, b[m - 1]);
    if (pre[n - 1] >= m) ans = 0;

    cout << (ans == INF ? -1 : ans) << '\n';
}

signed main() {
    IOS();
    AC();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

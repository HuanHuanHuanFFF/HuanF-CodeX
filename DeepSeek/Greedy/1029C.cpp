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

// Codeforces 1029C – Maximal Intersection
// Link: https://codeforces.com/problemset/problem/1029/C
// 思路：删除恰好一个区间后，剩余 n−1 段的交集区间长度最大。
// 用前缀/后缀预处理左右端点的最大/最小值，枚举删除位置 O(1) 合并。
void HuanF() {
    int n;
    cin >> n;
    // preL[i], preR[i] 存 1..i 的左端点最大值 / 右端点最小值
    // sufL[i], sufR[i] 存 i..n 的左端点最大值 / 右端点最小值
    // l[i], r[i] 存原始第 i 个区间的左右端点（1-based）
    vector<int> preL(n + 1), preR(n + 1), sufL(n + 2), sufR(n + 2), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
    preL[0] = sufL[n + 1] = 0;
    preR[0] = sufR[n + 1] = INF;
    for (int i = 1; i <= n; ++i) {
        preL[i] = std::max(l[i], preL[i - 1]);
        preR[i] = std::min(r[i], preR[i - 1]);
    }
    for (int i = n; i > 0; --i) {
        sufL[i] = std::max(sufL[i + 1], l[i]);
        sufR[i] = std::min(sufR[i + 1], r[i]);
    }
    int ans = 0;
    // 枚举删除第 i 个区间：剩余区间是 1..i-1 和 i+1..n
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, std::min(preR[i - 1], sufR[i + 1]) - std::max(preL[i - 1], sufL[i + 1]));
    }
    cout << ans;
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

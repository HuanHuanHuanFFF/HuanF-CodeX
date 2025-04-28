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

/****************************************************************
 * Codeforces 2028C – Alice’s Adventures in Cutting Cake
 * Link:https://codeforces.com/problemset/problem/2028/C
 * ------------------------------------------------------------
 * 题意（简化）：给 n 段蛋糕 a[1‥n]，必须先切出 m 段
 * “和 ≥ v” 的连续区间分给 m 只生物。剩下的某一段
 * 留给 Alice，要求这段区间和最大；若根本切不出 m 段，
 * 输出 -1。
 *
 * 核心思路（Occam 剃刀 + 模块化）：
 * 1. **滑窗预处理** prefix / suffix
 *    · pref[i] = 在前缀 [1..i] 内最多能喂几只生物
 *    · suf[i]  = 在后缀 [i..n] 内最多能喂几只生物
 *    双指针滑窗：右端 r 只增不减，累加和 s；一旦
 *    s ≥ v 就说明 [l..r] 喂得起一只，记录并继续滑。
 *    复杂度 O(n)。
 *
 * 2. **双指针枚举空档**
 *    固定左端 l = 生物块右端之后的位置（或 0），
 *    右端 r 平移直到再右移就不足 m 只生物：
 *        while (pref[l] + suf[r+1] ≥ m) ++r;
 *    若此时 pref[l] + suf[r] ≥ m，则 [l..r] 可留给
 *    Alice，区间和 sum[r]-sum[l] 参与最大值更新。
 *
 * 3. 无解判定：若 pref[n] < m ，直接 -1。
 *
 * 时空复杂度：
 *   · 预处理 pref + suf：O(n)
 *   · 扫 l, r：O(n)
 *   · 总 O(n)，额外 O(n) 空间。
 ****************************************************************/
void HuanF() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<ll> a(n), sum(n + 1);
    vector<int> pref(n + 1), suf(n + 2);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    auto cacl = [&]() {
        vector<int> pre(n + 1, 0);
        int r = 0;
        ll s = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && s < v) {
                s += a[r];
                ++r;
                pre[r] = std::max(pre[r], pre[r - 1]);
            }
            if (s >= v) pre[r] = pre[l] + 1;
            s -= a[l];
        }
        for (int i = 1; i <= n; ++i)
            pre[i] = std::max(pre[i], pre[i - 1]);
        return pre;
    };

    pref = cacl();
    std::reverse(a.begin(), a.end());
    suf = cacl();
    std::reverse(a.begin(), a.end());
    std::reverse(suf.begin(), suf.end());
    if (pref[n] < m) {
        cout << "-1\n";
        return;
    }
    int r = 0;
    ll ans = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && pref[l] + suf[r + 1] >= m) ++r;
        if (pref[l] + suf[r] >= m) ans = std::max(ans, sum[r] - sum[l]);
    }
    cout << ans << "\n";
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

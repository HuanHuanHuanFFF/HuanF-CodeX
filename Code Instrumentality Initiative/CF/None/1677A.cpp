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

/*
 * 任务: 统计满足 a<b<c<d, p[a]<p[c], p[b]>p[d] 的四元组数
 * 做法总览:
 *   1) 预处理 f[i] = 位置 i 右侧严格小于 arr[i] 的元素个数   (i 当 b 时的 d 计数)
 *   2) 枚举 c = 1..n
 *        2-a) 把 c 位置从所有 f[b] 中“销账”，保证 f 只管 d>c
 *        2-b) 给 f 做前缀和 pref，便于区间求和
 *        2-c) 枚举 a<i<c 且 arr[a]<arr[c]，一次性累加所有合法 (b,d)
 *   3) 输出答案
 * 复杂度: 预处理+主循环皆 O(n²)，n≤5000 可通过
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> arr(n + 1), f(n + 1), pref(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (arr[i] > arr[j]) ++f[i];
        }
    }
    ll ans = 0;
    for (int c = 1; c <= n; ++c) {
        /* ① 把新经过的下标 k 从所有 f[b] 里扣掉 —— f 只剩 d > k */
        for (int b = 1; b < c; ++b) {
            if (arr[b] > arr[c]) --f[b]; // pref[i] = Σ_{t=1..i} f[t]
        }
        pref[0] = 0;
        for (int i = 1; i <= c; ++i) {
            pref[i] = pref[i - 1] + f[i];
        }
        for (int i = 1; i < c; ++i) {
            //对于每一对可行的ac去计算可以的bd
            if (arr[i] < arr[c]) ans += pref[c - 1] - pref[i];
        }
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

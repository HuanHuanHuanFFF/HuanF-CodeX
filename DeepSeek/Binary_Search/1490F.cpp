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

// Codeforces 1490F – Equalize the Array
// Link: https://codeforces.com/problemset/problem/1490/F
// 思路（Occam’s Razor + 模块化）：
// 1. 统计每个数出现次数，存入数组 cnt，并升序排序。
// 2. 构造前缀和 pre，pre[i] = cnt[0] + … + cnt[i]。
// 3. 定义 cost(x)：
//    - 小于 x 的所有种类（下标 [0..low-1]）必须全部删除，共需删除 pre[low] 个元素；
//    - 大于等于 x 的种类有 K = cnt.size()−low 个，每种只保留 x 个，
//      删除 (原有总数 − pre[low] − K*x) 个；
//    - cost = pre[low] + (n − pre[low] − K*x)。
// 4. 枚举 x 从 1 到 n，取最小 cost(x) 即可。
// 时间复杂度 O(n log n + n·log n)。
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    std::map<int, int> ct;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++ct[a[i]];
    }
    vector<int> cnt, pre(ct.size());
    for (auto &[x,c]: ct) cnt.push_back(c);
    std::sort(cnt.begin(), cnt.end());
    pre[0] = cnt[0];
    for (int i = 1; i < ct.size(); ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    auto cost = [&](int x) {
        ll ans = 0;
        int low = std::lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin();
        ans += pre[low];
        ans += n - pre[low] - 1ll * (cnt.size() - low) * x;
        return ans;
    };

    ll ans = INF;
    for (int i = 1; i <= n; ++i) {
        ans = std::min(ans, cost(i));
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

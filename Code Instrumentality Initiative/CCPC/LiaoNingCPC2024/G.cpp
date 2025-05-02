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

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* 子数组最大值出现至少K次
 * link: https://example.com/problem
 * 思路:
 * 模块1 单调栈求出每个下标i左边第一个大于a[i]的位置l[i]和右边第一个大于a[i]的位置r[i]
 * 模块2 记录每个值v出现的下标列表pos[v],对列表上第j个位置p[j],令
 *   last[p[j]] = (j>0?p[j-1]:0)      // 上一次出现
 *   next[p[j]] = (j+k-1<pos[v].size()?pos[v][j+k-1]:n+1)  // 第k次出现
 * 模块3 枚举每个i作为“首次出现的最大值”贡献：
 *   左侧可选范围 = (max(l[i],last[i]) , i]
 *   右侧可选范围 = [ next[i] , r[i] )
 *   贡献 = 左侧长度 * 右侧长度, 累加即答案
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // 模块1：单调栈求l和r
    vector<int> l(n + 1), r(n + 1);
    vector<int> st;
    st.reserve(n);
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        l[i] = st.empty() ? 0 : st.back();
        st.push_back(i);
    }
    st.clear();
    for (int i = n; i > 0; --i) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        r[i] = st.empty() ? n + 1 : st.back();
        st.push_back(i);
    }
    // 模块2：记录出现位置求last和next
    vector<vector<int> > pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        pos[a[i]].push_back(i);
    }
    vector<int> last(n + 1), next(n + 1);
    for (int v = 1; v <= n; ++v) {
        auto &p = pos[v];
        for (int j = 0; j < p.size(); ++j) {
            int i = p[j];
            last[i] = (j > 0 ? p[j - 1] : 0);
            next[i] = (j + k - 1 < p.size() ? p[j + k - 1] : n + 1);
        }
    }
    // 模块3：枚举贡献
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll left = i - std::max(l[i], last[i]);
        ll right = std::max(0, r[i] - next[i]);
        if (left > 0 && right > 0) ans += left * right;
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

/*
2
 5 2
 1 3 3 2 2
 4 3
 1 4 2 1
 */

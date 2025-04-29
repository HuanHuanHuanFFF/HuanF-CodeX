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

// Codeforces 1909C – Heavy Intervals
// Link: https://codeforces.com/contest/1909/problem/C
// 思路：
// 1. 把所有左端点 l[i] 看作“(”，右端点 r[i] 看作“)”并按数值从小到大排序；
//    由于 l[i]<r[i]，任意前缀“(”数 ≥ “)”数，正是合法括号序列。
// 2. 用栈做“括号匹配”：遇“(”入栈，遇“)”出栈并配对。
//    这样得到的每对 (l, r) 保证**无交叉**；任何交叉配对都可通过交换端点而不增成本，
//    最终化为合法匹配。
// 3. 计算每对的长度 Δ = r - l，收集到 dis[]，对 dis 升序、权重 c 降序，
//    根据重排不等式（一大一小配）最小化 ∑ c[i]*Δ[i]。
// 复杂度：O(n log n)
void HuanF() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll, bool> > lr(n << 1);
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> lr[i].first;
        lr[i].second = true;
    }
    for (int i = n; i < n << 1; ++i) {
        cin >> lr[i].first;
        lr[i].second = false;
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    // 1. 按坐标排序，同坐标时保证左端点“(”在前
    std::sort(lr.begin(), lr.end(), [](auto &a, auto &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    // 2. 括号匹配：遇“(”入栈存 x，遇“)”出栈配对，收集 dis = r - l
    vector<ll> dis;
    std::stack<ll> l;
    for (auto &[x,isL]: lr) {
        if (isL) l.push(x);
        else {
            auto y = l.top();
            l.pop();
            dis.push_back(x - y);
        }
    }

    // 3. 重排贪心：Δ 升序，c 降序
    std::sort(dis.begin(), dis.end());
    std::sort(c.begin(), c.end(), std::greater<>());
    for (int i = 0; i < n; ++i) {
        ans += c[i] * dis[i];
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

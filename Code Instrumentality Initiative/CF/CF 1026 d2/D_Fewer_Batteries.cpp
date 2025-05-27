//
// Created by 幻 on 2025/5/24.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, ll>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Codeforces Round 1026 (Div. 2)
/* 2110D - Fewer Batteries
 * link: https://codeforces.com/contest/2110/problem/D
 * 思路:
 * 1 二分搜索最小容量 X 在 [0,INF] 区间  判断是否可从 1 到达 n 且背包非空
 * 2 定义 check(X): 用数组 bs[i] 表示在容量上限 X 下到达 i 点时最多可携带电池数
 *   - 初始化 bs[i]=0  (i>1)  bs[1]=0
 *   - 按点编号从 1 到 n 遍历 如果 i>1 且 bs[i]==0 则 跳过 (不可达)
 *   - 否则 bs[i]+=b[i]  再 bs[i]=min(bs[i],X)
 *   - 枚举所有出边 (i->y, w)  如果 bs[i]>=w 则 bs[y]=max(bs[y], bs[i])
 *   - 结束后 返回 bs[n]>0 即可到达并且剩余>0
 * 3 若 check(INF) 为假 则输出 -1  否则在 [0,INF] 上二分收缩 l r 直到 l+1>=r
 * 4 输出 r  即最小可行容量
 * 时间复杂度 O((n+m) logW)
 * 空间复杂度 O(n+m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    vector g(n + 1, vector<PII>());
    for (int i = 0, x, y, w; i < m; ++i) {
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
    }

    auto check = [&](ll x) {
        vector<ll> bs(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (i > 1 && bs[i] == 0) continue;
            bs[i] += b[i];
            bs[i] = std::min(bs[i], x);
            for (auto &[y,w]: g[i]) {
                if (w <= bs[i])
                    bs[y] = std::max(bs[y], bs[i]);
            }
        }
        return bs.back() > 0;
    };

    ll l = 0, r = INF;
    if (!check(r)) {
        cout << "-1\n";
        return;
    }
    while (l + 1 < r) {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/20.
//
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

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* M. 第九届河北大学生程序设计竞赛
 * link: https://codeforces.com/gym/105909/problem/M
 * 思路:
 * 预处理: 把 m 支队伍的过题情况压成 n 位 bitmask 存入数组 ac
 * 枚举: 枚举所有非空子集 i(1≤i<2^n) 仅保留选题数 choose=popcount(i)∈[10,13]
 * 计数: 对每支队伍 j 计算过题数 cnt[j]=popcount(ac[j]&i)
 * 排序: 将 cnt 按降序排序 方便直接按排名取值
 * 判断: 若 cnt[rkg-1]=pg 且 cnt[rks-1]=ps 且 cnt[rkb-1]=pb 则 i 为合法方案
 * 输出: 将 i 中的题号还原为 1..n 递增次序输出
 * 若遍历完无解 输出 -1
 * 时间复杂度: O(2^n·(m log m))
 * 空间复杂度: O(m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<ll> ac(m);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            ac[i] |= (s[n - 1 - j] - '0') << j;
        }
    }
    int rkg, rks, rkb, pg, ps, pb;
    cin >> rkg >> rks >> rkb >> pg >> ps >> pb;
    for (ll i = 1; i <= 1 << n; ++i) {
        int choose = __builtin_popcountll(i);
        if (choose < 10 || choose > 13) continue;
        vector<int> cnt(m);
        for (int j = 0; j < m; ++j) {
            ll x = ac[j] & i;
            cnt[j] = __builtin_popcountll(x);
        }
        std::sort(cnt.begin(), cnt.end(), std::greater<>());
        if (cnt[rkg - 1] == pg && cnt[rks - 1] == ps && cnt[rkb - 1] == pb) {
            vector<int> ans;
            ans.reserve(n);
            for (int j = 0; j < n; ++j) {
                if (i & 1 << j) ans.push_back(n - j);
            }
            std::reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (auto &x: ans) cout << x << " ";
            return;
        }
    }
    cout << "-1";
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

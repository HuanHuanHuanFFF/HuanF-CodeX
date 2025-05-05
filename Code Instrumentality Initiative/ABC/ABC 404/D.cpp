#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<ll, ll>;
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

/* ABC404-D
 * link: https://atcoder.jp/contests/abc404/tasks/abc404_d
 * 思路:
 * 1 N≤10, 每个动物园访问次数 x[j]∈{0,1,2}, 枚举空间 3^N
 * 3^10×M≤59049×100≈6×10^6
 * 2 递归枚举时维护当前花费 now, 若 now≥ans 则提前剪枝
 * 3 更新访问计数 cnt[i] = ∑_{j∈A_i} x[j], 最后检查 ∀i cnt[i]≥2
 * 4 满足则 ans = min(ans, now)
 * 时间复杂度 O(3^N * M)
 * 空间复杂度 O(N + M)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<ll> cost(n + 1), love(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    vector zoo(n + 1, vector<int>());
    for (int i = 1, k; i <= m; ++i) {
        cin >> k;
        for (int j = 0, a; j < k; ++j) {
            cin >> a;
            zoo[a].push_back(i);
        }
    }
    ll ans = INF;
    vector<int> cnt(m + 1);
    auto dfs = [&](auto &&self, int x, ll now)-> void {
        if (x == n + 1) {
            for (int i = 1; i <= m; ++i)
                if (cnt[i] < 2) return;
            ans = std::min(now, ans);
            return;
        }
        self(self, x + 1, now);
        for (int animal: zoo[x]) {
            ++cnt[animal];
        }
        self(self, x + 1, now + cost[x]);
        for (int animal: zoo[x]) {
            ++cnt[animal];
        }
        self(self, x + 1, now + cost[x] * 2);
        for (int animal: zoo[x]) {
            cnt[animal] -= 2;
        }
    };
    dfs(dfs, 1, 0);
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

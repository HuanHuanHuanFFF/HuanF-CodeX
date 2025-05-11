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
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// https://codeforces.com/problemset/problem/689/B
// 纯纯BFS,开始想了个dp真是糖丸了
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> ans(n + 1);
    vector<bool> vis(n + 1);
    std::queue<int> q;
    q.emplace(1);
    vis[0] = vis[1] = true;
    while (q.size()) {
        auto x = q.front();
        q.pop();
        if (x > 0 && !vis[x - 1]) {
            vis[x - 1] = true;
            q.emplace(x - 1);
            ans[x - 1] = ans[x] + 1;
        }
        if (x < n && !vis[x + 1]) {
            vis[x + 1] = true;
            q.emplace(x + 1);
            ans[x + 1] = ans[x] + 1;
        }
        if (!vis[a[x]]) {
            vis[a[x]] = true;
            q.emplace(a[x]);
            ans[a[x]] = ans[x] + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

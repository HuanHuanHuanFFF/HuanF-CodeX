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
constexpr int INF = 1e8 + 17;
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

// Codeforces 96B – Lucky Numbers (easy)
// Link: https://codeforces.com/problemset/problem/96/B
// 思路：
// 1. 用 DFS 生成所有只含 '4' 和 '7' 的字符串（长度 ≤ 10），转成整数存入 `lucky`。
// 2. 对 `lucky` 排序。
// 3. 用 `lower_bound` 找到第一个 ≥ n 的幸运数并输出。
void HuanF() {
    vector<ll> lucky;
    auto dfs = [&](auto &self, int cnt4, int cnt7, string now)-> void {
        if (now.length() == 11) return;
        if (cnt4 != 0 && cnt4 == cnt7) lucky.push_back(std::stoll(now));
        self(self, cnt4 + 1, cnt7, now + "4");
        self(self, cnt4, cnt7 + 1, now + "7");
    };
    dfs(dfs, 0, 0, "");
    std::sort(lucky.begin(), lucky.end());
    int n;
    cin >> n;
    auto ans = *std::lower_bound(lucky.begin(), lucky.end(), n);
    cout << ans << "\n";
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

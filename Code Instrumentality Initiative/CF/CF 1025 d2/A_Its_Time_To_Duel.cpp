//
// Created by 幻 on 2025/5/22.
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

/* A. It's Time To Duel
 * link: https://codeforces.com/contest/2042/problem/A
 * 思路:
 *  1. 若所有玩家都报 1（sum==n），则 n−1 场对决中必有一人输却报赢，必有谎报
 *  2. 若存在相邻两人都报 0，则他们的对决中必有一人赢却报 0，必有谎报
 *  以上两种情况任一成立则输出 YES，否则输出 NO
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int sum = std::accumulate(a.begin(), a.end(), 0);
    if (sum == n) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 0 && a[i + 1] == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

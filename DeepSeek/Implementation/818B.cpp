//
// Created by 幻 on 2025/5/27.
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

// Educational Codeforces Round 24 
/* 818B-Permutation Game
 * link: https://codeforces.com/problemset/problem/818/B
 * 标签: 模拟, 数学, 圈游戏
 * 思路:
 * 1. 用 set<int> 维护未使用数字
 * 2. 相邻领队 l[i-1]→l[i] 唯一确定 a_{l[i-1]} = delta
 *    delta = (l[i]-l[i-1]+n)%n, 若为 0 记作 n
 * 3. 若该位置未赋值则分配 delta, 同时检查 delta 未被占用; 若已赋值则必须等于 delta, 否则无解
 * 4. 处理完 m-1 对后, 将其余未赋值位置按序填入 set 中剩余最小值
 * 时间复杂度 O(n)  空间复杂度 O(n)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), ans(n + 1);
    for (auto &x: l) cin >> x;
    std::set<int> unused;
    for (int i = 1; i <= n; ++i) unused.insert(i);
    for (int i = 1; i < m; ++i) {
        int p = l[i - 1];
        int d = (l[i] - l[i - 1] + n) % n;
        if (d == 0) d = n;
        if (ans[p] == 0) {
            if (!unused.count(d)) {
                cout << -1;
                return;
            }
            ans[p] = d;
            unused.erase(d);
        } else if (ans[p] != d) {
            cout << -1;
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!ans[i]) {
            ans[i] = *unused.begin();
            unused.erase(unused.begin());
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

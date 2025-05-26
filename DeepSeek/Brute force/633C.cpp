//
// Created by 幻 on 2025/5/25.
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

// Manthan, Codefest 16 
/* D. Fibonacci-ish (Codeforces 633D)
 * link: https://codeforces.com/contest/633/problem/D
 * 标签：哈希、计数、枚举、贪心模拟
 *
 * 思路：
 * 1. 统计输入数组中每个数的出现次数，存入 cnt
 * 2. 考虑特殊情况：如果有 x=0 出现超过 2 次，则所有前两项都选 0
 *    可得到最长全 0 的序列，长度即 cnt[0]
 * 3. 对所有下标对 (i,j)，枚举第一个数 f0=a[i]，第二个数 f1=a[j]，i != j
 *    跳过 (0,0) 组合，因已在特殊情况处理
 * 4. 用 vector<ll> used 记录本次模拟中用过的值，每次使用前两项时先减计数并记录
 * 5. 循环生成下一项 z=f0+f1，只要 cnt[z]>0 就能继续：
 *      - cnt[z]--; used.push_back(z); len++;
 *      - x=y; y=z;
 * 6. 模拟结束后，更新 ans = max(ans, len)
 * 7. 恢复计数：对 used 中所有值，cnt[v]++，保证下次模拟正确
 * 8. 输出 ans
 *
 * 复杂度：O(n^2 * L)，L≈50，n≤1000，满足时限
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    std::map<ll, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int ans = 2;
    if (cnt[0] > 2) ans = cnt[0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || (a[i] == 0 && a[j] == 0)) continue;
            vector<ll> used;
            used.reserve(57);
            int l = 2;
            ll x = a[i];
            ll y = a[j];
            ll z = a[i] + a[j];
            --cnt[a[i]];
            --cnt[a[j]];
            used.push_back(a[i]);
            used.push_back(a[j]);
            while (cnt.count(z) && cnt[z] > 0) {
                --cnt[z];
                used.push_back(z);
                ++l;
                x = y;
                y = z;
                z = x + y;
            }
            ans = std::max(ans, l);
            for (auto p: used) ++cnt[p];
        }
    }
    cout << ans;
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

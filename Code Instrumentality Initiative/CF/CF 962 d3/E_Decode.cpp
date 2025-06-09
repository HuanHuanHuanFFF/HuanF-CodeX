//
// Created by 幻 on 2025/6/8.
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

constexpr bool more = true;

// Codeforces Round 962 (Div. 3) 
/* 1996E-Decode
 * link: https://codeforces.com/contest/1996/problem/E
 * 标签: 前缀和、哈希计数
 * 思路:
 *   1. 将字符 '1' 映射为 +1，'0' 映射为 -1，构建前缀和 pre，pre[0]=0，pre[i]=pre[i-1]+映射值。
 *   2. 子串 [x..y] 中 0 与 1 等量的充要条件是 pre[y] == pre[x-1]。
 *   3. 枚举每个 i (0≤i≤n) 作为子串右端 y：
 *      - 用 map cnt[val] 维护所有 j<i 且 pre[j]==val 时 (j+1) 的累加和。
 *      - 对当前 i，累加贡献 (n-i+1) * cnt[pre[i]] 到答案，表示所有可能的左端 x=j+1 和右端 r 的组合总数。
 *   4. 每处理完 i，再更新 cnt[pre[i]] += (i+1)，供后续使用。
 *   5. 最终输出累加结果 mod 1e9+7。
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (s[i] == '1' ? 1 : -1);
    }
    std::map<int, ll> cnt;
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        // 可以在i~n被选中
        ans = (ans + (n - i + 1) * cnt[pre[i]]) % MOD;

        // 在1~n被选中的贡献
        cnt[pre[i]] = (cnt[pre[i]] + (i + 1)) % MOD;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

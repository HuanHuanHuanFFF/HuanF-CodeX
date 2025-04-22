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

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* https://www.luogu.com.cn/problem/P2679
 * 状态设计
 * dp(i,j,c,0/1) a前i个,b前j个,选了c段,选/不选当前的字符    该情况下匹配的方案数
 * if ai==bj dp(i,j,c,0)=dp(i-1,j,c,0)+dp(i-1,j,c,1)    继承前一位的方案
 *           dp(i,j,c,1)=dp(i-1,j-1,c,1)+dp(i-1,j-1,c-1,1)+dp(i-1,j-1,c-1,0)
 *
 * 状态解释:    dp(i-1,j-1,p,1)继续已有子串   dp(i-1,j-1,p-1,0)千一位不选,开启新段
 *             dp(i-1,j-1,p-1,1)前一段选,但是开启新一段
 *
 * else dp(i,j,c,0)=dp(i-1,j,c,0)+dp(i-1,j,c,1)         继承前一位的方案
 *      dp(i,j,c,1)=0;          不能选,选了就是0
 *
 * 时间复杂度O(nmk) 4e7
 * 空间复杂度O(nmk) 8e7 爆了
 * 但是发现dp(i, , , )只和dp(i-1, , , )有关,可使用滚动数组
 * 空间复杂度O(mk)
*/
void HuanF() {
    int n, m, k;
    cin >> n >> m >> k;
    vector dp(2, vector(m + 1, vector(k + 1, vector<ll>(2))));
    string a, b;
    cin >> a >> b;
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    //对于任意一段选a前i个b前0个的情况都是1
    for (int i = 1, v = 1; i <= n; ++i, v ^= 1) {
        for (int j = 1; j <= m; ++j) {
            for (int c = 1; c <= k; ++c) {
                if (a[i - 1] == b[j - 1]) {
                    dp[v][j][c][0] = (dp[v ^ 1][j][c][0] + dp[v ^ 1][j][c][1]) % MOD;
                    dp[v][j][c][1] = (dp[v ^ 1][j - 1][c - 1][0] + dp[v ^ 1][j - 1][c - 1][1]
                                      + dp[v ^ 1][j - 1][c][1]) % MOD;
                } else {
                    dp[v][j][c][0] = (dp[v ^ 1][j][c][0] + dp[v ^ 1][j][c][1]) % MOD;
                    dp[v][j][c][1] = 0;
                }
            }
        }
    }
    cout << (dp[n & 1][m][k][0] + dp[n & 1][m][k][1]) % MOD;
}

signed main() {
    IOS();
    init();
    HuanF();
    return 0;
}

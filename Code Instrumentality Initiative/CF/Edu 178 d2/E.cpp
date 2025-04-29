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
constexpr int INF = 1e9 + 17;
constexpr int N = 1e5 + 7;

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

// E. Unpleasant Strings
// Link: https://codeforces.com/contest/2104/problem/E
// 思路：
// 经典 Shortest Absent Subsequence 解法
// 1. 预处理 next[i][c]：对于每个位置 i 和允许字母 c，
//    next[i][c] = 在 s[i..n-1] 中首次出现 c 的下标（若不存在则设为 n）。
// 2. DP 计算 dp[i]：表示后缀 s[i..n-1] 的最短缺失子序列长度（Shortest Absent Subsequence）。
//    边界 dp[n]=1（空串上的最短缺失子序列就是任意单字母，长度 1）；
//    转移：
//      dp[i] = min_{0≤c<k} {
//        if next[i][c] ≥ n then
//          1                      // 字母 c 在后缀根本没出现，缺失子序列可以是 “c”
//        else
//          dp[next[i][c] + 1] + 1 // 否则跳到它第一次出现之后，再接着计算
//      }
// 3. 回答每个查询 t：
//    - 利用 next 数组在 s 上做子序列匹配，找到 t 匹配结束时的位置 pos。
//    - 若匹配失败（t 不是 s 的子序列），输出 0；否则输出 dp[pos]。
void HuanF() {
    int n, k, q;
    cin >> n >> k;
    string s;
    cin >> s;


    // 1. 构造 next 数组
    // next[i][c] = s[i..].find(c) 的下标（不存在则 n）
    vector<vector<int> > next(n + 1, vector<int>(k, n));
    // 临时记录每个字母下一次出现的位置，初始化为 n（表示“不存在”）
    vector<int> nxtPos(k, n);
    // 从后向前更新：先把当前位置 i 的字符记录到 nxtPos，再拷贝到 next[i]
    for (int i = n - 1; i >= 0; --i) {
        int c = s[i] - 'a';
        nxtPos[c] = i;
        for (int j = 0; j < k; ++j) {
            next[i][j] = nxtPos[j];
        }
    }
    // next[n][*] 全为 n，表示在空后缀里找不到任何字符

    // 2. 计算 dp[i]：后缀 s[i..] 的最短缺失子序列长度
    vector<int> dp(n + 1, INF);
    dp[n] = 1; // 空串上的答案是 1
    for (int i = n - 1; i >= 0; --i) {
        int best = INF;
        for (int j = 0; j < k; ++j) {
            // 如果 c 在后缀里不出现，单字母 c 就是缺失子序列，长度 1
            // 否则缺失串由 c + 后续缺失子序列组成，长度 dp[j+1]+1
            if (next[i][j] >= n) best = 1;
            else best = std::min(dp[next[i][j] + 1] + 1, best);
        }
        dp[i] = best;
    }

    // 3. 处理 q 个查询
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string t;
        cin >> t;
        int pos = 0;
        bool match = true;
        // 在 s 上按 next 数组做子序列匹配
        for (auto &c: t) {
            auto i = c - 'a';
            if (pos > n || next[pos][i] >= n) {
                match = false; // 无法继续匹配
                break;
            }
            pos = next[pos][i] + 1;
        }
        if (!match) {
            // t 不是 s 的子序列，已经“不愉快”
            cout << "0\n";
        } else {
            // t 不是 s 的子序列，已经“不愉快”
            cout << dp[pos] << "\n";
        }
    }
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

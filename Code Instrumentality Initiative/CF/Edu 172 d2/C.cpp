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
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* 2042C
 * link: https://codeforces.com/contest/2042/problem/C
 * 思路:
 * 1. 从后向前计算后缀差值 sum，sum = (#Bob 的鱼) - (#Alice 的鱼)
 *    - 遍历 i = n-1 ↓ 1，每遇 '1' 则 sum++，遇 '0' 则 sum--
 * 2. 只有当 sum>0 时，此位置划分边界才能为 Bob 带来正向增益，收集到 vals
 * 3. 对 vals 排序后，贪心取最大的增益：每取一次，ans++（组数加一），k 减去该增益
 * 4. 初始分组数 ans=1，若用完 vals 后仍 k>0，则不可能，输出 -1；否则输出 ans
 *
 * 时间复杂度：O(n log n)  （排序主导）
 * 空间复杂度：O(n)
 */
void HuanF() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> vals;
    int sum = 0;
    for (int i = n - 1; i > 0; --i) {
        sum += s[i] == '1' ? 1 : -1;
        if (sum > 0) vals.push_back(sum);
    }
    std::sort(vals.begin(), vals.end());
    int ans = 1;
    while (k > 0 && !vals.empty()) {
        k -= vals.back();
        vals.pop_back();
        ++ans;
    }
    cout << (k > 0 ? -1 : ans) << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

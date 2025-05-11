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

/* G-消失的数字
 * link: https://codeforces.com/gym/105257/problem/G
 * 思路:
 *   1. 给定的 n 不包含 x，将其按字符串处理
 *   2. 对于每一位 d：
 *      - 若 d > x，则该位在删除所有含 x 的数字后实际映射值为 d-1
 *      - 否则保持 d 不变
 *   3. 得到的新序列即为九进制表示，按常规方法将其转换为十进制累加到 ans
 *   4. 序列中包含 0，所以最终排名为 ans + 1
 * 时间复杂度: O(len(n))
 * 空间复杂度: O(len(n))
 */
void HuanF() {
    string s;
    int x;
    cin >> s >> x;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] - '0' > x)
            s[i] = (char) (s[i] - 1);
    }
    ll ans = 0, base = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        ans += (s[i] - '0') * base;
        base *= 9;
    }
    cout << ans + 1 << "\n";
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

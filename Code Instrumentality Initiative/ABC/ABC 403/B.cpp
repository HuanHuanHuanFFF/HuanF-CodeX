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


/* ABC403 B - Four Hidden
 * link: https://atcoder.jp/contests/abc403/tasks/abc403_b
 * 思路: 逐个位置尝试匹配 若对应字符相同或为?则继续 否则跳出 若存在一次全匹配则输出Yes 否则输出No
 * 时间复杂度: O(|T| * |U|)
 * 空间复杂度: O(|T| + |U|)
 */
void HuanF() {
    string t, u;
    cin >> t >> u;
    for (int i = 0; i < t.length() - u.length() + 1; ++i) {
        for (int j = 0; j < u.length(); ++j) {
            if (t[i + j] != u[j] && t[i + j] != '?') break;
            if (j == u.length() - 1) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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

//
// Created by 幻 on 2025/6/21.
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

constexpr bool more = false;

// UNIQUE VISION Programming Contest 2025 Summer (AtCoder Beginner Contest 411) 
/* ABC411-D Conflict 2
 * link: https://atcoder.jp/contests/abc411/tasks/abc411_d
 * 标签: 倒序模拟, 状态转移, 字符串拼接
 * 思路:
 * 1 逆序遍历所有查询，仅维护当前关注对象 now (0=服务器，其它=PC编号) 和倒序构造的结果 ans
 * 2 可逆转移:
 *   - 类型 1（1 p）：正向是 “服务器 → PC p”，倒序就变成 “如果关注的是 p，就回退到服务器”（即 i=p→0）
 *   - 类型 2（2 p s）：正向是 “PC p 在尾部追加 s”，倒序就要 “如果关注的是 p，就把这段 s 放到答案前面”
 *   - 类型 3（3 p）：正向是 “PC p → 服务器”，倒序就变成 “如果关注的是服务器，就切换关注到 p”
 * 3 遍历结束后 reverse(ans.begin(), ans.end()) 并输出
 * 时间复杂度 O(Q + Σ|s|)
 * 空间复杂度 O(Σ|s|)
 */
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<char> ans;
    vector<int> op(q), num(q);
    vector<string> s(q);
    for (int i = 0; i < q; ++i) {
        cin >> op[i] >> num[i];
        if (op[i] == 2) {
            cin >> s[i];
            std::reverse(s[i].begin(), s[i].end());
        }
    }
    int now = 0;
    for (int t = q - 1; t >= 0; --t) {
        if (op[t] == 1) {
            if (now == num[t]) now = 0;
        } else if (op[t] == 2) {
            if (now == num[t]) ans.insert(ans.end(), s[t].begin(), s[t].end());
        } else {
            if (now == 0) now = num[t];
        }
    }
    std::reverse(ans.begin(), ans.end());
    for (auto &c: ans) cout << c;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

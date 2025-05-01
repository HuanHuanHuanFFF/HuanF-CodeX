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

auto AC() {
    //AC!
    //WA->AC
    //TLE/MLE->AC
}

/* ABC403 C - 403 Forbidden
 * link: https://atcoder.jp/contests/abc403/tasks/abc403_c
 * 思路: 使用 map cansee 记录用户对单个页面的查看权限,
 * 使用 set all 记录拥有所有页面权限的用户,遍历查询时按类型1插入 cansee, 类型2 插入 all,
 * 类型3 时若用户在 all 或 cansee[x] 中存在则输出 Yes 否则输出 No
 * 时间复杂度: O(Q log Q)
 * 空间复杂度: O(Q)
 */
void HuanF() {
    std::map<int, std::set<int> > cansee;
    std::set<int> all;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0, opt, x, y; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            cansee[x].insert(y);
        } else if (opt == 2) {
            cin >> x;
            all.insert(x);
        } else {
            cin >> x >> y;
            if (all.count(x) || cansee[x].count(y)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

signed main() {
    IOS();
    AC();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

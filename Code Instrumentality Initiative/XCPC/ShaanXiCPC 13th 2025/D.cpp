//
// Created by 幻 on 2025/5/13.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* D. Stock
 * link: https://codeforces.com/gym/105891/problem/D
 * 思路:
 *  1 将所有“+ x”操作存入 add, 所有“* r”操作存入 mtp
 *  2 对 add 和 mtp 均按降序排序，保证先尝试对结果影响更大的操作
 *  3 用 dfs 枚举从两组操作中交替取头的所有顺序，参数含义：
 *    ia 已用加法个数，ib 已用乘法个数，now 当前股价，all 累计股价和
 *  4 递归终止条件：ia==add.size() && ib==mtp.size()，此时更新全局最大 ans
 *  5 最后 ans 除以 n 得到平均收盘价
 * 时间复杂度 O(2^n)；空间复杂度 O(n)
 */
void HuanF() {
    int n;
    double v;
    cin >> n >> v;
    vector<double> add, mtp;
    for (int i = 0; i < n; ++i) {
        char c;
        double x;
        cin >> c >> x;
        if (c == '+') add.push_back(x);
        else mtp.push_back(x);
    }
    std::sort(add.begin(), add.end(), std::greater<>());
    std::sort(mtp.begin(), mtp.end(), std::greater<>());
    double ans = 0;
    auto dfs = [&](auto &&self, int ia, int ib, double now, double all)-> void {
        if (ia == add.size() && ib == mtp.size()) {
            ans = std::max(all, ans);
            return;
        }
        if (ia < add.size())
            self(self, ia + 1, ib, now + add[ia], all + now + add[ia]);
        if (ib < mtp.size())
            self(self, ia, ib + 1, now * mtp[ib], all + now * mtp[ib]);
    };
    dfs(dfs, 0, 0, v, 0);
    ans /= n;
    printf("%.10lf", ans);
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

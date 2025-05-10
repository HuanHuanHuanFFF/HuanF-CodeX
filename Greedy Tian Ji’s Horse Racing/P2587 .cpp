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

/* P2587-[ZJOI2008]泡泡堂
 * link: https://www.luogu.com.cn/problem/P2587
 * 思路:
 *   1 将双方实力排序升序；
 *   2 用双指针分别指向我方最弱 al、最强 ar 和对方最弱 bl、最强 br；
 *   3 当 al<=ar 时循环：
 *     3.1 若我方最弱 a[al]>对方最弱 b[bl]，则我方此场必胜，得2分，al++,bl++；
 *     3.2 否则若我方最强 a[ar]>对方最强 b[br]，则用我方最强赢对方最强，得2分，ar--,br--；
 *     3.3 否则：
 *         若 a[al]==b[br]，平局得1分；否则输不得分；
 *         al++,br-- 生成为牺牲对方最强场次；
 *   4 同理反过来交换 a,b 可得最坏情况；
 * 时间复杂度 O(n log n)  排序为主
 * 空间复杂度 O(n)  存储数组
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    auto solve = [&](vector<int> &a, vector<int> &b) {
        int al = 0, ar = n - 1, bl = 0, br = n - 1, ans = 0;
        while (al <= ar) {
            if (a[al] > b[bl]) {
                ans += 2;
                ++al, ++bl;
            } else if (a[ar] > b[br]) {
                ans += 2;
                --ar, --br;
            } else {
                ans += a[al] == b[br];
                ++al, --br;
            }
        }
        return ans;
    };

    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    cout << solve(a, b) << " " << n * 2 - solve(b, a);
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

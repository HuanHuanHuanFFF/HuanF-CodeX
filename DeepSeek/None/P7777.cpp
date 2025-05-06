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

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* P7777『JROI-2』Shelter
 * link: https://www.luogu.com.cn/contest/30241
 * 思路:
 * 1 处理特例p==0时, 单抓取无代价, 直接输出0
 * 2 处理特例n==1时, 只有一堆, 只能单抓取, 输出p
 * 3 通过边际成本比较得x=(q/p-1)/2为最优单操作次数
 * 4 令r=n-x, 若r为奇数, x++, r-- 保证剩余可成对双抓
 * 5 总代价 = p * x*(x+1)/2 + q * (r/2)
 * 时间复杂度O(1) 空间复杂度O(1)
 */
void HuanF() {
    ll n, p, q;
    cin >> n >> p >> q;
    if (p == 0) {
        cout << "0\n";
        return;
    }
    if (n == 1) {
        cout << p << "\n";
        return;
    }
    ll x = (q / p - 1) / 2;
    ll r = n - x;
    if (r & 1) ++x, --r;
    cout << (1 + x) * x / 2 * p + r / 2 * q << "\n";
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

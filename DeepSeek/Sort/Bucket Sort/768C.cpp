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

/* 768C Jon Snow and his Favourite Number
 * link: https://codeforces.com/contest/768/problem/C
 * 思路:
 * 使用长度1024的桶计数维护当前各强度出现次数
 * 用odd记录本轮是否从奇数位置开始异或
 * 遍历0~1023对每个强度根据odd和cnt计算change
 * temp[i]-=change temp[i^x]+=change 更新完后赋回cnt
 * 重复k次得到最终频率
 * 遍历cnt得到最小最大值
 * 时间复杂度 O(k*1024)
 * 空间复杂度 O(1024)
 */
// 桶排序,一种时间复杂度为O(值域)的排序
// 初学时常常忽略值域当成O(N)的,没想到真有用到的时候
void HuanF() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &y: a) cin >> y;
    vector<int> cnt(1 << 10), temp;
    for (auto &y: a) {
        ++cnt[y];
    }
    while (k-- > 0) {
        temp = cnt;
        bool odd = true; // 开始是0,1开头的时候是奇数
        for (int i = 0; i < 1 << 10; ++i) {
            int now = cnt[i];
            if (now == 0) continue;
            int change = now / 2;
            if (odd && (now & 1)) {
                // 如果当前开头的是奇数,且当前有奇数个,那么就要算now/2+1个
                ++change;
            }
            temp[i] -= change;
            temp[i ^ x] += change;
            if (now & 1) {
                // 只有加上奇数才会改变奇偶状态
                odd = !odd;
            }
        }
        cnt = temp;
    }
    ll min = INF, max = 0;
    for (ll i = 0; i < 1 << 10; ++i) {
        if (cnt[i] > 0) {
            min = std::min(min, i);
            max = std::max(max, i);
        }
    }
    cout << max << " " << min;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

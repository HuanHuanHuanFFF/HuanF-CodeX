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
constexpr int INF = 1e8 + 17;
constexpr int N = 1e6 + 7;

vector<int> cnt(N);
vector<ll> ans;

void init() {
    for (int i = 2; i < N; ++i) {
        if (!cnt[i])
            for (int j = i; j < N; j += i) {
                ++cnt[j];
            }
    }
    for (ll i = 2; i < N; ++i) {
        if (cnt[i] == 2) ans.push_back(i * i);
    }
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* E - Ringo's Favorite Numbers 3
 * link: https://atcoder.jp/contests/abc400/tasks/abc400_e
 * 思路:
 * 初始化 cnt 长度 N 全零
 * 用埃氏筛 对每个素数 p 将其所有倍数 cnt[j]++ 记录不同素因子数
 * 遍历 k=2..N-1 若 cnt[k]==2 则 ans.push_back(k*k)
 * 查询时 对 ans upper_bound(a) 找到首个大于 a 迭代器 it 取 prev(it) 即所求 最大不超 a 的 400 数 输出
 */
void HuanF() {
    ll a;
    cin >> a;
    auto it = *prev(std::upper_bound(ans.begin(), ans.end(), a));
    cout << it << "\n";
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

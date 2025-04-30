#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 998244353;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 * 题目：Problem B. 扫雷 1
 * 思路（遵循奥卡姆剃刀与模块化原则）：
 * 1. 后缀最小值模块
 *    - 预处理 sufMin[i] = min(c[i..n])，用于快速判断当前轮是否是未来所有轮中成本最低的。
 * 2. 贪心模拟模块
 *    - 维护累积扫雷币 coin，每轮开始 coin++。
 *    - 若 c[i] == sufMin[i]，说明第 i 轮成本最小，应当尽可能在此轮购买：cnt = coin / c[i]，累加到答案，coin %= c[i]。
 *
 * 证明（交换论证）：
 * 若在某轮 j（c[j] > c[i]）购买了探测器，可将购买操作“交换”到成本更低的第 i 轮，
 * 消耗相同数量的币却能在总数上不减，因此贪心选择后缀最小值轮次是最优的。
 *
 * 时间复杂度 O(n)，空间复杂度 O(n)。
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> c(n), suf_min(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    suf_min[n] = INF;
    for (int i = n - 1; i >= 0; --i) {
        suf_min[i] = std::min(c[i], suf_min[i + 1]);
    }
    int ans = 0, coin = 0;
    for (int i = 0; i < n; ++i) {
        ++coin;
        if (c[i] == suf_min[i]) {
            ans += coin / c[i];
            coin %= c[i];
        }
    }
    cout << ans;
}

signed main() {
    IOS();
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

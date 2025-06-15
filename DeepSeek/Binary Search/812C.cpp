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

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 812C – Sagheer and Nubian Market
// Link: https://codeforces.com/problemset/problem/812/C
// 思路：
// 1. 二分搜索最大可买商品数量 k（区间 [0, n]）
// 2. 判定函数 check(k):
//    - 对每个商品 i，计算购买 k 件时的总价 price[i] = a[i] + (i+1) * k
//    - 将所有 price[i] 推入小顶堆（或排序），取出前 k 个最小元素累加，
//      判断累加和是否 ≤ 总预算 s；若可行则同时更新 ans = 累加和
// 3. 最终二分结束时，l 即为最大 k，ans 为对应的最小花费
void HuanF() {
    int n, s;
    ll ans = 0;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &x: a)cin >> x;
    int l = -1, r = 1e9 + 17;

    auto check = [&](ll x) {
        if (x > n) return false;
        std::priority_queue<ll, vector<ll>, std::greater<> > heap;
        for (int i = 0; i < n; ++i) {
            heap.push(a[i] + x * (i + 1));
        }
        ll sum = 0;
        for (int i = 0; i < x; ++i) {
            sum += heap.top();
            heap.pop();
        }
        if (sum <= s) {
            ans = sum;
            return true;
        }
        return false;
    };

    while (l + 1 < r) {
        int mid = l + (r - l >> 1);
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << " " << ans;
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

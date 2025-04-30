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

// Problem M: 有效算法
// 思路：
// 1. 对于每个位置 i，操作后元素 x 必须满足 a[i] - k * b[i] ≤ x ≤ a[i] + k * b[i]。
// 2. 若所有 i 的可选区间交集非空，则存在整数 x 使得所有元素相等。
// 3. 定义函数 check(k)，判断所有区间 [a[i] - k*b[i], a[i] + k*b[i]] 是否有公共交集。
// 4. 在 k 的范围 [0, INF] 上二分，找到最小满足 check(k) 的 k 即为答案。
// 模块化：
// - check 函数负责计算区间交集。
// - HuanF 函数处理单组测试，包括读入、二分和输出。
// 证明要点：
// 对于一组闭区间，若最左端点最大值 ≤ 最右端点最小值，则区间交集非空；若交集非空，则存在整数点在交集中。
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    // check 函数：判断给定 k 时，所有区间是否有公共交集
    auto check = [&](ll k) {
        ll l = -INF, r = INF;
        for (int i = 0; i < n; ++i) {
            l = std::max(a[i] - k * b[i], l);
            r = std::min(a[i] + k * b[i], r);
        }
        return l <= r;
    };

    int l = -1, r = INF;
    while (l + 1 < r) {
        int mid = l + (r - l >> 1);
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
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

/*
2
 4
 8 3 3 5
 1 2 3 2
 5
 4 3 4 5 6
 3 1 3 1 1
 */

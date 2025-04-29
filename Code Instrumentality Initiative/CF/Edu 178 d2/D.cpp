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
constexpr int N = 6200000 + 17;
//最大 n 的上界（这里取 6.2e6+17，保证先 n 个素数都能存下）

std::bitset<N> isp;
vector<int> p;

//埃氏筛：预处理 [2..N] 内所有素数
void init() {
    isp.set();
    isp[1] = isp[0] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (isp[i]) {
            for (int j = i << 1; j <= N; j += i) {
                isp[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (isp[i]) p.push_back(i);
    }
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 2104D – Array and GCD
// Link: https://codeforces.com/contest/2104/problem/D
// 思路：
// 1. 预处理前 N 个素数 p[i]（N≈6.2e6+17），存入 p 数组。
// 2. 对每个测试用例：
//    2.1 读入 n 和数组 a，排序。
//    2.2 计算 suma = ∑a[i]，sump = ∑p[i]（i=0…n-1）：
//         - suma 表示原数组所有元素之和，也就是如果把所有数字都不断“−1”可获得的最大初始 coin 数（同时也代表可供“+1”操作的最大总花费）。
//         - sump 表示将剩下的 k=n 个元素都调整成最小的 n 个素数（2,3,5…p[n-1]）所需的总值，因为理想数组要两两互素，选最小素数可最小化总成本。
//         - 在增减操作中，“+1”花费 1 coin，“−1”获得 1 coin，整体需要的 coin = sump - suma；
//         - 为了变换可行，必须有 suma ≥ sump，故初始化时比较这两者的大小。
//    2.3 用双指针 l=0, r=n−1：
//        while (l<n && suma<sump) {
//            suma -= a[l];    // “删掉”一个最小的原值，相当于放弃这部分可用 coins
//            sump -= p[r];    // 同时去掉一个最大的素数目标，k→k−1
//            ++l; --r;
//        }
//    2.4 输出 l，即最少删去的元素个数。
// 3. 时间复杂度：筛素数 O(N log log N)，每个用例 O(n log n + n)。
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::sort(a.begin(), a.end());
    ll suma = 0, sump = 0;
    for (int i = 0; i < n; ++i) {
        suma += a[i];
        sump += p[i];
    }
    int l = 0, r = n - 1;
    while (l < n) {
        if (suma >= sump) {
            cout << l << "\n";
            return;
        }
        suma -= a[l];
        sump -= p[r];
        ++l, --r;
    }
}

signed main() {
    IOS();
    // double n = 4e5 * (std::log(4e5) + std::log(std::log(4e5)));
    // printf("%.20lf", n); //质数定理求范围
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

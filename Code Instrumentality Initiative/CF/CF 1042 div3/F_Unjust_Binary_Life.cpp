//
// Created by 幻 on 2025/8/10.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 2e5 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = true;

// Codeforces Round 1042 (Div. 3) 
/* 前缀差绝对值和计算
 * link: https://codeforces.com/contest/2131/problem/FCF 1042 di
 * 标签: 绝对值和, 排序, 双指针, 前缀和, 数学恒等
 * 思路:
 * 设 prea[i]=#0(a[1..i])-#1(a[1..i]), 设 preb[j]=#1(b[1..j])-#0(b[1..j])
 * 令 cnt0(i,j)=#0(a[1..i])+#0(b[1..j]), cnt1(i,j)=#1(a[1..i])+#1(b[1..j])
 * 目标和为 Sum f(i,j), 其中 f(i,j)=min(cnt0(i,j), cnt1(i,j))
 *
 * 推导:
 * 1) min(u,v)=(u+v-|u-v|)/2
 * 2) cnt0(i,j)+cnt1(i,j)=i+j
 * 3) cnt0(i,j)-cnt1(i,j)=(#0-#1)_a + (#0-#1)_b = prea[i] - ( #1(b)-#0(b) ) = prea[i]-preb[j]
 * 代入得:
 *    f(i,j) = (i+j)/2 - |prea[i]-preb[j]|/2
 * 两边求和:
 *    Sum f(i,j) = Sum (i+j)/2 - (1/2) * Sum |prea[i]-preb[j]|
 * 其中常数项 Sum (i+j)/2 = n^2(n+1)/2
 * 因此答案 ans = n^2(n+1)/2 - (1/2) * Sum |A_i - B_j|, A_i=prea[i], B_j=preb[j]
 *
 * 计算 Sum |A-B|:
 * 将 B 升序并预处理前缀和 sumb
 * 对每个 A_i, 设 p=# { B_j <= A_i } (用指针单调右移)
 * 则 Sum_j |A_i - B_j| = A_i*p - sumb[p] + (sumb[n]-sumb[p]) - A_i*(n-p)
 * 累加即得 absSum; 最终 ans = base - absSum/2, base=n^2(n+1)/2
 *
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    ll n;
    string a, b;
    cin >> n >> a >> b;
    vector<ll> prea(n + 1), preb(n + 1);
    ll cnt0 = 0, cnt1 = 0, ans = n * n * (n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '0') ++cnt0;
        else ++cnt1;
        prea[i + 1] = cnt0 - cnt1;
    }
    cnt0 = cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == '0') ++cnt0;
        else ++cnt1;
        preb[i + 1] = cnt1 - cnt0;
    }
    std::sort(prea.begin() + 1, prea.end());
    std::sort(preb.begin() + 1, preb.end());
    vector<ll> sumb(n + 1);
    for (int i = 1; i <= n; ++i) sumb[i] = sumb[i - 1] + preb[i];
    ll p = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        while (p < n && prea[i] >= preb[p + 1]) ++p;
        sum += p * prea[i] - sumb[p] + sumb[n] - sumb[p] - prea[i] * (n - p);
    }
    ans -= sum / 2;
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/6/8.
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
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = true;

// Codeforces Round 988 (Div. 3) 
/* 2037E
 * link: https://codeforces.com/contest/2037/problem/E
 * 标签: 交互、前缀统计、差分
 * 思路:
 * 1 查询前缀 F(r)=f(1,r) 直到首次 F(R)>0 的位置 R
 * 2 计算 Z = F(R) - F(R-1) —— 即前缀中 0 的数量
 * 3 令 L = (R-1) - Z，则 s[1..L]=1，s[L+1..R-1]=0，s[R]=1
 * 4 对 i=R+1..n，若 Δ(i)=F(i)-F(i-1)>0 则 s[i]=1，否则 s[i]=0
 * 5 共做 ≤n 次查询，线性重建整个字符串
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> f(n + 1);
    vector<char> ans(n + 1);
    ll res = 0, r = 2;
    while (!res && r <= n) {
        cout << "? " << 1 << " " << r << endl;
        cin >> res;
        f[r] = res;
        ++r;
    }
    if (r == n + 1 && res == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    for (int i = n; i >= r; --i) {
        cout << "? " << 1 << " " << i << endl;
        cin >> res;
        f[i] = res;
    }
    for (int i = n; i >= r - 1; --i) {
        if (f[i] > f[i - 1]) ans[i] = '1';
        else ans[i] = '0';
    }
    int pre = r - 2 - f[r - 1];
    for (int i = 1; i <= pre; ++i) {
        ans[i] = '1';
    }
    for (int i = pre + 1; i < r - 1; ++i) {
        ans[i] = '0';
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) cout << ans[i];
    cout << endl;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

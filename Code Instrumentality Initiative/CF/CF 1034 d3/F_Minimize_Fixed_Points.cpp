//
// Created by 幻 on 2025/7/1.
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
constexpr int N = 1e5 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> factor(N);

void init() {
    IOS();
    factor[2] = 2;
    for (int i = 3; i < N; ++i) {
        int x = i;
        int maxp = 2;
        while (x % 2 == 0) x >>= 1;
        for (int j = 3; j * j <= x; j += 2) {
            while (x % j == 0) {
                maxp = j;
                x /= j;
            }
        }
        if (x > 1) maxp = x;
        factor[i] = maxp;
    }
}

constexpr bool more = true;

// Codeforces Round 1034 (Div. 3) 
// F. Minimize Fixed Points
// https://codeforces.com/contest/2123/problem/F
// 考虑一种构造方式使固定点最小
// 因为是gcd,首先想到按最小质因数分组,组内循环位移构造
// 但是6既是2又是3的倍数,有点麻烦
// 于是想到按最大质因数分组
// 2,4,8...3,6,9,27...5,10,15,20....
// 这样分组就不会冲突了
// 预处理最大质因数O(N^1.5),分组构造O(NlogN)
void HuanF() {
    int n;
    cin >> n;
    std::map<int, vector<int> > mp;
    for (int i = 2; i <= n; ++i) {
        mp[factor[i]].emplace_back(i);
    }
    vector<int> ans(n + 1);
    ans[1] = 1;
    for (auto &[x,y]: mp) {
        for (int i = 0; i < y.size() - 1; ++i) {
            ans[y[i]] = y[i + 1];
        }
        ans[y.back()] = y.front();
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

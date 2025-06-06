#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

struct MAT {
    int n, m;
    ll ele[3][3]{};

    MAT() {
        n = 3, m = 3;
    }

    //重载运算符,方便使用
    ll &operator()(int x, int y) {
        return ele[x][y];
    }

    MAT operator *(const MAT &b) const {
        MAT ans;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= b.m; ++j)
                for (int k = 1; k <= m; ++k)
                    ans(i, j) = (ans(i, j) + ele[i][k] * b.ele[k][j] % MOD) % MOD;
        return ans;
    }
};

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 * https://codeforces.com/gym/105184
 * J Iris' Food
 *
 * 贪心
 * 计算的时候我们需要把原来的数字*10再加上现在的数字
 * 可以想到使用矩阵加速计算
 * 由[a,b]得到[10a+b,b]
 * 所以中间矩阵为
 * [10,0]
 * [1 ,1]
 */

void AC() {
    int m;
    cin >> m;
    vector<int> cnt(10);
    MAT ans, base;
    for (auto &x: cnt) cin >> x;
    if (m == 1 && cnt[0] > 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i < 10; ++i) {
        if (cnt[i]) {
            ans(1, 1) = i;
            --m;
            --cnt[i];
            break;
        }
    }
    for (int i = 0; i < 10 && m > 0; ++i) {
        if (cnt[i]) {
            ans(1, 2) = i;
            int k = min(cnt[i], m);
            cnt[i] -= k;
            m -= k;
            base(1, 1) = 10;
            base(1, 0) = 0;
            base(2, 1) = base(2, 2) = 1;
            while (k) {
                if (k & 1) ans = ans * base;
                base = base * base;
                k >>= 1;
            }
        }
    }
    cout << ans(1, 1) << "\n";
}

// 3
// 3 1 0 0 0 3 0 0 0 0 0
// 1 2 0 0 0 0 0 0 0 0 0
// 4 0 1 1 1 3 0 0 0 0 0

signed main() {
    IOS();
    int T;
    cin >> T;
    while (T-- > 0)
        AC();
}

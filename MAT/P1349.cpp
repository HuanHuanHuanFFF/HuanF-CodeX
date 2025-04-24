#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int MOD;

struct MAT {
    int n, m;
    vector<vector<ll> > ele;

    MAT() {
    }

    MAT(int n, int m): n(n), m(m) {
        ele = vector(n + 1, vector<ll>(m + 1));
    }

    MAT(const MAT &other): n(other.n), m(other.m), ele(other.ele) {
    }

    //重载运算符,方便使用
    ll &operator()(int x, int y) {
        return ele[x][y];
    }

    //打印矩阵
    void print() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                cout << ele[i][j] << " ";
            cout << "\n";
        }
    }

    //返回大小为n*n的单位矩阵
    static MAT identity(int n) {
        MAT res(n, n);
        for (int i = 1; i <= n; ++i) {
            res(i, i) = 1;
        }
        return res;
    }

    MAT operator *(const MAT &b) const {
        MAT ans(n, b.m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= b.m; ++j)
                for (int k = 1; k <= b.m; ++k)
                    ans(i, j) = (ans(i, j) + ele[i][k] * b.ele[k][j] % MOD) % MOD;
        return ans;
    }
};

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// https://www.luogu.com.cn/problem/P1349
// 非常简单矩阵应用 //不做解释
signed main() {
    IOS();
    ll p, q, a, b, n;
    cin >> p >> q >> a >> b >> n >> MOD;
    MAT ans(1, 2), base(2, 2);
    //通过逆推算出base矩阵
    base(1, 1) = p, base(2, 1) = q, base(1, 2) = 1;
    ans(1, 1) = b, ans(1, 2) = a;
    if (n < 2) {
        if (n == 1) cout << a;
        else cout << b;
        return 0;
    }
    n -= 2; //记得-2,因为第一次算完是第三项
    while (n) {
        if (n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    cout << ans(1, 1);
}

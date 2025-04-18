#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

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
        assert(m == b.n);
        MAT ans(n, b.m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= b.m; ++j)
                for (int k = 1; k <= m; ++k)
                    ans(i, j) = (ans(i, j) + ele[i][k] * b.ele[k][j] % MOD) % MOD;
        return ans;
    }

    MAT operator +(const MAT &b) const {
        MAT ans(n, m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                ans(i, j) = (ele[i][j] + b.ele[i][j]) % MOD;
        return ans;
    }

    MAT operator -(const MAT &b) const {
        MAT ans(n, m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                ans(i, j) = ((ele[i][j] - b.ele[i][j]) % MOD + MOD) % MOD;
        return ans;
    }
};

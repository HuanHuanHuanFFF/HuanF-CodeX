//
// Created by 幻 on 2025/5/15.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

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

    // 快速幂
    static ll mod_pow(ll x, ll y) {
        ll res = 1;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    // 乘法逆元（MOD 为质数）
    static ll mod_inv(ll x) {
        return mod_pow(x, MOD - 2);
    }

    /* ---------- 原地求逆：成功返回 true，失败返回 false ---------- */
    bool invert() {
        if (n != m) return false; // 只处理方阵
        int sz = n;

        // 构造增广矩阵 [A | I]
        vector<vector<ll> > aug(sz + 1, vector<ll>(2 * sz + 1));
        for (int i = 1; i <= sz; ++i) {
            for (int j = 1; j <= sz; ++j) {
                aug[i][j] = ele[i][j];
                aug[i][sz + j] = (i == j); // 单位矩阵
            }
        }

        // 高斯-约旦消元
        for (int col = 1, row = 1; col <= sz; ++col, ++row) {
            int pivot = -1;
            for (int r = row; r <= sz; ++r)
                if (aug[r][col]) {
                    pivot = r;
                    break;
                }
            if (pivot == -1) return false; // 找不到主元 → 奇异矩阵

            if (pivot != row)
                for (int c = 1; c <= 2 * sz; ++c)
                    swap(aug[row][c], aug[pivot][c]);

            ll inv_p = mod_inv(aug[row][col]);
            for (int c = 1; c <= 2 * sz; ++c)
                aug[row][c] = aug[row][c] * inv_p % MOD;

            for (int r = 1; r <= sz; ++r)
                if (r != row && aug[r][col]) {
                    ll factor = aug[r][col];
                    for (int c = 1; c <= 2 * sz; ++c) {
                        aug[r][c] = (aug[r][c] - factor * aug[row][c]) % MOD;
                        if (aug[r][c] < 0) aug[r][c] += MOD;
                    }
                }
        }

        // 把右半部分复制回 ele，完成原地替换
        for (int i = 1; i <= sz; ++i)
            for (int j = 1; j <= sz; ++j)
                ele[i][j] = aug[i][sz + j];

        return true;
    }
};


void HuanF() {
    int n;
    cin >> n;
    MAT ans(n, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> ans(i, j);
        }
    }
    if (ans.invert()) {
        ans.print();
    } else {
        cout << "No Solution";
    }

}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

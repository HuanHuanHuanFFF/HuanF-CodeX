#include <bits/stdc++.h>
// #define x first
// #define y second
using namespace std;
using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
using PIII = pair<int, PII>;
constexpr int MOD = 2017;
constexpr ll INF = 1e12 + 17;
constexpr int N = 1e6 + 7;

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
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= b.m; ++j)
                for (int k = 0; k <= m; ++k)
                    ans(i, j) = (ans(i, j) + ele[i][k] * b.ele[k][j] % MOD) % MOD;
        return ans;
    }
};

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* P3758-TJOI2017-可乐
 * link: https://www.luogu.com.cn/problem/P3758
 * 思路:
 *  1 构造大小为(n+1)x(n+1)的邻接矩阵A
 *  2 对于每条道路u-v设置A(u,v)=A(v,u)=1
 *  3 对于每个城市i设置自环A(i,i)=1表示停在原地
 *  4 构造节点0表示自爆状态并设置A(0,0)=1保证自爆后不可逆
 *  5 对于每个城市i设置A(i,0)=1表示随时自爆
 *  6 快速幂计算A^t
 *  7 答案为从1到0..n的路径数之和sum(A^t(1,i)) mod 2017
 * 时间复杂度O(n^3 log t) 空间复杂度O(n^2)
 */
void HuanF() {
    ll n, m, t, an = 0;
    cin >> n >> m;
    MAT a(n, n), ans = MAT::identity(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a(x, y) = 1;
        a(y, x) = 1;
    }
    a(0, 0) = 1;
    for (int i = 1; i <= n; ++i) {
        a(i, 0) = 1;
        a(i, i) = 1;
    }
    cin >> t;
    while (t) {
        if (t & 1) ans = ans * a;
        a = a * a;
        t >>= 1;
    }
    for (int i = 0; i <= n; ++i) {
        an = (an + ans(1, i)) % MOD;
    }
    cout << an;
}

int main() {
    init();
    HuanF();
}

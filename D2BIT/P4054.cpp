#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

using ll = long long;
constexpr int MOD = 1e9 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

//二维树状数组
template<typename T>
struct D2BIT {
    int n, m;
    vector<vector<T> > t;

    explicit D2BIT(int n, int m): n(n), m(m), t(vector(n + 1, vector<T>(m + 1))) {
    }

    int lowbit(int x) { return x & -x; }

    //单点修改 O(logN*logM)
    void add(int x, int y, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                t[i][j] += val;
            }
        }
    }

    //查询前缀和 O(logN*logM)
    ll pre_sum(int x, int y) {
        ll ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                ans += t[i][j];
            }
        }
        return ans;
    }

    //查询区间和
    ll query(int sx, int sy, int ex, int ey) {
        return pre_sum(ex, ey)
               - pre_sum(sx - 1, ey)
               - pre_sum(ex, sy - 1)
               + pre_sum(sx - 1, sy - 1);
    }
};

/*
 * https://www.luogu.com.cn/problem/P4054'
 * 开始还想该怎么做
 * 一看数据,c怎么才100?
 * 那我开100个二维树状数组分别计算不就好了
 * 9e4*100=9e6  才9e6而已,空间完全够的呀
 */
signed main() {
    IOS();
    int n, m, q;
    cin >> n >> m;
    vector<D2BIT<int> > bits(100, D2BIT<int>(n, m));
    vector g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, c; j <= m; ++j) {
            cin >> c;
            --c;
            //标记并计入数量
            g[i][j] = c;
            bits[c].add(i, j, 1);
        }
    }
    cin >> q;
    for (int i = 0, opt, a1, a2, b1, b2, c; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            cin >> a1 >> b1 >> c;
            --c;
            //擦除旧的,加上新的
            bits[c].add(a1, b1, 1);
            bits[g[a1][b1]].add(a1, b1, -1);
            g[a1][b1] = c;
        } else {
            cin >> a1 >> a2 >> b1 >> b2 >> c;
            --c;
            //直接查
            cout << bits[c].query(a1, b1, a2, b2) << "\n";
        }
    }
    return 0;
}

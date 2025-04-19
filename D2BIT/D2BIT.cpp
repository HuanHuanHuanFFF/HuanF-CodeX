#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
    ll query(int start_x, int start_y, int end_x, int end_y) {
        return pre_sum(start_x - 1, start_y - 1) + pre_sum(end_x, end_y)
               - pre_sum(start_x - 1, end_y) - pre_sum(start_x, end_y - 1);
    }
};

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

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/**
 * https://www.luogu.com.cn/problem/P4514
 * 这题卡空间,只有最大的d4需要开long long,其他开int,所以引入了泛型
 */
signed main() {
    IOS();
    string opt;
    int n, m;
    cin >> opt;
    cin >> n >> m;
    D2BIT<int> d1(n, m), d2(n, m), d3(n, m);
    D2BIT<ll> d4(n, m);

    auto add = [&](int a, int b, int k) {
        d1.add(a, b, k);
        d2.add(a, b, k * a);
        d3.add(a, b, k * b);
        d4.add(a, b, k * a * b);
    };

    auto query_ans = [&](int x, int y) {
        if (x < 1 || y < 1) return 0LL;
        ll sum_d1 = d1.pre_sum(x, y);
        ll sum_d2 = d2.pre_sum(x, y);
        ll sum_d3 = d3.pre_sum(x, y);
        ll sum_d4 = d4.pre_sum(x, y);
        return sum_d1 * (x * y + x + y + 1) - sum_d2 * (y + 1) - sum_d3 * (x + 1) + sum_d4;
    };

    while (cin >> opt) {
        int a, b, c, d, del;
        cin >> a >> b >> c >> d;
        if (opt == "L") {
            cin >> del;
            add(a, b, del);
            if (d + 1 <= m) add(a, d + 1, -del);
            if (c + 1 <= n) add(c + 1, b, -del);
            if (c + 1 <= n && d + 1 <= m) add(c + 1, d + 1, del);
        } else {
            ll res = query_ans(c, d);
            if (a - 1 >= 1) res -= query_ans(a - 1, d);
            if (b - 1 >= 1) res -= query_ans(c, b - 1);
            if (a - 1 >= 1 && b - 1 >= 1) res += query_ans(a - 1, b - 1);
            cout << res << "\n";
        }
    }
}

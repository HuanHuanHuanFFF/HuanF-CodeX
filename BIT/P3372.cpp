#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    int n;
    vector<ll> t;

    explicit BIT(int n): n(n), t(vector<ll>(n + 1)) {
    }

    int lowbit(int x) { return x & -x; }

    //单点修改
    void add(int x, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            t[i] += val;
        }
    }

    //查询前缀和
    ll pre_sum(int x) {
        ll ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += t[i];
        }
        return ans;
    }

    //查询区间和
    ll query(int l, int r) {
        return pre_sum(r) - pre_sum(l - 1);
    }
};

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

signed main() {
    IOS();
    int n, m;
    cin >> n >> m;
    BIT d1(n), d2(n);
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        d1.add(i, x);
        d1.add(i + 1, -x);
        d2.add(i, (i - 1) * x);
        d2.add(i + 1, -i * x);
    }
    for (int i = 0; i < m; ++i) {
        ll opt, x, y, k;
        cin >> opt >> x >> y;
        if (opt == 1) {
            cin >> k;
            d1.add(x, k);
            d1.add(y + 1, -k);
            d2.add(x, (x - 1) * k);
            d2.add(y + 1, -y * k);
        } else cout << d1.pre_sum(y) * y - d1.pre_sum(x - 1) * (x - 1) - d2.pre_sum(y) + d2.pre_sum(x - 1) << "\n";
    }
    return 0;
}

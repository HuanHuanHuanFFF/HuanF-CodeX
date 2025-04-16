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
    vector<ll> arr(n + 1);
    BIT bit(n);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; ++i) {
        int opt, x, y, k;
        cin >> opt >> x;
        if (opt == 1) {
            cin >> y >> k;
            bit.add(x, k);
            bit.add(y + 1, -k);
        } else cout << arr[x] + bit.pre_sum(x) << "\n";
    }
}
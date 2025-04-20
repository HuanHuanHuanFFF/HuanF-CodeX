#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct BIT {
    int n;
    vector<T> t;

    explicit BIT(int n): n(n), t(vector<T>(n + 1)) {
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

    //查询闭区间和
    ll query(int l, int r) {
        return pre_sum(r) - pre_sum(l - 1);
    }
};

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 *
 */
signed main() {
    IOS();
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    vector<int> b = a;
    sort(b.begin(), b.end());
    //同一个值必须映射到同一个位置,所以必须去重
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();
    //建立映射
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
    BIT<int> bit_L(m), bit_R(m);
    for (auto &ind: a) bit_R.add(ind, 1);
    for (int i = 0; i < n; ++i) {
        bit_R.add(a[i], -1);
        ans += bit_L.pre_sum(a[i] - 1) * bit_R.query(a[i] + 1, m);
        bit_L.add(a[i], 1);
    }
    cout << ans;
}

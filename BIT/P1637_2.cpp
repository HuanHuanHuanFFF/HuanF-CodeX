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
 * https://www.luogu.com.cn/problem/P1637
 * 使用递推关系,另一种做法使用乘法原理
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
    //建立映射
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
    int m = b.size();
    BIT<int> t1(m), t2(m); //到当前位置,上升1元组数量,上升2元祖数量
    for (auto &ind: a) {
        ans += t2.pre_sum(ind - 1);
        t1.add(ind, 1);
        t2.add(ind, t1.pre_sum(ind - 1));
    }
    cout << ans;
}

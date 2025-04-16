#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e8 - 3;

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

/* https://www.luogu.com.cn/problem/P1966
 * [NOIP 2013 提高组] 火柴排队
 * 排序两个数组,记录排序后数组b的下标对应数组a的下标,然后计算按a排序一一对应下标的逆序对
*/
signed main() {
    IOS();
    int n;
    ll ans = 0;
    cin >> n;
    BIT bit(n);
    vector<PII> a(n), b(n);
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x;
        a[i].y = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].x;
        b[i].y = i + 1;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        p[b[i].y] = a[i].y;
    }
    for (int i = 1; i <= n; ++i) {
        ans = (ans + bit.query(p[i] + 1, n)) % MOD;
        bit.add(p[i], 1);
    }
    cout << ans;
}

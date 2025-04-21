#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

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
 * https://www.acwing.com/problem/content/243/
*/
void HuanF() {
    int n;
    ll ansA = 0, ansV = 0;
    cin >> n;
    vector<int> h(n);
    for (auto &x: h) cin >> x;
    vector<int> a = h;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();
    for (int i = 0; i < n; ++i) {
        h[i] = lower_bound(a.begin(), a.end(), h[i]) - a.begin() + 1;
    }
    BIT<int> right(m), left(m);
    //枚举时相对当前位置  右边插入的 和 左边插入的
    for (auto &ind: h) right.add(ind, 1);
    for (ll i = 0; i < n; ++i) {
        //从小到大枚举
        right.add(h[i], -1); //删除之前右边插入的当前位置
        ll small_l = left.pre_sum(h[i] - 1); //左边小的就是已经插入了比当前小的
        ll big_l = i - small_l; //那么其他的就是左边大的
        ll small_r = right.pre_sum(h[i] - 1); //右边插入比当前小的
        ll big_r = n - 1 - i - small_r; //同理
        ansA += small_l * small_r;
        ansV += big_l * big_r;
        //乘法原理
        left.add(h[i], +1); //在左边加入当前位置
    }
    cout << ansV << " " << ansA;
}

signed main() {
    IOS();
    init();
    HuanF();
    return 0;
}

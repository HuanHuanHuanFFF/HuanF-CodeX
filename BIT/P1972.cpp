#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

using ll = long long;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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

/*
 * https://www.luogu.com.cn/problem/P1972
 * 不看题解我真想不到这么做
 *
 * 对于每次l,r查询,相同的数字只有最右边的可以计入统计
 * 那么按r从小到大排序,从1开始遍历,每次在当前位置加1代表这个数
 * 然后删除上一次加的1
 * 每次遇到r的时候就统计次数
 */
void HuanF() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    BIT<int> bit(n);
    std::unordered_map<int, int> last(n << 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    vector<std::tuple<int, int, int> > ask(m);
    vector<int> ans(m);
    int cnt = 0;
    for (auto &[r,l,p]: ask) {
        cin >> l >> r;
        p = cnt++;
        //回答要按输入顺序
    }
    std::sort(ask.begin(), ask.end());
    cnt = 0;
    for (int i = 1; i <= n && cnt < m; ++i) {
        bit.add(i, 1); //计入当前的数
        if (last[a[i]] != 0) //如果有上一次记录就删除
            bit.add(last[a[i]], -1);
        last[a[i]] = i; //记录最后出现次数
        while (cnt < m && i == std::get<0>(ask[cnt])) {
            auto [r,l,p] = ask[cnt++];
            ans[p] = bit.query(l, r);
        }
    }
    for (auto &x: ans) cout << x << "\n";
}

signed main() {
    IOS();
    HuanF();
    return 0;
}

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;

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
 * https://www.luogu.com.cn/problem/P3605
 * 查逆序对,很容易想到树状数组加dfs
 * 不过如何让之前的结果不影响后面的结果我想了很久😭
 * 看了题解才发现开始减一下就好了,这么简单😭
 */
signed main() {
    IOS();

    int n;
    cin >> n;
    vector<int> p(n), rank(n + 1), ans(n + 1);
    vector children(n + 1, vector<int>());
    BIT<int> bit(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        rank[i + 1] = p[i];
    }
    std::sort(p.begin(), p.end());
    for (int i = 1; i <= n; ++i) {
        //得到每个人能力值在公司的排名
        rank[i] = std::lower_bound(p.begin(), p.end(), rank[i]) - p.begin() + 1;
    }
    for (int i = 2, fa; i <= n; ++i) {
        cin >> fa;
        children[fa].push_back(i);
    }

    auto dfs = [&](auto &self, int x)-> void {
        //后面再加的时候会算重,先减去,后面再加上就去重了,dfs完左子树就不会影响右子树了
        ans[x] -= bit.query(rank[x] + 1, n);
        for (auto &y: children[x]) {
            self(self, y);
        }
        ans[x] += bit.query(rank[x] + 1, n);
        bit.add(rank[x], 1);
    };

    dfs(dfs, 1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";

    return 0;
}

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::string;

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
 * 前置知识P1908逆序对
 * https://www.luogu.com.cn/problem/P3586
 * 题解请看markdown
 *  关键思想：
 *  1. 先离线收集所有出现的数值 (所有 a 与所有 s)，加 0 后排序去重。
 *  2. 两棵 BIT（Fenwick）按“值域坐标”维护
 *        - inv：每个值出现的次数      —— 用来算  k = arr[i]>=s的个数
 *        - pre：每个值出现后的总和    —— 用来算  sum = arr中小于s的和
 *  3. 判定式   sum ≥ (c-k)·s
 *  4. 更新即「删旧 + 插新」，删除旧值需要知道它现在在哪个坐标，
 *     所以用 last_rank[x] 记录第 x 个位置当前值的坐标。
 */
signed main() {
    IOS();
    int n, m;
    cin >> n >> m;
    vector<std::tuple<string, int, int> > opt(m);

    /* 1. 读操作，顺便收集 y 的值域 */
    for (auto &[s,x,y]: opt) {
        cin >> s >> x >> y;
    }

    /* 2. 值域压缩 */
    vector<int> a(opt.size());
    int cnt = 0;
    for (auto &[s,x,y]: opt) a[cnt++] = y;

    /* 3. 构造 rank[] = opt[i].y 的压缩坐标 */
    vector<int> rank = a;
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    m = a.size();

    /* 4. 两棵 BIT */
    BIT<ll> inv(m), pre(m);
    for (int i = 0; i < opt.size(); ++i) {
        rank[i] = std::lower_bound(a.begin(), a.end(), rank[i]) - a.begin() + 1;
    }
    cnt = 0;

    /* 5. 维护原序列状态 */
    vector<int> arr(n + 1), last_rank(n + 1);

    /* 6. 主循环执行全部操作 */
    for (auto &[s,x,y]: opt) {
        if (s == "U") {
            if (last_rank[x] != 0) {
                /* (1) 删除旧值对两棵 BIT 的影响 */
                inv.add(last_rank[x], -1);
                pre.add(last_rank[x], -arr[x]);
            }
            /* (2) 插入新值 */
            pre.add(rank[cnt], y);
            inv.add(rank[cnt], +1);
            last_rank[x] = rank[cnt];
            arr[x] = y;
        } else {
            ll k = inv.query(rank[cnt], m); // ≥ s 的个数
            ll sum = pre.pre_sum(rank[cnt] - 1); // < s 的总和
            if ((-k + x) * y <= sum) //判定
                cout << "TAK\n";
            else cout << "NIE\n";
        }
        ++cnt;
    }

    return 0;
}

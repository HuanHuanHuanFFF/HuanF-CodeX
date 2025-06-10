//
// Created by 幻 on 2025/6/10.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = false;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> st;
    function<T(T &, T &)> merge;
    T id_val;

    SegmentTree(int _n,
                function<T(T &, T &)> _merge,
                T _id_val)
        : n(_n), merge(_merge), id_val(_id_val) {
        st.assign(4 * (n + 1), id_val);
    }

    // 构建：输入数组 a[1..n]
    void build(const vector<T> &a) {
        build(1, 1, n, a);
    }

    // 单点更新：将位置 pos 的值设为 v
    void update(int pos, const T &v) {
        update(1, 1, n, pos, v);
    }

    // 区间查询：[L, R]
    T query(int L, int R) {
        return query(1, 1, n, L, R);
    }

private:
    void build(int p, int l, int r, const vector<T> &a) {
        if (l == r) {
            st[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    void update(int p, int l, int r, int pos, const T &v) {
        if (l == r) {
            st[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) update(p << 1, l, m, pos, v);
        else update(p << 1 | 1, m + 1, r, pos, v);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    T query(int p, int l, int r, int L, int R) {
        if (r < L || R < l) return id_val;
        if (L <= l && r <= R) return st[p];
        int m = (l + r) >> 1;
        T left = query(p << 1, l, m, L, R);
        T right = query(p << 1 | 1, m + 1, r, L, R);
        return merge(left, right);
    }
};


// P1886 滑动窗口 /【模板】单调队列
// https://www.luogu.com.cn/problem/P1886
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (auto &x: a | views::drop(1)) cin >> x;
    auto maxx = [](int &x, int &y) { return max(x, y); };
    auto minn = [](int &x, int &y) { return min(x, y); };
    SegmentTree<int> seg_max(n, maxx, -INF);
    SegmentTree<int> seg_min(n, minn, INF);
    seg_max.build(a);
    seg_min.build(a);
    for (int i = k; i <= n; ++i) {
        cout << seg_min.query(i - k + 1, i) << " ";
    }
    cout << "\n";
    for (int i = k; i <= n; ++i) {
        cout << seg_max.query(i - k + 1, i) << " ";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

//
// Created by 幻 on 2025/8/4.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

// 自定义功能1-idx线段树
template<typename T>
struct SegmentTree {
    int n;
    vector<T> t;
    function<T(T &, T &)> merge;
    T init_v;

    SegmentTree(int n, function<T(T &, T &)> merge, T init_v)
        : n(n), merge(merge), init_v(init_v) {
        t.assign(4 * (n + 1), init_v);
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
            t[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        t[p] = merge(t[p << 1], t[p << 1 | 1]);
    }

    void update(int p, int l, int r, int pos, const T &v) {
        if (l == r) {
            t[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) update(p << 1, l, m, pos, v);
        else update(p << 1 | 1, m + 1, r, pos, v);
        t[p] = merge(t[p << 1], t[p << 1 | 1]);
    }

    T query(int p, int l, int r, int L, int R) {
        if (r < L || R < l) return init_v;
        if (L <= l && r <= R) return t[p];
        int m = (l + r) >> 1;
        T left = query(p << 1, l, m, L, R);
        T right = query(p << 1 | 1, m + 1, r, L, R);
        return merge(left, right);
    }
};

struct node {
    char lc, rc;
    int llen, rlen, ans;
    bool con;

    node(): lc('.'), rc('.'), llen(0), rlen(0), ans(0), con(true) {
    }

    node(char lc, int llen, char rc, int rlen, int ans, bool con)
        : lc(lc),
          rc(rc),
          llen(llen),
          rlen(rlen),
          ans(ans),
          con(con) {
    }
};

auto merge_ = [](node &a, node &b) {
    if (a.lc == '.') return b;
    if (b.lc == '.') return a;
    node res;
    res.ans = max(a.ans, b.ans);
    if (a.con && b.con) {
        if (a.lc == b.lc) {
            res.lc = a.lc;
            res.llen = a.llen + b.llen;
            res.con = true;
        } else {
            res.lc = a.lc;
            res.llen = a.llen;
            res.rc = b.lc;
            res.rlen = b.llen;
            res.con = false;
        }
    } else if (a.con) {
        res.con = false;
        if (a.lc == b.lc) {
            res.lc = a.lc;
            res.llen = a.llen + b.llen;
        } else {
            res.lc = a.lc;
            res.llen = a.llen;
        }
        res.rc = b.rc;
        res.rlen = b.rlen;
    } else if (b.con) {
        res.con = false;
        res.lc = a.lc;
        res.llen = a.llen;
        if (a.rc == b.lc) {
            res.rc = b.lc;
            res.rlen = b.llen + a.rlen;
        } else {
            res.rc = b.lc;
            res.rlen = b.llen;
        }
    } else {
        res.con = false;
        res.lc = a.lc;
        res.llen = a.llen;
        res.rc = b.rc;
        res.rlen = b.rlen;
        if (a.rc == b.lc) res.ans = max(res.ans, a.rlen + b.llen);
    }
    res.ans = max({res.ans, res.llen, res.rlen});
    return res;
};


constexpr bool more = false;

// Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415) 
/* JPRS#2-ABC415-F
 * link: https://atcoder.jp/contests/abc415/tasks/abc415_f
 * 标签: 线段树, 区间合并, 字符串
 * 思路:
 * 1 定义 node 存储区间左缀字符 lc 及长度 llen, 右缀字符 rc 及长度 rlen, 全区间同字符标志 con, 最大连续长度 ans
 * 2 叶节点初始化为单字符状态 node(c,1,'.',0,1,true)
 * 3 合并 merge_(left,right):
 *   - 若 left.lc=='.' 返回 right, 若 right.lc=='.' 返回 left
 *   - res.ans = max(left.ans, right.ans)
 *   - 若 left.rc == right.lc 则跨界长度 left.rlen+right.llen 更新 res.ans
 *   - 更新 res.lc, res.llen: 若 left.con 且 left.lc==right.lc 则 llen累加, 否则继承 left
 *   - 更新 res.rc, res.rlen 同理
 *   - res.con = left.con && right.con && left.lc==right.lc
 *   - 最终 res.ans = max(res.ans, res.llen, res.rlen)
 * 4 用 SegmentTree<node> 封装 merge_ 与 init_v 支持单点更新与区间查询
 * 时间复杂度 O((N+Q)logN)
 * 空间复杂度 O(N)
 */
void HuanF() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    SegmentTree<node> seg(n, merge_, node());
    vector<node> a(n + 1);
    for (int i = 0; i < n; ++i) {
        a[i + 1] = node(s[i], 1, '.', 0, 1, true);
    }
    seg.build(a);
    for (int i = 0, opt; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            int x;
            char y;
            cin >> x >> y;
            seg.update(x, node{y, 1, '.', 0, 1, true});
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r).ans << "\n";
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

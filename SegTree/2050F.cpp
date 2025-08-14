//
// Created by 幻 on 2025/6/29.
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

namespace seg {
    using std::vector;

    template<typename T, auto merge, auto e>
    struct SegmentTree {
        int n;
        vector<T> t;

        // 自定义功能1-idx线段树
        SegmentTree(int n): n(n) { t.assign(4 * (n + 1) + 5, e()); }

        // 构建：输入数组 a[1..n]
        void build(const vector<T> &a) { build(1, 1, n, a); }

        // 单点更新：将位置 pos 的值设为 v
        void update(int pos, const T &v) { update(1, 1, n, pos, v); }

        // 区间查询：[L, R]
        T query(int l, int r) { return query(1, 1, n, l, r); }

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
            if (r < L || R < l) return e();
            if (L <= l && r <= R) return t[p];
            int m = (l + r) >> 1;
            T left = query(p << 1, l, m, L, R);
            T right = query(p << 1 | 1, m + 1, r, L, R);
            return merge(left, right);
        }
    };
}


constexpr bool more = true;

// Codeforces Round 991 (Div. 3)
/* F-Maximum modulo equality
 * link: https://codeforces.com/problemset/problem/2050/F
 * 标签: 差分 数学 线段树 区间GCD
 * 思路:
 *   结论推导——“两数同余 ⇒ 差值被模整除”:
 *       x=a*m+c    y=b*m+c
 *       |x-y| ≡ 0 (mod m)
 *   区间 [l,r] 内若要 a_l≡a_{l+1}≡…≡a_r (mod m)，则对每个相邻对都有
 *       m | |a_i − a_{i+1}|  (∀ i∈[l,r−1])
 *   因此合法 m 必同时整除所有相邻差，取最大值即
 *       m* = gcd(|a_l−a_{l+1}|,…,|a_{r−1}−a_r|)。
 *   若区间元素全相等，则差值全为 0，按题意输出 0。
 *   实现: 构造差分数组 b[0]=0, b[i]=|a_{i−1}−a_i|；询问即求区间 b[l..r−1] 的 gcd。
 *   用线段树维护 gcd，单次查询 O(log n)，适配 n,q≤2e5。
 * 时间复杂度: 建树 O(n) + 每询问 O(log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b;
    b.reserve(n);
    b.emplace_back(0);
    for (auto &x: a) cin >> x;
    for (int i = 0; i < n - 1; ++i) {
        b.emplace_back(abs(a[i] - a[i + 1]));
    }
    seg::SegmentTree<int, [](int &a, int &b) { return gcd(a, b); }, [] { return 0; }> t(n);
    t.build(b);
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        cout << t.query(l, r - 1) << " ";
    }
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/8/14.
//
#include <bits/stdc++.h>

namespace seg {
    using std::vector;

    // 懒标记线段树（1-idx，闭区间 [l,r]）
    // 模板参数：S 节点值类型，F 懒标记类型
    // merge:   S(const S&, const S&)            —— 区间合并
    // E:       S()                               —— 节点幺元
    // mapping: S(const F&, const S&)             —— 标记作用到节点
    // composition: F(const F&, const F&)         —— 标记合成（先右后左）
    // ID:      F()                               —— 标记幺元
    template<typename S, typename F,
        auto merge, auto E, auto apply, auto mix, auto ID>
    struct LazySegmentTree {
        int n;
        vector<S> t;
        vector<F> lz;
        static inline const S e = E();
        static inline const F id = ID();

        LazySegmentTree(int n): n(n), t(4 * n + 5, e), lz(4 * n + 5, id) {
        }

        void build(const vector<S> &a) { build(1, 1, n, a); }
        void update(int pos, S v) { update(1, 1, n, pos, v); }
        S query(int l, int r) { return query(1, 1, n, l, r); }
        void rangeApply(int l, int r, F f) { rangeApply(1, 1, n, l, r, f); }

    private:
        void all_apply(int p, F f) {
            t[p] = apply(t[p], f);
            lz[p] = mix(lz[p], f); // 旧在前：等价于先旧后新
        }

        void down(int p) {
            all_apply(p << 1, lz[p]);
            all_apply(p << 1 | 1, lz[p]);
            lz[p] = id;
        }

        void build(int p, int l, int r, const vector<S> &a) {
            if (l == r) {
                t[p] = a[l];
                return;
            }
            int m = (l + r) >> 1;
            build(p << 1, l, m, a);
            build(p << 1 | 1, m + 1, r, a);
            t[p] = merge(t[p << 1], t[p << 1 | 1]);
        }

        void update(int p, int l, int r, int pos, S v) {
            if (l == r) {
                t[p] = v;
                return;
            }
            int m = (l + r) >> 1;
            down(p);
            if (pos <= m) update(p << 1, l, m, pos, v);
            else update(p << 1 | 1, m + 1, r, pos, v);
            t[p] = merge(t[p << 1], t[p << 1 | 1]);
        }

        S query(int p, int l, int r, int L, int R) {
            if (r < L || R < l) return e;
            if (L <= l && r <= R) return t[p];
            int m = (l + r) >> 1;
            down(p);
            S Ls = query(p << 1, l, m, L, R), Rs = query(p << 1 | 1, m + 1, r, L, R);
            return merge(Ls, Rs);
        }

        void rangeApply(int p, int l, int r, int L, int R, F f) {
            if (r < L || R < l) return;
            if (L <= l && r <= R) {
                all_apply(p, f);
                return;
            }
            int m = (l + r) >> 1;
            down(p);
            rangeApply(p << 1, l, m, L, R, f);
            rangeApply(p << 1 | 1, m + 1, r, L, R, f);
            t[p] = merge(t[p << 1], t[p << 1 | 1]);
        }
    };
}

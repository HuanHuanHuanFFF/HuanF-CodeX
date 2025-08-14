//
// Created by 幻 on 2025/8/14.
//
#include <bits/stdc++.h>

namespace seg {
    using std::vector;
    using std::function;

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
}

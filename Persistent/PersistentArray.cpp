//
// Created by 幻 on 2026/1/19.
//
#include <bits/stdc++.h>

namespace Persistent {
    using std::vector;

    // 1-idx 可持久化数组(主席树的最简特化)
    // 目标: 支持在历史版本上单点赋值, 并能在任意版本单点查询
    // 思路: 把下标当作二叉堆编号(根=1, 左=2x, 右=2x+1)
    //      每次 update 只复制 root->leaf 路径上的节点(O(log n)), 其它节点共享
    template<typename T>
    struct PersistentArray {
    private:
        struct Node {
            T val;            // 该节点(下标)存的值(仅叶子有意义, 这里直接把数组下标当节点)
            int left, right;  // 儿子下标(在节点池 tree 中的下标)

            Node(T val = T(), int left = 0, int right = 0)
                : val(val), left(left), right(right) {
            }
        };

        vector<int> roots_idx; // roots_idx[ver] = 第 ver 个版本的根节点下标
        vector<Node> tree;     // 节点池, 新版本通过 copy() 追加新节点

        // 初始建树: 按二叉堆编号把 vec[pos] 放进 tree[pos]
        // 注意: 这里只做点存储, 不维护区间信息, 适合点改点查
        void build(vector<T> &vec, int pos) {
            if (pos >= vec.size()) return;
            tree[pos].val = vec[pos];
            tree[pos].left = pos << 1;
            tree[pos].right = pos << 1 | 1;
            build(vec, pos << 1);
            build(vec, pos << 1 | 1);
        }

        // 复制一个节点并返回新节点下标
        // 持久化核心: update 时沿路径复制, 未经过的子树直接复用旧节点
        int copy(int idx) {
            tree.emplace_back(tree[idx].val, tree[idx].left, tree[idx].right);
            return (int)tree.size() - 1;
        }

    public:
        // max_size: 预留版本数(只 reserve roots, tree 由 build/update 动态增长)
        PersistentArray(int max_size) {
            roots_idx.reserve(max_size);
        }

        // 建立版本0: 输入数组 vec[1..n]
        void build(vector<T> &vec) {
            roots_idx.emplace_back(1);      // ver=0 的根固定从 1 开始
            tree.resize(vec.size() + 1);    // 让 tree[1..] 可写, reserve 不够用
            build(vec, 1);
        }

        // 单点赋值: 在 ver 版本基础上把位置 pos 改成 val, 生成新版本(追加到 roots_idx)
        // 走路规则: 把 pos 当二叉堆编号, 用 bit 还原从根到 pos 的左右选择
        // 复杂度: 新增节点 O(log pos), 时间 O(log pos)
        void update(int ver, int pos, T val) {
            int idx = copy(roots_idx[ver]); // 新版本根(复制旧根)
            roots_idx.emplace_back(idx);

            int path = 0, go = 0;
            // 由 pos 反推出路径(从叶到根), 再用 path 的 bit 正向走
            // 由于每轮会额外左移一次, 走的时候要先 path >>= 1 再判位
            while (pos > 1) {
                if (pos & 1) path |= 1; // 该层来自右儿子
                path <<= 1;
                pos >>= 1;
                ++go;
            }

            while (go--) {
                path >>= 1;
                if (path & 1) { // 走右
                    tree[idx].right = copy(tree[idx].right);
                    idx = tree[idx].right;
                } else {        // 走左
                    tree[idx].left = copy(tree[idx].left);
                    idx = tree[idx].left;
                }
            }
            tree[idx].val = val; // 到达叶子, 写入新值
        }

        // 单点查询: 查询 ver 版本的 pos 位置
        // 复杂度: O(log pos)
        T query(int ver, int pos) {
            int idx = roots_idx[ver];

            int path = 0, go = 0;
            while (pos > 1) {
                if (pos & 1) path |= 1;
                path <<= 1;
                pos >>= 1;
                ++go;
            }

            while (go--) {
                path >>= 1;
                if (path & 1) idx = tree[idx].right;
                else          idx = tree[idx].left;
            }
            return tree[idx].val;
        }
    };
}

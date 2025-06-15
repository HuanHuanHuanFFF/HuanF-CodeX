//
// Created by 幻 on 2025/6/15.
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

constexpr bool more = true;

struct BTire {
    static constexpr int B = 30; // 支持 int 范围（最高位）
    int N; // 节点总数上限

    struct node {
        array<int, 2> ch{-1, -1}; // 左右儿子编号
        int last = -1;
    };

    BTire(int n): N(n) {
        trie = vector<node>(n * (B + 1) + 5);
    }

    vector<node> trie;
    int idx = 1; // 下一个可分配节点编号，0 是根

    void insert(int x, int id) {
        int now = 0;
        trie[now].last = max(id, trie[now].last);
        for (int i = B; i >= 0; --i) {
            int b = x >> i & 1;
            if (trie[now].ch[b] == -1)
                trie[now].ch[b] = idx++;
            now = trie[now].ch[b];
            trie[now].last = max(id, trie[now].last);
        }
    }

    int find(int val, int k) {
        int ans = -1, now = 0;
        bool found = true;
        for (int i = B; i >= 0 && found; --i) {
            int xbit = val >> i & 1;
            int kbit = k >> i & 1;
            auto children = trie[now].ch;
            if (kbit) {
                if (children[xbit ^ 1] != -1) {
                    now = children[xbit ^ 1];
                } else found = false;
            } else {
                if (children[xbit ^ 1] != -1) {
                    ans = max(ans, trie[children[xbit ^ 1]].last);
                }
                if (children[xbit] != -1) {
                    now = children[xbit];
                } else found = false;
            }
        }
        if (found) ans = max(ans, trie[now].last);
        return ans;
    }
};

// Codeforces Round 1016 (Div. 3)
/* G-Shorten the Array
 * link: https://codeforces.com/contest/2093/problem/G
 * 标签: 01Trie, 位运算, 前缀枚举
 * 思路: 用01Trie在线插入前缀并在节点记录最大下标
 *      对于每个i在Trie中查询最靠后的j使a[i]^a[j]>=k
 *      更新最短子数组长度
 * 时间复杂度: O(n log A)  空间复杂度: O(n log A)
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    BTire tire(n);
    int ans = n + 1;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        tire.insert(x, i);
        int p = tire.find(x, k);
        if (p != -1)
            ans = min(ans, i - p + 1);
    }
    cout << (ans == n + 1 ? -1 : ans) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

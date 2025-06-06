//
// Created by 幻 on 2025/6/3.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

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

// Educational Codeforces Round 179 (Rated for Div. 2) 
/* 2111E-2111E
 * link: https://codeforces.com/problemset/problem/2111/E
 * 标签: 贪心, 字符串, set
 * 思路:
 *   1. 对每种可能的字符转换 x→y（x,y∈{a,b,c}）维护一个存储所有操作下标的有序集合 idx[x][y]。
 *   2. 从左到右遍历原字符串 s，对于每个字符 c：
 *      - 如果 c=='a'，跳过（无法变得更小）。
 *      - 如果 c=='b'：
 *         1) 尝试执行最早的 b→a 操作：若 idx[1][0] 非空，则删除最小下标并将 c 置为 'a'，直接结束当前字符处理。
 *         2) 否则尝试间接执行 b→c→a：
 *            - 取最早的 b→c 操作下标 id=*idx[1][2].begin()（若不存在，则跳过该路径）。
 *            - 在 idx[2][0] 中查找第一个大于 id 的 c→a 操作 p；若找到，则删除 p 和 id，并将 c 置为 'a'。
 *      - 如果 c=='c'：
 *         1) 尝试执行最早的 c→a 操作：若 idx[2][0] 非空，则删除最小下标并将 c 置为 'a'。
 *         2) 否则尝试执行 c→b→a：
 *            - 先查找最早的 c→b 操作 id=*idx[2][1].begin()；若不存在则跳过该路径。
 *            - 删除 id，将 c 置为 'b'。
 *            - 再在 idx[1][0] 中查找第一个下标大于 id 的 b→a 操作 p；若找到，则删除 p，并将 c 置为 'a'。
 *   3. 每次使用某个操作时，从对应集合中删除它，避免重复使用。
 *   4. 最终输出贪心处理后的 s，即为字典序最小结果。
 *
 * 时间复杂度: O((n+q) * log q)
 * 空间复杂度: O(q)
 */
void HuanF() {
    string s;
    int n, q;
    cin >> n >> q >> s;
    vector idx(3, vector<std::set<int> >(3));
    for (int i = 0; i < q; ++i) {
        char x, y;
        cin >> x >> y;
        idx[x - 'a'][y - 'a'].insert(i);
    }

    for (auto &c: s) {
        if (c == 'a') continue;
        if (c == 'b') {
            if (!idx[1][0].empty()) {
                idx[1][0].erase(idx[1][0].begin());
                c = 'a';
                continue;
            }
            if (!idx[1][2].empty()) {
                auto id = *idx[1][2].begin();
                auto p = idx[2][0].lower_bound(id);
                if (p != idx[2][0].end()) {
                    idx[2][0].erase(p);
                    idx[1][2].erase(id);
                    c = 'a';
                }
            }
        }
        if (c == 'c') {
            if (!idx[2][0].empty()) {
                idx[2][0].erase(idx[2][0].begin());
                c = 'a';
                continue;
            }
            if (!idx[2][1].empty()) {
                auto id = *idx[2][1].begin();
                idx[2][1].erase(id);
                c = 'b';
                auto p = idx[1][0].lower_bound(id);
                if (p != idx[1][0].end()) {
                    idx[1][0].erase(p);
                    c = 'a';
                }
            }
        }
    }
    cout << s << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

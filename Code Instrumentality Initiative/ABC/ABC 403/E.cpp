#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct Node {
    int next[26];
    bool f = false;
    vector<int> Zv;
    Node() { fill(begin(next), end(next), -1); }
};


/* ABC403 E - Forbidden Prefix
 * link: https://atcoder.jp/contests/abc403/tasks/abc403_e
 * 思路:
 *  使用 Trie 存储所有字符串节点，每个节点维护：
 *    - next[26]：子节点指针
 *    - f：该节点对应字符串是否已在 X 中插入
 *    - Zv：该节点上所有待激活的 Y 字符串 ID 列表
 *  插入到 X 时：
 *    - 在 Trie 中找到终点节点 v
 *    - 遍历 Zv[v]，对每个未标记为 bad 的 Y ID 标记为 bad 并累加 badY
 *    - 清空 Zv[v]，并置 f[v]=true
 *  插入到 Y 时：
 *    - 为该 Y 分配一个唯一 ID；totalY++
 *    - 遍历其路径节点 u：
 *        如果 f[u] 已为 true（存在 X 前缀），即时标记该 Y 为 bad 并 badY++，停止
 *        否则将该 Y ID 推入 Zv[u]
 *  每次输出 totalY - badY
 * 时间复杂度：O(∑|S_i|)，空间复杂度：O(∑|S_i|)
 */
//此为GPT的代码,HuanF未完全理解,但是已AC,作为样例参考
void HuanF() {
    int Q;
    cin >> Q;
    vector<Node> trie;
    trie.emplace_back(); // root

    ll totalY = 0, badY = 0;
    vector<bool> y_bad; // 标记每个 Y 是否已 bad
    y_bad.reserve(Q);

    int y_count = 0; // 给每个 Y 分配 ID

    for (int qi = 0; qi < Q; qi++) {
        int T;
        string S;
        cin >> T >> S;

        if (T == 1) {
            // 插入到 X
            int u = 0;
            for (char ch: S) {
                int c = ch - 'a';
                if (trie[u].next[c] == -1) {
                    trie[u].next[c] = trie.size();
                    trie.emplace_back();
                }
                u = trie[u].next[c];
            }
            // 激活此前缀下所有待激活的 Y
            for (int yid: trie[u].Zv) {
                if (!y_bad[yid]) {
                    y_bad[yid] = true;
                    badY++;
                }
            }
            trie[u].Zv.clear();
            trie[u].f = true;
        } else {
            // 插入到 Y
            totalY++;
            int yid = y_count++;
            y_bad.push_back(false);

            bool is_bad = false;
            int u = 0;
            for (char ch: S) {
                int c = ch - 'a';
                if (trie[u].next[c] == -1) {
                    trie[u].next[c] = trie.size();
                    trie.emplace_back();
                }
                u = trie[u].next[c];
                if (!is_bad && trie[u].f) {
                    // 遇到已有 X 前缀，立即标记
                    is_bad = true;
                    y_bad[yid] = true;
                    badY++;
                }
                if (!is_bad) {
                    trie[u].Zv.push_back(yid);
                }
            }
        }

        cout << (totalY - badY) << "\n";
    }
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

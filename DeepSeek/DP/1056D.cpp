#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* 1056D-Decorate Apple Tree
 * link: https://codeforces.com/problemset/problem/1056/D
 * 思路:
 * 1 进行一次从根节点 1 的 DFS, 计算每个节点子树中的叶子节点数 leaf[x]
 * 2 收集所有 leaf[1..n], 并升序排序
 * 3 对于每个 k(1..n), 排序后的第 k 小值即为使至少 k 个节点幸福所需的最少颜色数
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector children(n + 1, vector<int>());
    vector<int> leaf(n + 1);
    for (int i = 2, x; i <= n; ++i) {
        cin >> x;
        children[x].push_back(i);
    }
    auto dfs = [&](auto &&self, int x)-> int {
        if (children[x].empty()) return leaf[x] = 1;
        int res = 0;
        for (auto &y: children[x]) {
            res += self(self, y);
        }
        return leaf[x] = res;
    };
    dfs(dfs, 1);
    std::sort(leaf.begin() + 1, leaf.end());
    for (int i = 1; i <= n; ++i) {
        cout << leaf[i] << " ";
    }
}

signed main() {
    IOS();
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

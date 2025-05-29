//
// Created by 幻 on 25-5-29.
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
constexpr int N = 100 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Codeforces Round 288 (Div. 2) 
/* 508D-恢复密码
 * link: https://codeforces.com/contest/508/problem/D
 * 标签: 图论、欧拉路径、Hierholzer 算法
 * 思路:
 *   1. 构建 De Bruijn 图：将每个长度3子串 s 的前缀 s.substr(0,2) 作为 u，后缀 s.substr(1,2) 作为 v；记录有向边 u→v，并统计 in[v]、out[u]
 *   2. 判断欧拉路径条件：检查每个顶点的 out-in 差值 ∈ {-1,0,1}，并选出合适起点；使用DFS确认所有有边顶点在同一弱连通分量
 *   3. Hierholzer 算法构造欧拉路径：用栈模拟，从起点不断沿剩余出边前进，走不动时回退并记录顶点
 *   4. 还原密码：路径上的顶点序列 path，输出初始顶点的全部字符，再依次输出后续每个顶点的第二个字符
 * 时间复杂度: O(n log n)  // map/字符串操作导致对数因子
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    std::map<string, vector<string> > g;
    std::map<string, int> in, out;
    std::set<string> st;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        string x = s.substr(0, 2);
        string y = s.substr(1);
        st.insert(x);
        st.insert(y);
        g[x].push_back(y);
        ++in[y];
        ++out[x];
    }
    int cnto = 0, cnti = 0;
    auto start = *st.begin();
    for (auto &x: st) {
        if (in[x] != out[x]) {
            if (in[x] - out[x] == 1) {
                ++cnti;
            } else if (out[x] - in[x] == 1) {
                ++cnto;
                start = x;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    if (cnti > 1 && cnto > 1) {
        cout << "NO\n";
        return;
    }
    auto vis = st;
    auto check = [&](auto &&self, string x)-> void {
        vis.erase(x);
        for (auto &y: g[x]) {
            if (vis.contains(y))
                self(self, y);
        }
    };
    check(check, start);
    if (!vis.empty()) {
        cout << "NO\n";
        return;
    }
    vector<string> ans;
    ans.reserve(n + 2);
    auto dfs = [&](auto &&self, string x)-> void {
        while (g[x].size()) {
            auto y = g[x].back();
            g[x].pop_back();
            self(self, y);
        }
        ans.emplace_back(x);
    };
    dfs(dfs, start);
    std::ranges::reverse(ans);
    cout << "YES\n";
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i][1];
    }
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

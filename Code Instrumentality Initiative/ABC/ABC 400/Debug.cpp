#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> w;
vector<vector<int>> tr;
vector<char> dp_down, ans;

// 第一次 DFS：计算每个节点在“以自己为根”的子树内是否都合法
void dfs1(int u, int p) {
    dp_down[u] = 1;
    for (int v : tr[u]) if (v != p) {
        dfs1(v, u);
        dp_down[u] &= dp_down[v] && (2 * w[v] >= w[u]);
    }
}

// 第二次 DFS：传入 upOK = “去掉 u 子树后那部分是否都合法”
// 然后统计 ans[u]，并为每个孩子计算它的 upOK
void dfs2(int u, int p, char upOK) {
    // 收集子节点列表（不含父亲）
    vector<int> childs;
    for (int v : tr[u]) if (v != p)
        childs.push_back(v);

    // 1) 先判断 u 自己：上半部分 upOK & 所有子树的 dp_down & 权值关系
    char ok = upOK;
    for (int v : childs)
        ok &= dp_down[v] && (2 * w[v] >= w[u]);
    ans[u] = ok;

    // 2) 构造前后缀积：快速排除某个子树影响
    int k = (int)childs.size();
    vector<char> pref(k+1, 1), suf(k+1, 1);
    for (int i = 0; i < k; i++) {
        int v = childs[i];
        pref[i+1] = pref[i] & dp_down[v] & (2 * w[v] >= w[u]);
    }
    for (int i = k-1; i >= 0; i--) {
        int v = childs[i];
        suf[i] = suf[i+1] & dp_down[v] & (2 * w[v] >= w[u]);
    }

    // 3) 给每个孩子 v 计算 upOK_v，并递归
    for (int i = 0; i < k; i++) {
        int v = childs[i];
        // 去掉 v 子树后，上半部分要合法，需要 upOK & 左边所有孩子 & 右边所有孩子 & (w[u]*2>=w[v])
        char upChild = upOK & pref[i] & suf[i+1] & (2 * w[u] >= w[v]);
        dfs2(v, u, upChild);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        w.assign(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        tr.assign(n+1, {});
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        dp_down.assign(n+1, 0);
        ans.assign(n+1, 0);

        // 任选 1 号节点作为初始根
        dfs1(1, 0);
        dfs2(1, 0, 1);

        // 统计美丽节点数
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += ans[i];
        cout << res << "\n";
    }
    return 0;
}

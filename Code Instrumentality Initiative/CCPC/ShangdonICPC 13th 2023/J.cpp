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

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

struct DSU {
    vector<int> p;

    DSU(int n): p(vector<int>(n + 1)) {
        std::iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) p[x] = y;
    }
};

/* J. Not Another Path Query Problem
 * link: （第十三届山东省 ICPC 大学生程序设计竞赛 Problem J）
 * 思路（遵循奥卡姆剃刀＆模块化）:
 * 1. 价值≥V 的路径必须保留 V 二进制中所有 1 位——构造基础掩码 mask0=V
 * 2. 若要 >V，则在 V 的某一 0 位抬起为 1 即可——对每个 0 位构造一个掩码 mask_p
 * 3. 对每个掩码建立子图：仅保留 (w & mask)==mask 的边，用并查集合并端点
 * 4. 离线回答：若对任一掩码子图中 x,y 属于同一连通块，则存在合法路径
 *
 * 时间复杂度 O((m+q)·logV ·α(n))，空间 O(n·logV)
 */
void HuanF() {
    ll n, m, q, v;
    cin >> n >> m >> q >> v;
    vector<std::tuple<int, int, ll> > edges(m);
    for (auto &[x,y,w]: edges) {
        cin >> x >> y >> w;
    }
    vector<ll> masks{v};
    for (int bit = 0; bit < 60; ++bit) {
        if (!(v >> bit & 1))
            masks.push_back(v & -1LL << bit | 1LL << bit);
    }
    int k = masks.size();
    vector<DSU> dsus(k, DSU(n));
    for (int i = 0; i < k; ++i) {
        auto mask = masks[i];
        for (auto &[x,y,w]: edges)
            if ((w & mask) == mask)
                dsus[i].merge(x, y);
    }
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        bool ok = false;
        for (int j = 0; j < k; ++j) {
            if (dsus[j].find(x) == dsus[j].find(y))
                ok = true;
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;
using std::endl;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto AC() {
    //AC!
    //WA->AC
    //TLE/MLE->AC
}


/*
 * 我测,这么简单?2200+?
 * 一颗"星"型树,你不知道根节点和权值,但是可以通过两种操作猜出全部权值
 * type 1：路径和查询
 * 输入格式：? 1 k u1 u2 … uk
 * 返回值：f(u) = Σ_{节点 root→u 的整条路径} a[x]
 * type 2：节点取反
 * 输入格式：? 2 u
 * 操作：将节点 u 的权值 a[u] 在 {+1, -1} 之间翻转
 *
 * 那么可以自然想到两种情况
 * 当1不为根节点时,使1和根节点的和为0,然后询问直接记录
 * 当1为根节点时,得出1的值,依次询问算出每个值
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> val(n + 1);
    int root1, root2, rootV;
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
    }
    cout << "? 1 1 1" << endl;
    cin >> root1;
    cout << "? 2 1" << endl;
    cout << "? 1 1 1" << endl;
    cin >> root2;

    //1为根节点
    if (root2 == -root1) {
        val[1] = root2;
        for (int i = 2, ans; i <= n; ++i) {
            cout << "? 1 1 " << i << endl;
            cin >> ans;
            val[i] = ans - root2;
        }
    } else {
        //1不为根节点
        rootV = root1 + root2 >> 1;
        if (root2 != 0) {
            //强制让1和根节点的和为0
            cout << "? 2 1" << endl;
            root2 = 0;
        }
        val[1] = root2 - rootV;
        for (int i = 2; i <= n; ++i) {
            cout << "? 1 1 " << i << endl;
            cin >> val[i];
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << val[i] << " ";
    }
    cout << endl;
}

signed main() {
    IOS();
    AC();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

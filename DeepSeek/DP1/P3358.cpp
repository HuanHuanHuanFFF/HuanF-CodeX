#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

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

/*
 * https://www.luogu.com.cn/problem/P3558
 * 虽然原则上xi可以为任意值,但是1,0,-1对应3钟增加不变减少的状态
 * 比如50,-1,依然要往后加两次变为非递减,所以只需考虑1,0,-1的情况
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector f(n + 1, vector<int>(3, INF));
    for (int i = 1; i <= n; ++i) cin >> a[i];
    //初始状态为0
    f[1][a[1] + 1] = 0;
    for (int i = 2; i <= n; ++i) {
        //状态转移
        if (a[i] == -1) {
            f[i][0] = f[i - 1][0];
            // f[i][1] = f[i - 1][2] + 1;   前一位是1的话,这一位就不能为0
            f[i][2] = f[i - 1][2] + 2;
        } else if (a[i] == 0) {
            f[i][0] = f[i - 1][0] + 1;
            f[i][1] = std::min(f[i - 1][1], f[i - 1][0]); //上升且最小
            f[i][2] = f[i - 1][2] + 1;
        } else {
            f[i][0] = f[i - 1][0] + 2;
            f[i][1] = f[i - 1][0] + 1;
            f[i][2] = std::min(f[i - 1][0], std::min(f[i - 1][1], f[i - 1][2]));
            //上升且最小
        }
    }
    int ans = std::min(f[n][0], std::min(f[n][1], f[n][2]));
    if (ans >= INF) cout << "BRAK";
    else cout << ans;
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

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

auto AC() {
    //AC!
    //WA->AC
    //TLE/MLE->AC
}

/*------------------------------------------------------------
 *  ❶  每列翻转后可分为「上段-中段-下段」三块
 *      - 当 s[i] = '0'：上段 i-1 个 0，中段 1 个 1，下段 n-i 个 0
 *      - 当 s[i] = '1'：上段 i-1 个 1，中段 1 个 0，下段 n-i 个 1
 *      贡献只来自 0。
 *
 *  ❷  把整张图压缩成两条水平带：
 *      *top 带* ＝ 所有列的「上段」零块连通；
 *      *bot 带* ＝ 所有列的「下段」零块连通。
 *      若相邻两列对应带都为 0，它们自然连通。
 *
 *  ❸  令
 *        top[i] = 处理完第 i 列时，上带已连通的 0 数量
 *        bot[i] = 处理完第 i 列时，下带已连通的 0 数量
 *
 *      递推：
 *      • s[i] = '0'
 *          top[i] = top[i-1] + (i-1)        // 上段新加 (i-1) 个 0
 *          bot[i] = bot[i-1] + (n-i)        // 下段新加 (n-i) 个 0
 *      • s[i] = '1'
 *          top[i] = bot[i-1] + 1            // 中段那 1 个 0 把下带延续到上带
 *          bot[i] = bot[i-1]                // 本列下段都是 1
 *
 *  ❹  扫描同时更新答案 ans = max(top[i], bot[i])。
 *
 *  ❺  手写前几列即可观察到上述递推规律。关键点：
 *      - 为什么 top[i] = bot[i-1] + 1 当 s[i]='1'？
 *        因为此时唯一的 0 位于中间，它把「左列下带」延伸到新一列的上半区，
 *        于是新的上带就是旧的下带再多这 1 个 0。
 *----------------------------------------------------------*/
void HuanF() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> top(n + 1), bot(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '1') {
            // 当前列翻出的 0 在中间
            top[i] = bot[i - 1] + 1;
            bot[i] = bot[i - 1];
        } else {
            // 当前列上下都是 0
            top[i] = top[i - 1] + (i - 1);
            bot[i] = bot[i - 1] + (n - i);
        }
        ans = std::max(ans, std::max(top[i], bot[i]));
    }
    cout << ans << '\n';
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
